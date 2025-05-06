/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:18:36 by ygille            #+#    #+#             */
/*   Updated: 2025/05/06 16:54:19 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_xpm(t_context *ctx);
static void	get_addr(t_context *ctx);
static void	get_addr2(t_context *ctx);

void	init_fire(t_context *ctx)
{
	load_xpm(ctx);
	get_addr(ctx);
}

static void	load_xpm(t_context *ctx)
{
	ctx->fire.f1 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f1_bonus.xpm",
			&ctx->fire.txtinfos.width, &ctx->fire.txtinfos.height);
	verif(ctx, ctx->fire.f1, "assets/f1_bonus.xpm");
	ctx->fire.f2 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f2_bonus.xpm",
			&ctx->fire.txtinfos.width, &ctx->fire.txtinfos.height);
	verif(ctx, ctx->fire.f2, "assets/f2_bonus.xpm");
	ctx->fire.f3 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f3_bonus.xpm",
			&ctx->fire.txtinfos.width, &ctx->fire.txtinfos.height);
	verif(ctx, ctx->fire.f3, "assets/f3_bonus.xpm");
	ctx->fire.f4 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f4_bonus.xpm",
			&ctx->fire.txtinfos.width, &ctx->fire.txtinfos.height);
	verif(ctx, ctx->fire.f4, "assets/f4_bonus.xpm");
	ctx->fire.f5 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f5_bonus.xpm",
			&ctx->fire.txtinfos.width, &ctx->fire.txtinfos.height);
	verif(ctx, ctx->fire.f5, "assets/f5_bonus.xpm");
	ctx->fire.f6 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f6_bonus.xpm",
			&ctx->fire.txtinfos.width, &ctx->fire.txtinfos.height);
	verif(ctx, ctx->fire.f6, "assets/f6_bonus.xpm");
	ctx->fire.f7 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f7_bonus.xpm",
			&ctx->fire.txtinfos.width, &ctx->fire.txtinfos.height);
	verif(ctx, ctx->fire.f7, "assets/f7_bonus.xpm");
	ctx->fire.f8 = mlx_xpm_file_to_image(ctx->mlx.id, "assets/f8_bonus.xpm",
			&ctx->fire.txtinfos.width, &ctx->fire.txtinfos.height);
	verif(ctx, ctx->fire.f8, "assets/f8_bonus.xpm");
}

static void	get_addr(t_context *ctx)
{
	ctx->fire.f1_img = (int *)mlx_get_data_addr(ctx->fire.f1,
			&ctx->fire.txtinfos.bpp, &ctx->fire.txtinfos.line_size,
			&ctx->fire.txtinfos.endian);
	if (!ctx->fire.f1_img)
		error(EMGETDATA, "f1_bonus");
	ctx->fire.f2_img = (int *)mlx_get_data_addr(ctx->fire.f2,
			&ctx->fire.txtinfos.bpp, &ctx->fire.txtinfos.line_size,
			&ctx->fire.txtinfos.endian);
	if (!ctx->fire.f2_img)
		error(EMGETDATA, "f2_bonus");
	ctx->fire.f3_img = (int *)mlx_get_data_addr(ctx->fire.f3,
			&ctx->fire.txtinfos.bpp, &ctx->fire.txtinfos.line_size,
			&ctx->fire.txtinfos.endian);
	if (!ctx->fire.f3_img)
		error(EMGETDATA, "f3_bonus");
	ctx->fire.f4_img = (int *)mlx_get_data_addr(ctx->fire.f4,
			&ctx->fire.txtinfos.bpp, &ctx->fire.txtinfos.line_size,
			&ctx->fire.txtinfos.endian);
	if (!ctx->fire.f4_img)
		error(EMGETDATA, "f4_bonus");
	get_addr2(ctx);
}

static void	get_addr2(t_context *ctx)
{
	ctx->fire.f5_img = (int *)mlx_get_data_addr(ctx->fire.f5,
			&ctx->fire.txtinfos.bpp, &ctx->fire.txtinfos.line_size,
			&ctx->fire.txtinfos.endian);
	if (!ctx->fire.f5_img)
		error(EMGETDATA, "f5_bonus");
	ctx->fire.f6_img = (int *)mlx_get_data_addr(ctx->fire.f6,
			&ctx->fire.txtinfos.bpp, &ctx->fire.txtinfos.line_size,
			&ctx->fire.txtinfos.endian);
	if (!ctx->fire.f6_img)
		error(EMGETDATA, "f6_bonus");
	ctx->fire.f7_img = (int *)mlx_get_data_addr(ctx->fire.f7,
			&ctx->fire.txtinfos.bpp, &ctx->fire.txtinfos.line_size,
			&ctx->fire.txtinfos.endian);
	if (!ctx->fire.f7_img)
		error(EMGETDATA, "f7_bonus");
	ctx->fire.f8_img = (int *)mlx_get_data_addr(ctx->fire.f8,
			&ctx->fire.txtinfos.bpp, &ctx->fire.txtinfos.line_size,
			&ctx->fire.txtinfos.endian);
	if (!ctx->fire.f8_img)
		error(EMGETDATA, "f8_bonus");
}
