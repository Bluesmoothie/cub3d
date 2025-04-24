/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:11:27 by ygille            #+#    #+#             */
/*   Updated: 2025/04/24 14:56:30 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_raycast	update_rc(t_player *player, int x);
static void			get_ray_dir(t_player *player, t_raycast *rc);
static void			found_collision(t_map *map, t_raycast *rc);

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
			rc.walldist = (rc.sidedistX - rc.deltadistX);
		else 
			rc.walldist = (rc.sidedistY - rc.deltadistY);
		rc.lineheight = (int)(WHEIGHT / rc.walldist);
		rc.sy = -rc.lineheight / 2 + WHEIGHT / 2;
		if (rc.sy < 0)
			rc.sy = 0;
		rc.ey = rc.lineheight / 2 + WHEIGHT / 2;
		if (rc.ey >= WHEIGHT)
			rc.ey = WHEIGHT - 1;
		for (int y = 0; y < WHEIGHT; y++)
			if (y >= rc.sy && y <= rc.ey)
				render_pixel(ctx->mlx.img_data, 0x00FFFFFF, x, y);
	x++;	
	}
}

static t_raycast	update_rc(t_player *player, int x)
{
	t_raycast	rc;

	rc.cameraX = 2 * x / (double)WWIDTH - 1;
	rc.raydirX = player->dirx + player->diry * rc.cameraX;
	rc.raydirY = player->diry - player->dirx * rc.cameraX;
	rc.deltadistX = fabs(1 / rc.raydirX);
	rc.deltadistY = fabs(1 / rc.raydirY);
	rc.mapX = (int)player->posx;
	rc.mapY = (int)player->posy;
	return (rc);
}

static void	get_ray_dir(t_player *player, t_raycast *rc)
{
	if (rc->raydirX < 0)
	{
		rc->stepX = -1;
		rc->sidedistX = (player->posx - rc->mapX) * rc->deltadistX;
	}
	else
	{
		rc->stepX = 1;
		rc->sidedistX = (rc->mapX + 1.0 - player->posx) * rc->deltadistX;
	}
	if (rc->raydirY < 0)
	{
		rc->stepY = -1;
		rc->sidedistY = (player->posy - rc->mapY) * rc->deltadistY;
	}
	else
	{
		rc->stepY = 1;
		rc->sidedistY = (rc->mapY + 1.0 - player->posy) * rc->deltadistY;
	}
}

static void	found_collision(t_map *map, t_raycast *rc)
{
	while (1)
	{
		if (rc->sidedistX < rc->sidedistY)
		{
			rc->sidedistX += rc->deltadistX;
			rc->mapX += rc->stepX;
			rc->side = false;
		}
		else
		{
			rc->sidedistY += rc->deltadistY;
			rc->mapY += rc->stepY;
			rc->side = true;
		}
		if (map->map[rc->mapX][rc->mapY] == 1)
			break ;
	}
}
