/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:26:12 by ygille            #+#    #+#             */
/*   Updated: 2025/04/25 11:26:44 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	apply_rot(t_player *player, double step_size);

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
	if (ctx->kin.viewright)
		apply_rot(&ctx->player, CSTEP_SIZE);
	if (ctx->kin.viewleft)
		apply_rot(&ctx->player, -CSTEP_SIZE);
}

static void	apply_rot(t_player *player, double step_size)
{
	const double	mem = player->dirx;

	player->dirx = player->dirx * cos(step_size) - player->diry * sin (step_size);
	player->diry = mem * sin(step_size) + player->diry * cos(step_size);
}
