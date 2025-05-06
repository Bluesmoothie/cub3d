/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:11:27 by ygille            #+#    #+#             */
/*   Updated: 2025/05/06 17:52:30 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_raycast	init_rc(t_player *player, int x);
static void			get_ray_dir(t_player *player, t_raycast *rc);
static void			ray_step(t_raycast *rc);
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
		rc = init_rc(&ctx->player, x);
		get_ray_dir(&ctx->player, &rc);
		while (!(out_of_map(&ctx->map, rc.mapx, rc.mapy)
				|| ctx->map.map[rc.mapx][rc.mapy] > 0))
			ray_step(&rc);
		if (!out_of_map(&ctx->map, rc.mapx, rc.mapy))
		{
			dist_size(&rc);
			render_texture(ctx, rc, x);
		}
		x++;
	}
}

/*
**	Initialize values for raycasting compute
*/
static t_raycast	init_rc(t_player *player, int x)
{
	t_raycast	rc;

	rc.mapx = player->posx;
	rc.mapy = player->posy;
	rc.cam_angle = 2 * x / (double)WWIDTH - 1;
	rc.rayx = player->viewx + player->viewy * rc.cam_angle;
	rc.rayy = player->viewy - player->viewx * rc.cam_angle;
	rc.raystepx = fabs(1 / rc.rayx);
	rc.raystepy = fabs(1 / rc.rayy);
	rc.side = SIDE_NS;
	return (rc);
}

static void	get_ray_dir(t_player *player, t_raycast *rc)
{
	if (rc->rayx < 0)
	{
		rc->stepx = -1;
		rc->nextsidex = -(int)player->posx + player->posx ;
	}
	else
	{
		rc->stepx = 1;
		rc->nextsidex = (int)player->posx - player->posx + 1;
	}
	if (rc->rayy < 0)
	{
		rc->stepy = -1;
		rc->nextsidey = -(int)player->posy + player->posy ;
	}
	else
	{
		rc->stepy = 1;
		rc->nextsidey = (int)player->posy - player->posy + 1;
	}
	rc->nextsidex *= rc->raystepx;
	rc->nextsidey *= rc->raystepy;
}

static void	ray_step(t_raycast *rc)
{
	if (rc->nextsidex < rc->nextsidey)
	{
		rc->mapx += rc->stepx;
		rc->nextsidex += rc->raystepx;
		rc->side = SIDE_NS;
	}
	else
	{
		rc->mapy += rc->stepy;
		rc->nextsidey += rc->raystepy;
		rc->side = SIDE_EW;
	}
}

static void	dist_size(t_raycast *rc)
{
	if (rc->side == SIDE_NS)
		rc->walldist = (rc->nextsidex - rc->raystepx);
	else
		rc->walldist = (rc->nextsidey - rc->raystepy);
	rc->halfheight = WHEIGHT / rc->walldist / 2;
	rc->sy = HWHEIGHT - rc->halfheight;
	rc->ey = HWHEIGHT + rc->halfheight;
	if (rc->sy < 0)
		rc->sy = 0;
	if (rc->ey >= WHEIGHT)
		rc->ey = WHEIGHT - 1;
}
