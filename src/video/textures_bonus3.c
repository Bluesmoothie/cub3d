/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:47:16 by ygille            #+#    #+#             */
/*   Updated: 2025/05/06 16:06:29 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	ctx->map.mmap = mlx_new_image(ctx->mlx.id,
			ctx->map.width * ctx->map.px,
			ctx->map.height * ctx->map.px);
	verif(ctx, ctx->map.mmap, "mmap");
	ctx->map.mmap_img = (int *)mlx_get_data_addr(ctx->map.mmap, &ctx->map.bpp,
			&ctx->map.line_size, &ctx->map.endian);
	if (!ctx->map.mmap)
		error(EMGETDATA, "mmap");
}

void	deinit_mmap(t_context *ctx)
{
	if (ctx->map.mmap_img)
		mlx_destroy_image(ctx->mlx.id, ctx->map.mmap);
}
