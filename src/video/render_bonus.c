/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:39:35 by ygille            #+#    #+#             */
/*   Updated: 2025/05/06 15:56:44 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_frame(t_context *ctx);
static void	render_bg(t_context *ctx);

/*
**	Treat inputs and calculate the next frame
*/
int	renderer(t_context *ctx)
{
	static size_t	timer = 0;

	if (!timer)
	{
		ctx->ceiling[0] = get_bgcolor(ctx->ceiling);
		ctx->floor[0] = get_bgcolor(ctx->floor);
	}
	if (1)
	{
		ctx->frame++;
		player_moves(ctx);
		camera_moves(ctx);
		if (ctx->kin.door)
			interact_door(ctx);
		ctx->kin.door = false;
		render_map(ctx);
		render_frame(ctx);
		mlx_put_image_to_window(ctx->mlx.id, ctx->mlx.win, ctx->mlx.img, 0, 0);
		mlx_put_image_to_window(ctx->mlx.id, ctx->mlx.win, ctx->map.mmap, 0, 0);
	}
	return (timer++);
}

void	render_pixel(int *frame, int color, int x, int y)
{
	if (x <= WWIDTH && y <= WHEIGHT)
		frame[x + y * WWIDTH] = color;
}

/*
**	Print texture using raycasting result to resize and choose the good
**	texture depending on the orientation
*/
void	render_texture(t_context *ctx, t_raycast rc, int screenx)
{
	t_rendering	render;
	const int	ymem = rc.sy;
	int			*txt;

	render = calc_render_params(&ctx->txt_infos, &ctx->player, &rc);
	if (ctx->map.map[rc.mapx][rc.mapy] == T_CLOSEDOOR)
		return (render_door(ctx, rc, screenx, render));
	txt = get_dir(&rc, &ctx->txt);
	while (rc.sy <= rc.ey)
	{
		render_pixel(ctx->mlx.img_data,
			txt[render.txtx + (int)render.txty * ctx->txt_infos.width],
			screenx, rc.sy);
		render.txty += render.txtstep;
		if ((int)render.txty >= ctx->txt_infos.height)
			render.txty = (double)(ctx->txt_infos.height - 1);
		rc.sy++;
	}
	if (txt == ctx->txt.ea)
	{
		rc.sy = ymem;
		render_fire(ctx, rc, screenx);
	}
}

static void	render_frame(t_context *ctx)
{
	render_bg(ctx);
	ray_cast(ctx);
}

static void	render_bg(t_context *ctx)
{
	int	x;
	int	y;

	y = 0;
	while (y < WHEIGHT / 2)
	{
		x = 0;
		while (x < WWIDTH)
		{
			render_pixel(ctx->mlx.img_data, ctx->ceiling[0], x, y);
			x++;
		}
		y++;
	}
	while (y < WHEIGHT)
	{
		x = 0;
		while (x < WWIDTH)
		{
			render_pixel(ctx->mlx.img_data, ctx->floor[0], x, y);
			x++;
		}
		y++;
	}
}
