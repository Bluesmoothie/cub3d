/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:15:10 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/24 14:57:46 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	look_for_hole(t_map *map, int i, int j);
static void	check_first_and_last_column(t_map *map);
static void	check_zeros_and_perso(t_map *map);
static void	check_perso(t_map *map);

void	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%d", map->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	check_first_and_last_line(map);
	check_first_and_last_column(map);
	check_zeros_and_perso(map);
	check_perso(map);
}

static void	check_first_and_last_column(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] > -1 && map->map[i][0] != 1)
			error("wrong map", NULL);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][map->width - 1] > -1 && map->map[i][map->width
			- 1] != 1)
			error("wrong map", NULL);
		i++;
	}
}

static void	check_zeros_and_perso(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	printf("HERE\n");
	while (i < map->height - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			if (map->map[i][j] == 0)
			{
				look_for_hole(map, i, j);
			}
			j++;
		}
		i++;
	}
}

static void	look_for_hole(t_map *map, int i, int j)
{
	if (map->map[i - 1][j - 1] != 0 && map->map[i - 1][j - 1] < 1)
		error("map error", NULL);
	if (map->map[i][j - 1] != 0 && map->map[i][j - 1] < 1)
		error("map error", NULL);
	if (map->map[i + 1][j - 1] != 0 && map->map[i + 1][j - 1] < 1)
		error("map error", NULL);
	if (map->map[i - 1][j] != 0 && map->map[i - 1][j] < 1)
		error("map error", NULL);
	if (map->map[i + 1][j] != 0 && map->map[i + 1][j] < 1)
		error("map error", NULL);
	if (map->map[i - 1][j + 1] != 0 && map->map[i - 1][j + 1] < 1)
		error("map error", NULL);
	if (map->map[i][j + 1] != 0 && map->map[i][j + 1] < 1)
		error("map error", NULL);
	if (map->map[i + 1][j + 1] != 0 && map->map[i + 1][j + 1] < 1)
		error("map error", NULL);
}

static void	check_perso(t_map *map)
{
	int		i;
	int		j;
	t_bool	is_already_here;

	i = 1;
	is_already_here = 0;
	while (i < map->height - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			if (map->map[i][j] > 1 && !is_already_here)
				is_already_here = 1;
			else if (map->map[i][j] > 1 && is_already_here)
				error("too many characters", NULL);
			j++;
		}
		i++;
	}
}

// if (map->map[i-1][j-1] < 0)
// error("map error", NULL);
// else if (map->map[i][j-1] < 0)
// error("map error", NULL);
// else if (map->map[i+1][j-1] < 0)
// error("map error", NULL);
// else if (map->map[i-1][j] < 0)
// error("map error", NULL);
// else if (map->map[i+1][j] < 0)
// error("map error", NULL);
// else if (map->map[i-1][j+1] < 0)
// error("map error", NULL);
// else if (map->map[i][j+1] < 0)
// error("map error", NULL);
// else if (map->map[i+1][j+1] < 0)
// error("map error", NULL);