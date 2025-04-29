/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:51:01 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/29 14:06:49 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_mmap(t_context *ctx, int x_schema, int y_schema);
static void	render_map_pixel(t_map *map, int color, int x, int y);

void	render_map(t_context *ctx)
{
	int	x_schema;
	int	y_schema;

	x_schema = 0;
	while (x_schema < ctx->map.height)
	{
		y_schema = 0;
		while (y_schema < ctx->map.width)
		{
			fill_mmap(ctx, x_schema, y_schema);
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
			if (x == (int)ctx->player.posx && y == (int)ctx->player.posy)
				render_map_pixel(&ctx->map, 0x00FFFFFF, PIXELMAP * x + i,
					PIXELMAP * y + j);
			else if (ctx->map.map[x][y] < 0 || ctx->map.map[x][y] == 1)
				render_map_pixel(&ctx->map, 0x00566573, PIXELMAP * x + i,
					PIXELMAP * y + j);
			else if (ctx->map.map[x][y] == 0 || ctx->map.map[x][y] > 1)
				render_map_pixel(&ctx->map, 0x009c640c, PIXELMAP * x + i,
					PIXELMAP * y + j);
			j++;
		}
		i++;
	}
}

static void	render_map_pixel(t_map *map, int color, int y, int x)
{
	if (x <= map->width * PIXELMAP && y <= map->height * PIXELMAP)
		map->mmap_img[x + y * map->width * PIXELMAP] = color;
}
