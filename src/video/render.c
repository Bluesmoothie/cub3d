/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:39:35 by ygille            #+#    #+#             */
/*   Updated: 2025/04/23 18:51:13 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_frame(t_context *ctx);
static void	render_bg(t_context *ctx);

int	renderer(t_context *ctx)
{
	static size_t	timer = 0;
	static size_t	frame = 0;

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

static void	render_frame(t_context *ctx)
{
	render_bg(ctx);
	render_test(ctx);
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
			render_pixel(ctx->mlx.img_data, get_bgcolor(ctx->ceiling), x, y);
			x++;
		}
		y++;
	}
	while (y < WHEIGHT)
	{
		x = 0;
		while (x < WWIDTH)
		{
			render_pixel(ctx->mlx.img_data, get_bgcolor(ctx->floor), x, y);
			x++;
		}
		y++;
	}
}
