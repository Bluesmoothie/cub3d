/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:11:27 by ygille            #+#    #+#             */
/*   Updated: 2025/05/06 15:02:51 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_raycast	update_rc(t_player *player, int x);
static void			get_ray_dir(t_player *player, t_raycast *rc);
static void			found_collision(t_map *map, t_raycast *rc);
static void			dist_size(t_raycast *rc);

/*
**	That's where the magic is
**	Launch a ray for each column of pixel on the window
**	Find the nearest collision and calculate the distance
**	to calculate the size of the resulting texture
*/
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
		dist_size(&rc);
		if (!out_of_map(&ctx->map, rc.mapx, rc.mapy))
			render_texture(ctx, rc, x);
		x++;
	}
}

/*
**	Initialize values for raycasting compute
*/
static t_raycast	update_rc(t_player *player, int x)
{
	t_raycast	rc;

	rc.cam_angle = 2 * x / (double)WWIDTH - 1;
	rc.rayx = player->viewx + player->viewy * rc.cam_angle;
	rc.rayy = player->viewy - player->viewx * rc.cam_angle;
	rc.raystepx = fabs(1 / rc.rayx);
	rc.raystepy = fabs(1 / rc.rayy);
	rc.mapx = (int)player->posx;
	rc.mapy = (int)player->posy;
	return (rc);
}

static void	get_ray_dir(t_player *player, t_raycast *rc)
{
	if (rc->rayx < 0)
	{
		rc->stepx = -1;
		rc->nextsidex = (player->posx - rc->mapx) * rc->raystepx;
	}
	else
	{
		rc->stepx = 1;
		rc->nextsidex = (rc->mapx + 1.0 - player->posx) * rc->raystepx;
	}
	if (rc->rayy < 0)
	{
		rc->stepy = -1;
		rc->nextsidey = (player->posy - rc->mapy) * rc->raystepy;
	}
	else
	{
		rc->stepy = 1;
		rc->nextsidey = (rc->mapy + 1.0 - player->posy) * rc->raystepy;
	}
}

static void	found_collision(t_map *map, t_raycast *rc)
{
	while (1)
	{
		if (rc->nextsidex < rc->nextsidey)
		{
			rc->nextsidex += rc->raystepx;
			rc->mapx += rc->stepx;
			rc->side = SIDE_NS;
		}
		else
		{
			rc->nextsidey += rc->raystepy;
			rc->mapy += rc->stepy;
			rc->side = SIDE_EW;
		}
		if (out_of_map(map, rc->mapx, rc->mapy)
			|| map->map[rc->mapx][rc->mapy] > 0)
			break ;
	}
}

static void	dist_size(t_raycast *rc)
{
	if (rc->side == SIDE_NS)
		rc->walldist = (rc->nextsidex - rc->raystepx);
	else
		rc->walldist = (rc->nextsidey - rc->raystepy);
	rc->lineheight = WHEIGHT / rc->walldist;
	rc->sy = -rc->lineheight / 2 + WHEIGHT / 2;
	if (rc->sy < 0)
		rc->sy = 0;
	rc->ey = rc->lineheight / 2 + WHEIGHT / 2;
	if (rc->ey >= WHEIGHT)
		rc->ey = WHEIGHT - 1;
}
