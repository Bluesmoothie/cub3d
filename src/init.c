/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:19:51 by ygille            #+#    #+#             */
/*   Updated: 2025/04/25 11:58:31 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	mlx_hook(ctx->mlx.win, DestroyNotify, KeyPressMask, destroy_handler, NULL);
	mlx_hook(ctx->mlx.win, KeyPress, KeyPressMask, keypress_handler,
		(void *)&ctx->kin);
	mlx_hook(ctx->mlx.win, KeyRelease, KeyReleaseMask, keyrelease_handler,
		(void *)&ctx->kin);
	mlx_expose_hook(ctx->mlx.win, renderer, (void *)ctx);
	mlx_loop_hook(ctx->mlx.id, renderer, (void *)ctx);
	mlx_loop(ctx->mlx.id);
}
