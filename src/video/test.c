/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:09:03 by ygille            #+#    #+#             */
/*   Updated: 2025/04/24 13:21:18 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void cast_ray(t_context *ctx) ;

void	render_test(t_context *ctx)
{
	cast_ray(ctx);
}

void	cast_ray(t_context *ctx)
{
	for (int x = 0; x < WWIDTH; x++)
	{
		double cameraX = 2 * x / (double)WWIDTH - 1;
		double rayDirX = ctx->player.dirx + ctx->player.diry * cameraX;
		double rayDirY = ctx->player.diry - ctx->player.dirx * cameraX;
		int mapX = (int)ctx->player.posx;
		int mapY = (int)ctx->player.posy;
		double sideDistX;
		double sideDistY;
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		int stepX;
		int stepY;
		int hit = 0;
		int side;
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (ctx->player.posx - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - ctx->player.posx) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (ctx->player.posy - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - ctx->player.posy) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (ctx->map.map[mapX][mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else 
			perpWallDist = (sideDistY - deltaDistY);
		int lineHeight = (int)(WHEIGHT / perpWallDist);
		int drawStart = -lineHeight / 2 + WHEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WHEIGHT / 2;
		if (drawEnd >= WHEIGHT)
			drawEnd = WHEIGHT - 1;
		for (int y = 0; y < WHEIGHT; y++)
			if (y >= drawStart && y <= drawEnd)
				render_pixel(ctx->mlx.img_data, 0x00FFFFFF, x, y);
		}
}
