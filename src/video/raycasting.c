/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:11:27 by ygille            #+#    #+#             */
/*   Updated: 2025/04/24 13:56:14 by ygille           ###   ########.fr       */
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
			rc.perpWallDist = (rc.sideDistX - rc.deltaDistX);
		else 
			rc.perpWallDist = (rc.sideDistY - rc.deltaDistY);
		int lineHeight = (int)(WHEIGHT / rc.perpWallDist);
		int drawStart = -lineHeight / 2 + WHEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WHEIGHT / 2;
		if (drawEnd >= WHEIGHT)
			drawEnd = WHEIGHT - 1;
		for (int y = 0; y < WHEIGHT; y++)
			if (y >= drawStart && y <= drawEnd)
				render_pixel(ctx->mlx.img_data, 0x00FFFFFF, x, y);
	x++;	
	}
}

static t_raycast	update_rc(t_player *player, int x)
{
	t_raycast	rc;

	rc.cameraX = 2 * x / (double)WWIDTH - 1;
	rc.rayDirX = player->dirx + player->diry * rc.cameraX;
	rc.rayDirY = player->diry - player->dirx * rc.cameraX;
	rc.deltaDistX = fabs(1 / rc.rayDirX);
	rc.deltaDistY = fabs(1 / rc.rayDirY);
	rc.mapX = (int)player->posx;
	rc.mapY = (int)player->posy;
	return (rc);
}

static void	get_ray_dir(t_player *player, t_raycast *rc)
{
	if (rc->rayDirX < 0)
	{
		rc->stepX = -1;
		rc->sideDistX = (player->posx - rc->mapX) * rc->deltaDistX;
	}
	else
	{
		rc->stepX = 1;
		rc->sideDistX = (rc->mapX + 1.0 - player->posx) * rc->deltaDistX;
	}
	if (rc->rayDirY < 0)
	{
		rc->stepY = -1;
		rc->sideDistY = (player->posy - rc->mapY) * rc->deltaDistY;
	}
	else
	{
		rc->stepY = 1;
		rc->sideDistY = (rc->mapY + 1.0 - player->posy) * rc->deltaDistY;
	}
}

static void	found_collision(t_map *map, t_raycast *rc)
{
	while (1)
	{
		if (rc->sideDistX < rc->sideDistY)
		{
			rc->sideDistX += rc->deltaDistX;
			rc->mapX += rc->stepX;
			rc->side = false;
		}
		else
		{
			rc->sideDistY += rc->deltaDistY;
			rc->mapY += rc->stepY;
			rc->side = true;
		}
		if (map->map[rc->mapY][rc->mapX] > 0)
			break ;
	}
}
