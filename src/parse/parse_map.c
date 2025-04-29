/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:23:58 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/29 17:50:15 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*go_to_first_map_line(int fd);
static char	**fill_char_tab(int fd);
static char	**fill_char_tab_2(char **charmap, int fd, char *current, int max);
static void	check_if_end(int fd);

void	fill_map(int fd, t_context *ctx)
{
	char	**charmap;
	int		i;

	charmap = fill_char_tab(fd);
	ctx->map.height = max_height(charmap);
	ctx->map.width = max_width(charmap);
	ctx->map.map = ft_calloc(ctx->map.height, sizeof(int *));
	if (!ctx->map.map)
		error("malloc error", NULL);
	i = 0;
	while (i < ctx->map.height)
	{
		ctx->map.map[i] = ft_calloc(ctx->map.width, sizeof(int));
		if (!ctx->map.map[i])
			error("malloc error", NULL);
		i++;
	}
	fill_int_tab(ctx, charmap);
}

static char	**fill_char_tab(int fd)
{
	char	*current;
	char	**charmap;
	int		max;

	charmap = malloc(11 * sizeof(char *));
	if (!charmap)
		error("malloc error", NULL);
	current = go_to_first_map_line(fd);
	if (!current)
		error("please check map", NULL);
	max = 10;
	charmap = fill_char_tab_2(charmap, fd, current, max);
	return (charmap);
}

static char	**fill_char_tab_2(char **charmap, int fd, char *current, int max)
{
	int	i;

	i = 0;
	while (1)
	{
		while (i < max)
		{
			charmap[i] = ft_strdup(current);
			free(current);
			current = get_next_line(fd);
			i++;
			if (!current || (current[0] == '\n'))
			{
				check_if_end(fd);
				if (current)
					free(current);
				charmap[i] = NULL;
				return (charmap);
			}
		}
		charmap = ft_realloc_tab(charmap, max, 10);
		max += 10;
	}
	return (charmap);
}

static char	*go_to_first_map_line(int fd)
{
	char	*current;
	int		i;

	current = NULL;
	while (1)
	{
		current = get_next_line(fd);
		if (!current || !current[0])
			error("please check input file", NULL);
		i = 0;
		while (current[i] == ' ')
			i++;
		if (current[i] == '\n')
		{
			free(current);
			continue ;
		}
		else
			return (current);
	}
}

static void	check_if_end(int fd)
{
	char	*test;

	while (1)
	{
		test = get_next_line(fd);
		if (test && ft_strlen(test) > 1 && test[0] != '\n')
		{
			free(test);
			error("map error", NULL);
		}
		if (!test)
			return ;
	}
}
