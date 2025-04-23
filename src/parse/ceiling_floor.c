/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:55:20 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/23 13:21:05 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parse.h"

static void	check_line_end(char *current, int pos);
static void	fill_tab(t_textures *paths, char *tmp, int nb, int c_o_f);
static char	*get_number(int pos, int i, char *current);
static int	move_till_next_colour(char *current);


void ceiling(char *current, int pos, t_textures *paths, int c_o_f)
{
	int		i;
	char	*tmp;
	
	pos++;
	pos += forward_char(current + pos, ' ');
	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	tmp = get_number(pos, i, current);
	fill_tab(paths, tmp, 0, c_o_f);
	pos += move_till_next_colour(current + pos);
	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	tmp = get_number(pos, i, current);
	fill_tab(paths, tmp, 1, c_o_f);
	pos += move_till_next_colour(current + pos);
	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	tmp = get_number(pos, i, current);
	fill_tab(paths, tmp, 2, c_o_f);
	check_line_end(current, pos);
}

static void	fill_tab(t_textures *paths, char *tmp, int nb, int c_o_f)
{
	if (c_o_f == 1)
	{
		paths->floor[nb] = ft_atoi(tmp);
		if (paths->floor[nb] < 0 || paths->floor[nb] > 255)
			error("problem in floor or ceiling color");
	}
	if (c_o_f == 2)
	{
		paths->ceiling[nb] = ft_atoi(tmp);
		if (paths->ceiling[nb] < 0 || paths->ceiling[nb] > 255)
			error("problem in floor or ceiling color");
	}
	free(tmp);
}

static int	move_till_next_colour(char *current)
{
	int i;
	
	i = 0;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	while (current[i] == ' ')
		i++;
	if (current[i] != ',')
		error("problem in floor or ceiling color");
	i++;
	while (current[i] == ' ')
		i++;
	return (i);
}

static char	*get_number(int pos, int i, char *current)
{
	char	*tmp;
	
	if (pos == i || i > pos + 3)
		error("problem in floor or ceiling color");
	tmp = ft_substr(current, pos, i - pos);
	if (!tmp)
		error("malloc error");
	return (tmp);
}

static void	check_line_end(char *current, int pos)
{
	int i;
	
	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	while (current[i] == ' ')
		i++;
	if (current[i] != '\n')
		error("problem in floor or ceiling color");
}