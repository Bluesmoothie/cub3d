/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:55:20 by sithomas          #+#    #+#             */
/*   Updated: 2025/05/14 11:30:43 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	check_line_end(t_context *ctx, char *current, int pos);
static void	fill_tab(t_context *ctx, int *tab, char *tmp, int nb);
static char	*get_number(t_context *ctx, int pos, int i, char *current);
static int	move_till_next_colour(t_context *ctx, char *current);

void	ceiling(t_context *ctx, char *current, int pos, int *tab)
{
	int		i;
	char	*tmp;

	pos++;
	pos += forward_char(current + pos, ' ');
	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	tmp = get_number(ctx, pos, i, current);
	fill_tab(ctx, tab, tmp, 0);
	pos += move_till_next_colour(ctx, current + pos);
	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	tmp = get_number(ctx, pos, i, current);
	fill_tab(ctx, tab, tmp, 1);
	pos += move_till_next_colour(ctx, current + pos);
	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	tmp = get_number(ctx, pos, i, current);
	fill_tab(ctx, tab, tmp, 2);
	check_line_end(ctx, current, pos);
}

static void	fill_tab(t_context *ctx, int *tab, char *tmp, int nb)
{
	tab[nb] = ft_atoi(tmp);
	if (tab[nb] < 0 || tab[nb] > 255)
		error_empty_buff_2(ctx, "problem in floor or ceiling color", tmp);
	free(tmp);
}

static int	move_till_next_colour(t_context *ctx, char *current)
{
	int	i;

	i = 0;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	while (current[i] == ' ')
		i++;
	if (current[i] != ',')
		error_empty_buff_2(ctx, "problem in floor or ceiling color", current);
	i++;
	while (current[i] == ' ')
		i++;
	return (i);
}

static char	*get_number(t_context *ctx, int pos, int i, char *current)
{
	char	*tmp;

	if (pos == i || i > pos + 3)
		error_empty_buff_2(ctx, "problem in floor or ceiling color", current);
	tmp = ft_substr(current, pos, i - pos);
	if (!tmp)
		error_empty_buff_2(ctx, "malloc error", current);
	return (tmp);
}

static void	check_line_end(t_context *ctx, char *current, int pos)
{
	int	i;

	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	while (current[i] == ' ')
		i++;
	if (current[i] != '\n')
		error_empty_buff_2(ctx, "problem in floor or ceiling color", current);
}
