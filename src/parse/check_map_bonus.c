/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:15:10 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/29 15:47:42 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	look_for_hole(t_map *map, int i, int j);
static void	check_first_and_last_column(t_map *map);
static void	check_zeros_and_perso(t_map *map);
static void	check_perso(t_map *map);

void	check_map(t_map *map)
{
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
		if (map->map[i][0] > T_EMPTY && map->map[i][0] != T_WALL)
			error("wrong map", NULL);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][map->width - 1] > T_EMPTY && map->map[i][map->width
			- 1] != T_WALL)
			error("wrong map", NULL);
		i++;
	}
}

static void	check_zeros_and_perso(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->height - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			if (map->map[i][j] == T_HALL || map->map[i][j] > T_PLAYERW)
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
	if (map->map[i - 1][j - 1] != T_HALL && map->map[i - 1][j - 1] < T_WALL)
		error("map error", NULL);
	if (map->map[i][j - 1] != T_HALL && map->map[i][j - 1] < T_WALL)
		error("map error", NULL);
	if (map->map[i + 1][j - 1] != T_HALL && map->map[i + 1][j - 1] < T_WALL)
		error("map error", NULL);
	if (map->map[i - 1][j] != T_HALL && map->map[i - 1][j] < T_WALL)
		error("map error", NULL);
	if (map->map[i + 1][j] != T_HALL && map->map[i + 1][j] < T_WALL)
		error("map error", NULL);
	if (map->map[i - 1][j + 1] != T_HALL && map->map[i - 1][j + 1] < T_WALL)
		error("map error", NULL);
	if (map->map[i][j + 1] != T_HALL && map->map[i][j + 1] < T_WALL)
		error("map error", NULL);
	if (map->map[i + 1][j + 1] != T_HALL && map->map[i + 1][j + 1] < T_WALL)
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
			if (map->map[i][j] > T_WALL && map->map[i][j] < T_CLOSEDOOR && !is_already_here)
				is_already_here = 1;
			else if (map->map[i][j] > T_WALL && map->map[i][j] < T_CLOSEDOOR
				&& is_already_here)
				error("too many characters", NULL);
			j++;
		}
		i++;
	}
	if (!is_already_here)
		error("No character in map", NULL);
}
