/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:23:06 by ygille            #+#    #+#             */
/*   Updated: 2025/04/22 17:18:33 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exit_handler(t_context *ctx, int op);

/*
**	Set ctx ptr to exit_call function properly
*/
void	exit_set_ctx(t_context *ctx)
{
	exit_handler(ctx, STORE);
}

/*
**	Exit properly
*/
void	exit_call(void)
{
	exit_handler(NULL, CALL);
}

/*
**	Exit properly (with ctx ptr)
*/
void	free_exit(t_context *ctx)
{
	deinit_video(ctx->mlx);
	exit(0);
}

static void	exit_handler(t_context *ctx, int op)
{
	static t_context	*ctx_mem = NULL;

	if (op == STORE)
		ctx_mem = ctx;
	else if (op == CALL)
		free_exit(ctx_mem);
}
