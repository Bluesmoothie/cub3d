/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:37:32 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/29 15:49:20 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	fill_player_dir(t_context *ctx, int pos);

void	init_player(t_context *ctx)
{
	int	i;
	int	j;

	i = 1;
	while (i < ctx->map.height - 1)
	{
		j = 1;
		while (j < ctx->map.width - 1)
		{
			if (ctx->map.map[i][j] > T_WALL && ctx->map.map[i][j] < 6)
			{
				ctx->player.posx = (double)i + 0.5;
				ctx->player.posy = (double)j + 0.5;
				fill_player_dir(ctx, ctx->map.map[i][j]);
				ctx->map.map[i][j] = 0;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	fill_player_dir(t_context *ctx, int pos)
{
	if (pos == T_PLAYERN)
	{
		ctx->player.dirx = -1.0;
		ctx->player.diry = 0.0;
	}
	else if (pos == T_PLAYERS)
	{
		ctx->player.dirx = 1.0;
		ctx->player.diry = 0.0;
	}
	else if (pos == T_PLAYERE)
	{
		ctx->player.dirx = 0.0;
		ctx->player.diry = 1.0;
	}
	else if (pos == T_PLAYERW)
	{
		ctx->player.dirx = 0.0;
		ctx->player.diry = -1.0;
	}
}
