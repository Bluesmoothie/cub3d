/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:57:58 by ygille            #+#    #+#             */
/*   Updated: 2025/04/29 14:25:45 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_xpm(t_context *ctx);
static void	get_addr(t_context *ctx);
static void	verif(t_context *ctx, void *loaded, void *path);

/*
** Load all textures
*/
void	init_textures(t_context *ctx)
{
	load_xpm(ctx);
	get_addr(ctx);
	init_fire(ctx);
	init_mmap(ctx);
}

/*
**	Unload textures
*/
void	deinit_textures(t_context *ctx)
{
	if (ctx->txt_id.ea)
		mlx_destroy_image(ctx->mlx.id, ctx->txt_id.ea);
	if (ctx->txt_id.so)
		mlx_destroy_image(ctx->mlx.id, ctx->txt_id.so);
	if (ctx->txt_id.no)
		mlx_destroy_image(ctx->mlx.id, ctx->txt_id.no);
	if (ctx->txt_id.we)
		mlx_destroy_image(ctx->mlx.id, ctx->txt_id.we);
	if (ctx->txt_id.cd)
		mlx_destroy_image(ctx->mlx.id, ctx->txt_id.cd);
	if (ctx->txt_path.ea)
		free(ctx->txt_path.ea);
	if (ctx->txt_path.so)
		free(ctx->txt_path.so);
	if (ctx->txt_path.no)
		free(ctx->txt_path.no);
	if (ctx->txt_path.we)
		free(ctx->txt_path.we);
	deinit_fire(ctx);
	deinit_mmap(ctx);
}

static void	load_xpm(t_context *ctx)
{
	ctx->txt_id.ea = mlx_xpm_file_to_image(ctx->mlx.id, ctx->txt_path.ea,
			&ctx->txt_infos.width, &ctx->txt_infos.height);
	verif(ctx, ctx->txt_id.ea, ctx->txt_path.ea);
	ctx->txt_id.no = mlx_xpm_file_to_image(ctx->mlx.id, ctx->txt_path.no,
			&ctx->txt_infos.width, &ctx->txt_infos.height);
	verif(ctx, ctx->txt_id.no, ctx->txt_path.no);
	ctx->txt_id.so = mlx_xpm_file_to_image(ctx->mlx.id, ctx->txt_path.so,
			&ctx->txt_infos.width, &ctx->txt_infos.height);
	verif(ctx, ctx->txt_id.so, ctx->txt_path.so);
	ctx->txt_id.we = mlx_xpm_file_to_image(ctx->mlx.id, ctx->txt_path.we,
			&ctx->txt_infos.width, &ctx->txt_infos.height);
	verif(ctx, ctx->txt_id.we, ctx->txt_path.we);
	ctx->txt_id.cd = mlx_xpm_file_to_image(ctx->mlx.id, "assets/Door.xpm",
			&ctx->txt_infos.width, &ctx->txt_infos.height);
	verif(ctx, ctx->txt_id.cd, "assets/Door.xpm");
}

static void	get_addr(t_context *ctx)
{
	ctx->txt.ea = (int *)mlx_get_data_addr(ctx->txt_id.ea, &ctx->txt_infos.bpp,
			&ctx->txt_infos.line_size, &ctx->txt_infos.endian);
	if (!ctx->txt.ea)
		error("Mlx get data addr failed on", "ea");
	ctx->txt.no = (int *)mlx_get_data_addr(ctx->txt_id.no, &ctx->txt_infos.bpp,
			&ctx->txt_infos.line_size, &ctx->txt_infos.endian);
	if (!ctx->txt.no)
		error("Mlx get data addr failed on", "no");
	ctx->txt.so = (int *)mlx_get_data_addr(ctx->txt_id.so, &ctx->txt_infos.bpp,
			&ctx->txt_infos.line_size, &ctx->txt_infos.endian);
	if (!ctx->txt.so)
		error("Mlx get data addr failed on", "so");
	ctx->txt.we = (int *)mlx_get_data_addr(ctx->txt_id.we, &ctx->txt_infos.bpp,
			&ctx->txt_infos.line_size, &ctx->txt_infos.endian);
	if (!ctx->txt.we)
		error("Mlx get data addr failed on", "we");
	ctx->txt.cd = (int *)mlx_get_data_addr(ctx->txt_id.cd, &ctx->txt_infos.bpp,
			&ctx->txt_infos.line_size, &ctx->txt_infos.endian);
	if (!ctx->txt.cd)
		error("Mlx get data addr failed on", "cd");
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
