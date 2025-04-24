/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:11:27 by ygille            #+#    #+#             */
/*   Updated: 2025/04/24 17:14:33 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_raycast	update_rc(t_player *player, int x);
static void			get_ray_dir(t_player *player, t_raycast *rc);
static void			found_collision(t_map *map, t_raycast *rc);
static bool			out_of_map(t_map *map, int x, int y);

void	ray_cast(t_context *ctx)
{
	t_raycast	rc;
	int			x;

	x = 0;
	while (x < WWIDTH)
	{
		rc = update_rc(&ctx->player, x);
		get_ray_dir(&ctx->player, &rc);
		found_collision(&ctx->map, &rc);
		if (!rc.side)
			rc.walldist = (rc.sidedistx - rc.deltadistx);
		else 
			rc.walldist = (rc.sidedisty - rc.deltadisty);
		rc.lineheight = (int)(WHEIGHT / rc.walldist);
		rc.sy = -rc.lineheight / 2 + WHEIGHT / 2;
		if (rc.sy < 0)
			rc.sy = 0;
		rc.ey = rc.lineheight / 2 + WHEIGHT / 2;
		if (rc.ey >= WHEIGHT)
			rc.ey = WHEIGHT - 1;
		if (!out_of_map(&ctx->map, rc.mapx, rc.mapy))
			render_texture(ctx, rc, x);
	x++;	
	}
}

static t_raycast	update_rc(t_player *player, int x)
{
	t_raycast	rc;

	rc.camerax = 2 * x / (double)WWIDTH - 1;
	rc.raydirx = player->dirx + player->diry * rc.camerax;
	rc.raydiry = player->diry - player->dirx * rc.camerax;
	rc.deltadistx = fabs(1 / rc.raydirx);
	rc.deltadisty = fabs(1 / rc.raydiry);
	rc.mapx = (int)player->posx;
	rc.mapy = (int)player->posy;
	return (rc);
}

static void	get_ray_dir(t_player *player, t_raycast *rc)
{
	if (rc->raydirx < 0)
	{
		rc->stepx = -1;
		rc->sidedistx = (player->posx - rc->mapx) * rc->deltadistx;
	}
	else
	{
		rc->stepx = 1;
		rc->sidedistx = (rc->mapx + 1.0 - player->posx) * rc->deltadistx;
	}
	if (rc->raydiry < 0)
	{
		rc->stepy = -1;
		rc->sidedisty = (player->posy - rc->mapy) * rc->deltadisty;
	}
	else
	{
		rc->stepy = 1;
		rc->sidedisty = (rc->mapy + 1.0 - player->posy) * rc->deltadisty;
	}
}

static void	found_collision(t_map *map, t_raycast *rc)
{
	while (1)
	{
		if (rc->sidedistx < rc->sidedisty)
		{
			rc->sidedistx += rc->deltadistx;
			rc->mapx += rc->stepx;
			rc->side = false;
		}
		else
		{
			rc->sidedisty += rc->deltadisty;
			rc->mapy += rc->stepy;
			rc->side = true;
		}
		if (out_of_map(map, rc->mapx, rc->mapy) || map->map[rc->mapx][rc->mapy] == 1)
			break ;
	}
}

static bool	out_of_map(t_map *map, int x, int y)
{
	return (x >= map->height || y >= map->width || x < 0 || y < 0);
}
