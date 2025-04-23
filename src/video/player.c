/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:26:12 by ygille            #+#    #+#             */
/*   Updated: 2025/04/23 15:32:40 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_moves(t_context *ctx)
{
	if (ctx->kin.movdown)
		ctx->player.y -= PSTEP_SIZE;
	if (ctx->kin.movup)
		ctx->player.y += PSTEP_SIZE;
	if (ctx->kin.movleft)
		ctx->player.x -= PSTEP_SIZE;
	if (ctx->kin.movright)
		ctx->player.x += PSTEP_SIZE;
	if (ctx->kin.viewleft)
		ctx->player.camera -= CSTEP_SIZE;
	if (ctx->kin.viewright)
		ctx->player.camera += CSTEP_SIZE;
	if (ctx->player.camera < 0)
		ctx->player.camera = 360;
	if (ctx->player.camera > 360)
		ctx->player.camera = 0;
}
