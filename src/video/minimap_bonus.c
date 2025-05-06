/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:51:01 by sithomas          #+#    #+#             */
/*   Updated: 2025/05/06 16:07:45 by sithomas         ###   ########.fr       */
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
	while (x_schema < ctx->map.height * ctx->map.x_r)
	{
		y_schema = 0;
		while (y_schema < ctx->map.width * ctx->map.y_r)
		{
			fill_mmap(ctx, x_schema, y_schema);
			y_schema += ctx->map.y_r;
		}
		x_schema += ctx->map.x_r;
	}
}

static void	fill_mmap(t_context *ctx, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < ctx->map.px)
	{
		j = 0;
		while (j < ctx->map.px)
		{
			if (x == (int)ctx->player.posx && y == (int)ctx->player.posy)
				render_map_pixel(&ctx->map, 0x00FFFFFF, ctx->map.px * x
					/ ctx->map.x_r + i, ctx->map.px * y / ctx->map.y_r + j);
			else if (ctx->map.map[x][y] == -2 || ctx->map.map[x][y] == 6)
				render_map_pixel(&ctx->map, 0x00F1C40F, ctx->map.px * x
					/ ctx->map.x_r + i, ctx->map.px * y / ctx->map.y_r + j);
			else if (ctx->map.map[x][y] == -1 || ctx->map.map[x][y] == 1)
				render_map_pixel(&ctx->map, 0x00566573, ctx->map.px * x
					/ ctx->map.x_r + i, ctx->map.px * y / ctx->map.y_r + j);
			else if (ctx->map.map[x][y] == 0 || ctx->map.map[x][y] > 1)
				render_map_pixel(&ctx->map, 0x009c640c, ctx->map.px * x
					/ ctx->map.x_r + i, ctx->map.px * y / ctx->map.y_r + j);
			j++;
		}
		i++;
	}
}

static void	render_map_pixel(t_map *map, int color, int y, int x)
{
	if (x <= map->width * map->px && y <= map->height * map->px)
		map->mmap_img[x + y * map->width * map->px] = color;
}
