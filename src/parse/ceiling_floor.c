/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:55:20 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/24 14:58:58 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	check_line_end(char *current, int pos);
static void	fill_tab(int *tab, char *tmp, int nb);
static char	*get_number(int pos, int i, char *current);
static int	move_till_next_colour(char *current);

void	ceiling(char *current, int pos, int *tab)
{
	int		i;
	char	*tmp;

	pos++;
	pos += forward_char(current + pos, ' ');
	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	tmp = get_number(pos, i, current);
	fill_tab(tab, tmp, 0);
	pos += move_till_next_colour(current + pos);
	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	tmp = get_number(pos, i, current);
	fill_tab(tab, tmp, 1);
	pos += move_till_next_colour(current + pos);
	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	tmp = get_number(pos, i, current);
	fill_tab(tab, tmp, 2);
	check_line_end(current, pos);
}

static void	fill_tab(int *tab, char *tmp, int nb)
{
	tab[nb] = ft_atoi(tmp);
	if (tab[nb] < 0 || tab[nb] > 255)
		error("problem in floor or ceiling color", NULL);
	free(tmp);
}

static int	move_till_next_colour(char *current)
{
	int	i;

	i = 0;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	while (current[i] == ' ')
		i++;
	if (current[i] != ',')
		error("problem in floor or ceiling color", NULL);
	i++;
	while (current[i] == ' ')
		i++;
	return (i);
}

static char	*get_number(int pos, int i, char *current)
{
	char	*tmp;

	if (pos == i || i > pos + 3)
		error("problem in floor or ceiling color", NULL);
	tmp = ft_substr(current, pos, i - pos);
	if (!tmp)
		error("malloc error", NULL);
	return (tmp);
}

static void	check_line_end(char *current, int pos)
{
	int	i;

	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	while (current[i] == ' ')
		i++;
	if (current[i] != '\n')
		error("problem in floor or ceiling color", NULL);
}
