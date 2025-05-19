/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:55:20 by sithomas          #+#    #+#             */
/*   Updated: 2025/05/19 16:27:06 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	check_line_end(t_context *ctx, char *current, int pos);
static int	fill_tab(t_context *ctx, char *tmp, char *current);
static char	*get_number(t_context *ctx, int pos, int i, char *current);
static int	move_till_next_colour(t_context *ctx, char *current, int pos);

void	ceiling(t_context *ctx, char *current, int pos, int *tab)
{
	int		i;
	int		nb;
	char	*tmp;

	pos++;
	pos += forward_char(current + pos, ' ');
	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	tmp = get_number(ctx, pos, i, current);
	nb = 0;
	tab[nb++] = fill_tab(ctx, tmp, current);
	pos = move_till_next_colour(ctx, current, pos);
	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	tmp = get_number(ctx, pos, i, current);
	tab[nb++] = fill_tab(ctx, tmp, current);
	pos = move_till_next_colour(ctx, current, pos);
	i = pos;
	while (current[i] <= '9' && current[i] >= '0')
		i++;
	tmp = get_number(ctx, pos, i, current);
	tab[nb++] = fill_tab(ctx, tmp, current);
	check_line_end(ctx, current, pos);
}

static int	fill_tab(t_context *ctx, char *tmp, char *current)
{
	int	result;

	if (ft_strlen(tmp) > 3)
		error_empty_buff_3(ctx, "problem in floor or ceiling color",
			tmp, (void *)current);
	result = ft_atoi(tmp);
	if (result < 0 || result > 255)
		error_empty_buff_3(ctx, "problem in floor or ceiling color",
			tmp, (void *)current);
	free(tmp);
	return (result);
}

static int	move_till_next_colour(t_context *ctx, char *current, int pos)
{
	int	i;

	i = pos;
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
