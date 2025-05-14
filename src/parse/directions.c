/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:40:26 by sithomas          #+#    #+#             */
/*   Updated: 2025/05/14 12:59:21 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	fill_path(char *current, int pos, t_context *ctx, int direction);
static char	fill_second_letter(int direction);
static void	fill_path_2(int dir, t_context *ctx, char *path, char *current);

void	directions(char *current, int i, t_context *ctx)
{
	if (!current[i] || !current[i + 1] || !current[i + 2])
		error_empty_buff_2(ctx, "Error in input file please rectify", current);
	if (!ft_strncmp(current + i, "NO", 2) || !ft_strncmp("current + i", "N", 1))
		fill_path(current, i, ctx, 1);
	else if (!ft_strncmp(current + i, "SO", 2) || !ft_strncmp("current + i",
			"S", 1))
		fill_path(current, i, ctx, 2);
	else if (!ft_strncmp(current + i, "WE", 2) || !ft_strncmp("current + i",
			"W", 1))
		fill_path(current, i, ctx, 3);
	else if (!ft_strncmp(current + i, "EA", 2) || !ft_strncmp("current + i",
			"E", 1))
		fill_path(current, i, ctx, 4);
	else
		error_empty_buff_2(ctx, "please check input file", current);
}

static void	fill_path(char *current, int pos, t_context *ctx, int direction)
{
	char	*path;
	char	*tmp;
	char	letter;
	int		i;

	pos++;
	letter = fill_second_letter(direction);
	if (current[pos] == letter)
		pos++;
	i = pos;
	while (current[i] && current[i] != '\n')
		i++;
	tmp = ft_substr(current, pos, i - pos);
	if (!tmp)
		error_empty_buff_2(ctx, "malloc error", current);
	path = ft_strtrim(tmp, " ");
	free(tmp);
	if (!path)
		error("malloc_error", NULL);
	fill_path_2(direction, ctx, path, current);
}

static void	fill_path_2(int dir, t_context *ctx, char *path, char *current)
{
	if (dir == 1)
	{
		if (ctx->txt_path.no)
			error_empty_buff_3(ctx, "duplicate directions", path, (void *)current);
		ctx->txt_path.no = path;
	}
	if (dir == 2)
	{
		if (ctx->txt_path.so)
			error_empty_buff_3(ctx, "duplicate directions", path, (void *)current);
		ctx->txt_path.so = path;
	}
	if (dir == 3)
	{
		if (ctx->txt_path.we)
			error_empty_buff_3(ctx, "duplicate directions", path, (void *)current);
		ctx->txt_path.we = path;
	}
	if (dir == 4)
	{
		if (ctx->txt_path.ea)
			error_empty_buff_3(ctx, "duplicate directions", path, (void *)current);
		ctx->txt_path.ea = path;
	}
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
