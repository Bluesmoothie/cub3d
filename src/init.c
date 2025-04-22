/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:19:51 by ygille            #+#    #+#             */
/*   Updated: 2025/04/22 17:19:33 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	verif(t_textures txt, void *loaded, void *path);

/*
**	Initialize ctx struct and pass the ptr to the exit func
*/
void	init_ctx(t_context *ctx)
{
	ft_bzero(ctx, sizeof(t_context));
	exit_set_ctx(ctx);
}

/*
** Load all textures
*/
void	init_textures(t_context *ctx)
{
	ctx->txt.EA = mlx_xpm_file_to_image(ctx->mlx.id, ctx->txt_path.EA, &ctx->txt.width, &ctx->txt.height);
	verif(ctx->txt, ctx->txt.EA, ctx->txt_path.EA);
	ctx->txt.NO = mlx_xpm_file_to_image(ctx->mlx.id, ctx->txt_path.NO, &ctx->txt.width, &ctx->txt.height);
	verif(ctx->txt, ctx->txt.NO, ctx->txt_path.NO);
	ctx->txt.SO = mlx_xpm_file_to_image(ctx->mlx.id, ctx->txt_path.SO, &ctx->txt.width, &ctx->txt.height);
	verif(ctx->txt, ctx->txt.SO, ctx->txt_path.SO);
	ctx->txt.WE = mlx_xpm_file_to_image(ctx->mlx.id, ctx->txt_path.WE, &ctx->txt.width, &ctx->txt.height);
	verif(ctx->txt, ctx->txt.WE, ctx->txt_path.WE);
}

/*
**	Verify if a texture loaded successfully
*/
static void	verif(t_textures txt, void *loaded, void *path)
{
	static int width = 0;
	static int height = 0;

	if (!loaded)
		error("Failed to load", path);
	if (!width)
	{
		width = txt.width;
		height = txt.height;
	}
	else if (width != txt.width || height != txt.height)
		error("All textures must be the same size", path);
}
