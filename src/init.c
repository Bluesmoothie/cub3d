/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:19:51 by ygille            #+#    #+#             */
/*   Updated: 2025/04/22 17:55:51 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	verif(t_context *ctx, void *loaded, void *path);

/*
**	Initialize ctx struct and pass the ptr to the exit func
*/
void	init_ctx(t_context *ctx)
{
	ft_bzero(ctx, sizeof(t_context));
	exit_set_ctx(ctx);
}

/*
**	Initialize render/input loop
*/
void	init_hooks_loops(t_context *ctx)
{
	mlx_loop_hook(ctx->mlx.id, renderer, (void*)ctx);
	mlx_expose_hook(ctx->mlx.win, renderer, (void*)ctx);
	mlx_hook(ctx->mlx.win, KeyPress, KeyPressMask, keyPress_handler, (void*)&ctx->kin);
	mlx_hook(ctx->mlx.win, KeyRelease, KeyReleaseMask, keyRelease_handler, (void*)&ctx->kin);
	mlx_mouse_hook(ctx->mlx.win, mouse_handler, (void*)&ctx->min);
	mlx_hook(ctx->mlx.win, DestroyNotify, KeyPressMask, destroy_handler, NULL);
}

/*
** Load all textures
*/
void	init_textures(t_context *ctx)
{
	ctx->txt_id.EA = mlx_xpm_file_to_image(ctx->mlx.id, ctx->txt_path.EA, &ctx->txt_infos.width, &ctx->txt_infos.height);
	verif(ctx, ctx->txt.EA, ctx->txt_path.EA);
	ctx->txt_id.NO = mlx_xpm_file_to_image(ctx->mlx.id, ctx->txt_path.NO, &ctx->txt_infos.width, &ctx->txt_infos.height);
	verif(ctx, ctx->txt.NO, ctx->txt_path.NO);
	ctx->txt_id.SO = mlx_xpm_file_to_image(ctx->mlx.id, ctx->txt_path.SO, &ctx->txt_infos.width, &ctx->txt_infos.height);
	verif(ctx, ctx->txt.SO, ctx->txt_path.SO);
	ctx->txt_id.WE = mlx_xpm_file_to_image(ctx->mlx.id, ctx->txt_path.WE, &ctx->txt_infos.width, &ctx->txt_infos.height);
	verif(ctx, ctx->txt.WE, ctx->txt_path.WE);
	ctx->txt.EA = mlx_get_data_addr(ctx->txt_id.EA, &ctx->txt_infos.bpp, &ctx->txt_infos.line_size, &ctx->txt_infos.endian);
	if (!ctx->txt.EA)
		error("Mlx get data addr failed on", "EA");
	ctx->txt.NO = mlx_get_data_addr(ctx->txt_id.NO, &ctx->txt_infos.bpp, &ctx->txt_infos.line_size, &ctx->txt_infos.endian);
	if (!ctx->txt.NO)
		error("Mlx get data addr failed on", "NO");
	ctx->txt.SO = mlx_get_data_addr(ctx->txt_id.SO, &ctx->txt_infos.bpp, &ctx->txt_infos.line_size, &ctx->txt_infos.endian);
	if (!ctx->txt.SO)
		error("Mlx get data addr failed on", "SO");
	ctx->txt.WE = mlx_get_data_addr(ctx->txt_id.WE, &ctx->txt_infos.bpp, &ctx->txt_infos.line_size, &ctx->txt_infos.endian);
	if (!ctx->txt.WE)
		error("Mlx get data addr failed on", "WE");
}

/*
**	Unload textures
*/
void	deinit_textures(t_context *ctx)
{
	if (ctx->txt.EA)
		mlx_destroy_image(ctx->mlx.id, ctx->txt.EA);
	if (ctx->txt.SO)
		mlx_destroy_image(ctx->mlx.id, ctx->txt.SO);
	if (ctx->txt.NO)
		mlx_destroy_image(ctx->mlx.id, ctx->txt.NO);
	if (ctx->txt.WE)
		mlx_destroy_image(ctx->mlx.id, ctx->txt.WE);
}

/*
**	Verify if a texture loaded successfully
*/
static void	verif(t_context *ctx, void *loaded, void *path)
{
	static int width = 0;
	static int height = 0;

	if (!loaded)
		error("Failed to load", path);
	if (!width)
	{
		width = ctx->txt_infos.width;
		height = ctx->txt_infos.height;
	}
	else if (width != ctx->txt_infos.width || height != ctx->txt_infos.height)
		error("All textures must be the same size", path);
}
