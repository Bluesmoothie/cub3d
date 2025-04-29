/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:51:01 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/29 11:41:10 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_mmap(t_context *ctx, int x_schema, int y_schema);
void		render_map(t_context *ctx);

void	render_map(t_context *ctx)
{
	int	x_schema;
	int	y_schema;

	x_schema = 0;
	y_schema = 0;
	while (x_schema < ctx->map.height)
	{
		while (y_schema < ctx->map.width)
		{
			fill_mmap(ctx, PIXELMAP * x_schema, PIXELMAP * y_schema);
			y_schema++;
		}
		x_schema++;
	}
}

static void	fill_mmap(t_context *ctx, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < PIXELMAP)
	{
		j = 0;
		while (j < PIXELMAP)
		{
			if (ctx->map.map[x][y] < 0 || ctx->map.map[x][y] == 1)
				ctx->map.mmap_img[x + i + y + j] = 0xFFFFFF;
			else if (ctx->map.map[x][y] == 0 || ctx->map.map[x][y] > 1)
				ctx->map.mmap_img[x + i + y + j] = 0x000000;
			if ((int)(10 * (ctx->player.posx)) > ((x + i) * 10 - 2) && (int)(10
					* (ctx->player.posx)) < ((x + i) * 10 + 2) && (int)(10
					* (ctx->player.posy)) < ((y + j) * 10 + 2) && (int)(10
					* (ctx->player.posy)) > ((y + j) * 10 - 2))
				ctx->map.mmap_img[x + i + y + j] = 0x00FF00;
			j++;
		}
		i++;
	}
}
