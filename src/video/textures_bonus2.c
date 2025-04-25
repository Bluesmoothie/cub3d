/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:18:36 by ygille            #+#    #+#             */
/*   Updated: 2025/04/25 15:49:40 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_xpm(t_context *ctx);
static void	get_addr(t_context *ctx);
static void	get_addr2(t_context *ctx);
static void	verif(t_context *ctx, void *loaded, void *path);

void	init_fire(t_context *ctx)
{
	load_xpm(ctx);
	get_addr(ctx);
}

static void	load_xpm(t_context *ctx)
{
	ctx->fire.f1 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f1_bonus.xpm",
			&ctx->fire.width, &ctx->fire.height);
	verif(ctx, ctx->fire.f1, "assets/f1_bonus.xpm");
	ctx->fire.f2 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f2_bonus.xpm",
			&ctx->fire.width, &ctx->fire.height);
	verif(ctx, ctx->fire.f2, "assets/f2_bonus.xpm");
	ctx->fire.f3 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f3_bonus.xpm",
			&ctx->fire.width, &ctx->fire.height);
	verif(ctx, ctx->fire.f3, "assets/f3_bonus.xpm");
	ctx->fire.f4 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f4_bonus.xpm",
			&ctx->fire.width, &ctx->fire.height);
	verif(ctx, ctx->fire.f4, "assets/f4_bonus.xpm");
	ctx->fire.f5 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f5_bonus.xpm",
			&ctx->fire.width, &ctx->fire.height);
	verif(ctx, ctx->fire.f5, "assets/f5_bonus.xpm");
	ctx->fire.f6 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f6_bonus.xpm",
			&ctx->fire.width, &ctx->fire.height);
	verif(ctx, ctx->fire.f6, "assets/f6_bonus.xpm");
	ctx->fire.f7 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f7_bonus.xpm",
			&ctx->fire.width, &ctx->fire.height);
	verif(ctx, ctx->fire.f7, "assets/f7_bonus.xpm");
	ctx->fire.f8 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f8_bonus.xpm",
			&ctx->fire.width, &ctx->fire.height);
	verif(ctx, ctx->fire.f8, "assets/f8_bonus.xpm");
}

static void	get_addr(t_context *ctx)
{
	ctx->fire.f1_img = (int *)mlx_get_data_addr(ctx->fire.f1, &ctx->fire.bpp,
			&ctx->fire.line_size, &ctx->fire.endian);
	if (!ctx->fire.f1_img)
		error("Mlx get data addr failed on", "f1_bonus");
	ctx->fire.f2_img = (int *)mlx_get_data_addr(ctx->fire.f2, &ctx->fire.bpp,
			&ctx->fire.line_size, &ctx->fire.endian);
	if (!ctx->fire.f2_img)
		error("Mlx get data addr failed on", "f2_bonus");
	ctx->fire.f3_img = (int *)mlx_get_data_addr(ctx->fire.f3, &ctx->fire.bpp,
			&ctx->fire.line_size, &ctx->fire.endian);
	if (!ctx->fire.f3_img)
		error("Mlx get data addr failed on", "f3_bonus");
	ctx->fire.f4_img = (int *)mlx_get_data_addr(ctx->fire.f4, &ctx->fire.bpp,
			&ctx->fire.line_size, &ctx->fire.endian);
	if (!ctx->fire.f4_img)
		error("Mlx get data addr failed on", "f4_bonus");
	get_addr2(ctx);
}

static void	get_addr2(t_context *ctx)
{
	ctx->fire.f5_img = (int *)mlx_get_data_addr(ctx->fire.f5, &ctx->fire.bpp,
			&ctx->fire.line_size, &ctx->fire.endian);
	if (!ctx->fire.f5_img)
		error("Mlx get data addr failed on", "f5_bonus");
	ctx->fire.f6_img = (int *)mlx_get_data_addr(ctx->fire.f6, &ctx->fire.bpp,
			&ctx->fire.line_size, &ctx->fire.endian);
	if (!ctx->fire.f6_img)
		error("Mlx get data addr failed on", "f6_bonus");
	ctx->fire.f7_img = (int *)mlx_get_data_addr(ctx->fire.f7, &ctx->fire.bpp,
			&ctx->fire.line_size, &ctx->fire.endian);
	if (!ctx->fire.f7_img)
		error("Mlx get data addr failed on", "f7_bonus");
	ctx->fire.f8_img = (int *)mlx_get_data_addr(ctx->fire.f8, &ctx->fire.bpp,
			&ctx->fire.line_size, &ctx->fire.endian);
	if (!ctx->fire.f8_img)
		error("Mlx get data addr failed on", "f8_bonus");
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
		width = ctx->fire.width;
		height = ctx->fire.height;
	}
	else if (width != ctx->fire.width || height != ctx->fire.height)
		error("All textures must be the same size", path);
}
