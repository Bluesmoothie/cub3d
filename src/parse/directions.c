/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:40:26 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/24 14:57:51 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	fill_path(char *current, int pos, t_textures *txt, int direction);
static char	fill_second_letter(int direction);

void	directions(char *current, int i, t_textures *txt)
{
	if (!current[i] || !current[i + 1] || !current[i + 2])
		error("Error in input file please rectify", NULL);
	if (!ft_strncmp(current + i, "NO", 2) || !ft_strncmp("current + i", "N", 1))
		fill_path(current, i, txt, 1);
	else if (!ft_strncmp(current + i, "SO", 2) || !ft_strncmp("current + i",
			"S", 1))
		fill_path(current, i, txt, 2);
	else if (!ft_strncmp(current + i, "WE", 2) || !ft_strncmp("current + i",
			"W", 1))
		fill_path(current, i, txt, 3);
	else if (!ft_strncmp(current + i, "EA", 2) || !ft_strncmp("current + i",
			"E", 1))
		fill_path(current, i, txt, 4);
	else
		error("please check input file", NULL);
}

static void	fill_path(char *current, int pos, t_textures *txt, int direction)
{
	char	*path;
	char	letter;
	int		i;

	pos++;
	letter = fill_second_letter(direction);
	if (current[pos] == letter)
		pos++;
	while (current[pos] == ' ')
		pos++;
	i = pos;
	while (current[i] && current[i] != '\n')
		i++;
	path = ft_substr(current, pos, i - pos);
	if (!path)
		error("malloc_error", NULL);
	if (direction == 1)
		txt->no = path;
	if (direction == 2)
		txt->so = path;
	if (direction == 3)
		txt->we = path;
	if (direction == 4)
		txt->ea = path;
}

static char	fill_second_letter(int direction)
{
	if (direction == 1)
		return ('O');
	if (direction == 2)
		return ('O');
	if (direction == 3)
		return ('E');
	if (direction == 4)
		return ('A');
	return (0);
}
