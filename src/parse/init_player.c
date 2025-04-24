/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:37:32 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/24 14:20:31 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parse.h"

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
				ctx->player.posx = (double)i;
				ctx->player.posy = (double)j;
				fill_player_dir(ctx, ctx->map.map[i][j]);
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