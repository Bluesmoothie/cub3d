/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:47:16 by ygille            #+#    #+#             */
/*   Updated: 2025/04/25 16:48:58 by ygille           ###   ########.fr       */
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
