/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:24:46 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/24 11:02:45 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	fill_box(char c);

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
			ctx->map.map[i][j] = fill_box(charmap[i][j]);
			j++;
		}
		while (j < ctx->map.width)
		{
			ctx->map.map[i][j] = -1;
			j++;
		}
		i++;
	}
}

static int	fill_box(char c)
{
	if (c == ' ')
		return (-1);
	else if (c == '1')
		return (1);
	else if (c == '0')
		return (0);
	else if (c == 'N')
		return (2);
	else if (c == 'S')
		return (3);
	else if (c == 'E')
		return (4);
	else if (c == 'W')
		return (5);
	else if (c == '\n')
		return (-1);
	else
		error("Wrong tab", NULL);
	return (0);
}

int	max_height(char **tab)
{
	int i;

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