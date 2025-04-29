/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:47:16 by ygille            #+#    #+#             */
/*   Updated: 2025/04/29 12:12:42 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	verif(t_context *ctx, void *loaded, void *path);

void	deinit_fire(t_context *ctx)
{
	if (ctx->fire.f1)
		mlx_destroy_image(ctx->mlx.id, ctx->fire.f1);
	if (ctx->fire.f2)
		mlx_destroy_image(ctx->mlx.id, ctx->fire.f2);
	if (ctx->fire.f3)
		mlx_destroy_image(ctx->mlx.id, ctx->fire.f3);
	if (ctx->fire.f4)
		mlx_destroy_image(ctx->mlx.id, ctx->fire.f4);
	if (ctx->fire.f5)
		mlx_destroy_image(ctx->mlx.id, ctx->fire.f5);
	if (ctx->fire.f6)
		mlx_destroy_image(ctx->mlx.id, ctx->fire.f6);
	if (ctx->fire.f7)
		mlx_destroy_image(ctx->mlx.id, ctx->fire.f7);
	if (ctx->fire.f8)
		mlx_destroy_image(ctx->mlx.id, ctx->fire.f8);
}

void	init_mmap(t_context *ctx)
{
	ctx->map.mmap = mlx_new_image(ctx->mlx.id, ctx->map.width * PIXELMAP, ctx->map.height * PIXELMAP);
	verif(ctx, ctx->map.mmap, "mmap");
	ctx->map.mmap_img = (int *)mlx_get_data_addr(ctx->map.mmap, &ctx->map.bpp, &ctx->map.line_size,&ctx->map.endian);
	if (!ctx->map.mmap)
		error("Mlx get data addr failed on", "mmap");
}

void	deinit_mmap(t_context *ctx)
{
	if (ctx->map.mmap_img)
		mlx_destroy_image(ctx->mlx.id, ctx->map.mmap);
}

/*
**	Verify if a texture loaded successfully
*/
static void	verif(t_context *ctx, void *loaded, void *path)
{
	static int	width = 0;
	static int	height = 0;

	if (loaded == NULL)
		error("Failed to load", path);
	if (!width)
	{
		width = ctx->txt_infos.width;
		height = ctx->txt_infos.height;
	}
	else if (width != ctx->txt_infos.width || height != ctx->txt_infos.height)
		error("All textures must be the same size", path);
}
