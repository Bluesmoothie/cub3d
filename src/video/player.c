/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:26:12 by ygille            #+#    #+#             */
/*   Updated: 2025/05/06 15:05:55 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	apply_rot(t_player *p, double step_size);

void	player_moves(t_context *ctx)
{
	if (ctx->kin.movdown)
	{
		ctx->player.posx -= ctx->player.viewx * PSTEP_SIZE;
		ctx->player.posy -= ctx->player.viewy * PSTEP_SIZE;
	}
	if (ctx->kin.movup)
	{
		ctx->player.posx += ctx->player.viewx * PSTEP_SIZE;
		ctx->player.posy += ctx->player.viewy * PSTEP_SIZE;
	}
	if (ctx->kin.movleft)
	{
		ctx->player.posx -= ctx->player.viewy * PSTEP_SIZE;
		ctx->player.posy += ctx->player.viewx * PSTEP_SIZE;
	}
	if (ctx->kin.movright)
	{
		ctx->player.posx += ctx->player.viewy * PSTEP_SIZE;
		ctx->player.posy -= ctx->player.viewx * PSTEP_SIZE;
	}
}

void	camera_moves(t_context *ctx)
{
	if (ctx->kin.viewright)
		apply_rot(&ctx->player, CSTEP_SIZE);
	if (ctx->kin.viewleft)
		apply_rot(&ctx->player, -CSTEP_SIZE);
}

static void	apply_rot(t_player *p, double step_size)
{
	const double	mem = p->viewx;
	const double	cosval = cos(step_size);
	const double	sinval = sin(step_size);

	p->viewx = p->viewx * cosval - p->viewy * sinval;
	p->viewy = mem * sinval + p->viewy * cosval;
}
