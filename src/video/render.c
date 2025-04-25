/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:39:35 by ygille            #+#    #+#             */
/*   Updated: 2025/04/25 11:37:31 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_frame(t_context *ctx);
static void	render_bg(t_context *ctx);

int	renderer(t_context *ctx)
{
	static size_t	timer = 0;
	static size_t	frame = 0;

	if (!timer)
	{
		ctx->ceiling[0] = get_bgcolor(ctx->ceiling);
		ctx->floor[0] = get_bgcolor(ctx->floor);
	}
	if (!(timer % 200))
	{
		frame++;
		player_moves(ctx);
		camera_moves(ctx);
		render_frame(ctx);
		mlx_put_image_to_window(ctx->mlx.id, ctx->mlx.win, ctx->mlx.img, 0, 0);
	}
	return (timer++);
}

void	render_pixel(int *frame, int color, int x, int y)
{
	if (x <= WWIDTH && y <= WHEIGHT)
		frame[x + y * WWIDTH] = color;
}

void	render_texture(t_context *ctx, t_raycast rc, int screenx)
{
	t_rendering	render;
	int			*txt;

	render.txtstep = 1.0 * ctx->txt_infos.height / rc.lineheight;
	render.txty = (rc.sy - WHEIGHT / 2 + rc.lineheight / 2) * render.txtstep;
	render.y = rc.sy;
	render.txtx = calc_txtx(&rc, &ctx->txt_infos, &ctx->player);
	txt = get_dir(&rc, &ctx->txt);
	while (render.y <= rc.ey)
	{
		render_pixel(ctx->mlx.img_data, txt[render.txtx + (int)render.txty * ctx->txt_infos.width], screenx, render.y);
		render.txty += render.txtstep;
		if ((int)render.txty >= ctx->txt_infos.height)
			render.txty = (double)(ctx->txt_infos.height - 1);
		render.y++;
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
