/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:26:12 by ygille            #+#    #+#             */
/*   Updated: 2025/04/24 12:45:58 by ygille           ###   ########.fr       */
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
	double	mem;

	if (ctx->kin.viewright)
	{
		mem = ctx->player.dirx;
		ctx->player.dirx = ctx->player.dirx * cos(CSTEP_SIZE) - ctx->player.diry * sin (CSTEP_SIZE);
		ctx->player.diry = mem * sin(CSTEP_SIZE) + ctx->player.diry * cos(CSTEP_SIZE);
		mem = ctx->player.planex;
		ctx->player.planex = ctx->player.planex * cos(CSTEP_SIZE) - ctx->player.planey * sin(CSTEP_SIZE);
		ctx->player.planey = mem * sin(CSTEP_SIZE) + ctx->player.planey * cos(CSTEP_SIZE);
	}
	if (ctx->kin.viewleft)
	{
		mem = ctx->player.dirx;
		ctx->player.dirx = ctx->player.dirx * cos(-CSTEP_SIZE) - ctx->player.diry * sin (-CSTEP_SIZE);
		ctx->player.diry = mem * sin(-CSTEP_SIZE) + ctx->player.diry * cos(-CSTEP_SIZE);
		mem = ctx->player.planex;
		ctx->player.planex = ctx->player.planex * cos(-CSTEP_SIZE) - ctx->player.planey * sin(-CSTEP_SIZE);
		ctx->player.planey = mem * sin(-CSTEP_SIZE) + ctx->player.planey * cos(-CSTEP_SIZE);
	}
}
