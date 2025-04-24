/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:26:12 by ygille            #+#    #+#             */
/*   Updated: 2025/04/24 18:44:46 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_moves(t_context *ctx)
{
	if (ctx->kin.movdown)
	{
		ctx->player.posx -= ctx->player.dirx * PSTEP_SIZE;
		ctx->player.posy -= ctx->player.diry * PSTEP_SIZE;
	}
	if (ctx->kin.movup)
	{
		ctx->player.posx += ctx->player.dirx * PSTEP_SIZE;
		ctx->player.posy += ctx->player.diry * PSTEP_SIZE;
	}
	if (ctx->kin.movleft)
	{
		ctx->player.posx -= ctx->player.diry * PSTEP_SIZE;
		ctx->player.posy += ctx->player.dirx * PSTEP_SIZE;
	}
	if (ctx->kin.movright)
	{
		ctx->player.posx += ctx->player.diry * PSTEP_SIZE;
		ctx->player.posy -= ctx->player.dirx * PSTEP_SIZE;
	}
}

void	camera_moves(t_context *ctx)
{
	const double	mem = ctx->player.dirx;

	if (ctx->kin.viewright)
	{
		ctx->player.dirx = ctx->player.dirx * cos(CSTEP_SIZE) - ctx->player.diry * sin (CSTEP_SIZE);
		ctx->player.diry = mem * sin(CSTEP_SIZE) + ctx->player.diry * cos(CSTEP_SIZE);
	}
	if (ctx->kin.viewleft)
	{
		ctx->player.dirx = ctx->player.dirx * cos(-CSTEP_SIZE) - ctx->player.diry * sin (-CSTEP_SIZE);
		ctx->player.diry = mem * sin(-CSTEP_SIZE) + ctx->player.diry * cos(-CSTEP_SIZE);
	}
}
