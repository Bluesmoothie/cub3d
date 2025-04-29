/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:24:46 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/29 15:51:28 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	fill_box(char **charmap, int i, int j);

void	fill_int_tab(t_context *ctx, char **charmap)
{
	int	i;
	int	j;

	i = 0;
	while (i < ctx->map.height)
	{
		j = 0;
		while (charmap[i][j])
		{
			ctx->map.map[i][j] = fill_box(charmap, i, j);
			j++;
		}
		while (j < ctx->map.width)
		{
			ctx->map.map[i][j] = T_EMPTY;
			j++;
		}
		i++;
	}
	free_chartab(charmap);
}

static int	fill_box(char **charmap, int i, int j)
{
	if (charmap[i][j] == ' ')
		return (T_EMPTY);
	else if (charmap[i][j] == '1')
		return (T_WALL);
	else if (charmap[i][j] == '0')
		return (T_HALL);
	else if (charmap[i][j] == 'N')
		return (T_PLAYERN);
	else if (charmap[i][j] == 'S')
		return (T_PLAYERS);
	else if (charmap[i][j] == 'E')
		return (T_PLAYERE);
	else if (charmap[i][j] == 'W')
		return (T_PLAYERW);
	else if (charmap[i][j] == '\n')
		return (T_EMPTY);
	else
	{
		free_chartab(charmap);
		error("Wrong tab", NULL);
	}
	return (0);
}

int	max_height(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	max_width(char **tab)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}
