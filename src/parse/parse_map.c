/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:23:58 by sithomas          #+#    #+#             */
/*   Updated: 2025/05/14 14:48:28 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*go_to_first_map_line(t_context *ctx, char **charmap);
static char	**fill_char_tab(t_context *ctx);
static char	**fill_char_tab_2(char **charmap, t_context *ctx, char *current,
				int max);
static void	check_if_end(t_context *ctx, char **charmap, char *current);

void	fill_map(t_context *ctx)
{
	char	**charmap;
	int		i;

	charmap = fill_char_tab(ctx);
	ctx->map.height = max_height(charmap);
	ctx->map.width = max_width(charmap);
	ctx->map.map = ft_calloc(ctx->map.height, sizeof(int *));
	if (!ctx->map.map)
		error_map(ctx, charmap);
	i = 0;
	while (i < ctx->map.height)
	{
		ctx->map.map[i] = ft_calloc(ctx->map.width, sizeof(int));
		if (!ctx->map.map[i])
		{
			free_chartab(charmap);
			error("malloc error", NULL);
		}
		i++;
	}
	fill_int_tab(ctx, charmap);
}

static char	**fill_char_tab(t_context *ctx)
{
	char	*current;
	char	**charmap;
	int		max;

	charmap = calloc(11, sizeof(char *));
	if (!charmap)
		error_empty_buff(ctx, "malloc error");
	current = go_to_first_map_line(ctx, charmap);
	if (!current)
		error_empty_buff(ctx, "please check map");
	max = 10;
	charmap = fill_char_tab_2(charmap, ctx, current, max);
	return (charmap);
}

static char	**fill_char_tab_2(char **charmap, t_context *ctx, char *current,
		int max)
{
	int	i;

	i = 0;
	while (1)
	{
		while (i < max)
		{
			charmap[i] = ft_strdup(current);
			free(current);
			current = get_next_line(ctx->fd);
			i++;
			if (!current || (current[0] == '\n'))
			{
				check_if_end(ctx, charmap, current);
				charmap[i] = NULL;
				return (charmap);
			}
		}
		charmap = ft_realloc_tab(charmap, max, 10);
		max += 10;
	}
	return (charmap);
}

static char	*go_to_first_map_line(t_context *ctx, char **charmap)
{
	char	*current;
	int		i;

	current = NULL;
	while (1)
	{
		current = get_next_line(ctx->fd);
		if (!current || !current[0])
			error_empty_buff_3(ctx, "please check input file", current,
				charmap);
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

static void	check_if_end(t_context *ctx, char **charmap, char *current)
{
	while (1)
	{
		if (current && current[0] != '\n')
		{
			free_chartab(charmap);
			error_empty_buff_2(ctx, "map error", current);
		}
		if (!current)
			return ;
		free(current);
		current = get_next_line(ctx->fd);
	}
}
