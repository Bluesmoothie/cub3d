/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:37:32 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/28 11:58:04 by ygille           ###   ########.fr       */
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
			if (ctx->map.map[i][j] > 1 && ctx->map.map[i][j] < 6)
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
	if (pos == 2)
	{
		ctx->player.dirx = -1.0;
		ctx->player.diry = 0.0;
	}
	else if (pos == 3)
	{
		ctx->player.dirx = 1.0;
		ctx->player.diry = 0.0;
	}
	else if (pos == 4)
	{
		ctx->player.dirx = 0.0;
		ctx->player.diry = 1.0;
	}
	else if (pos == 5)
	{
		ctx->player.dirx = 0.0;
		ctx->player.diry = -1.0;
	}
}
