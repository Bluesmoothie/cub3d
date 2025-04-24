/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:27:17 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/24 17:48:07 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	forward_char(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] == sep)
		i++;
	return (i);
}

char	**ft_realloc_tab(char **tab, int max, int size)
{
	char	**newtab;
	int		i;

	newtab = malloc((max + size) * sizeof(char *));
	// if (!newtab)
	// 	free_tab_exit(tab);
	i = 0;
	while (i < max)
	{
		newtab[i] = tab[i];
		i++;
	}
	while (i < max + size)
	{
		newtab[i] = NULL;
		i++;
	}
	free(tab);
	return (newtab);
}

void	check_first_and_last_line(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width)
	{
		if (map->map[0][i] > -1 && map->map[0][i] != 1)
			error("wrong map", NULL);
	}
	i = -1;
	while (++i < map->width)
	{
		if (map->map[map->height - 1][i] > -1 && map->map[map->height
			- 1][i] != 1)
			error("wrong map", NULL);
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
}

void	free_chartab(char **chartab)
{
	int	i;

	i = 0;
	while (chartab[i])
	{
		free(chartab[i]);
		i++;
	}
	free(chartab);
}