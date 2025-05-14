/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:11:14 by sithomas          #+#    #+#             */
/*   Updated: 2025/05/14 14:28:12 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_av(char **av);
static void	fill_paths(t_context *ctx);
static void	ceiling_floor(char *current, int pos, t_context *ctx);
static void	find_ratio(t_map *map);

void	parse(int ac, char **av, t_context *ctx)
{
	if (ac != 2)
		error("wrong number of arguments", NULL);
	ctx->fd = check_av(av);
	fill_paths(ctx);
	fill_map(ctx);
	check_map(&ctx->map);
	init_player(ctx);
	find_ratio(&ctx->map);
	empty_gnl_buff(ctx->fd);
}

static int	check_av(char **av)
{
	int	i;
	int	fd;

	i = 0;
	if (!av[1] || !av[1][0])
		error("empty argument", NULL);
	while (av[1][i])
		i++;
	if (i < 3)
		error("wrong argument format", NULL);
	i -= 3;
	if (ft_strncmp(av[1] + i - 1, ".cub", 4))
		error("description file must end with .cub", NULL);
	fd = open(av[1], O_RDWR);
	if (fd == -1)
		error("open fail, please check file name and permissions", NULL);
	return (fd);
}

static void	fill_paths(t_context *ctx)
{
	char	*current;
	int		i;
	int		j;

	j = 0;
	while (j != 6)
	{
		current = get_next_line(ctx->fd);
		if (!current || !current[0])
			error_empty_buff_2(ctx, "please check input file", current);
		i = 0;
		while (current[i] == ' ')
			i++;
		if (current[i] == '\n')
		{
			free(current);
			continue ;
		}
		if (j++ < 4)
			directions(current, i, ctx);
		else if (j < 7)
			ceiling_floor(current, i, ctx);
		free(current);
	}
}

static void	ceiling_floor(char *current, int pos, t_context *ctx)
{
	if (current[pos] == 'C')
		ceiling(ctx, current, pos, ctx->ceiling);
	else if (current[pos] == 'F')
		ceiling(ctx, current, pos, ctx->floor);
	else
		error_empty_buff_2(ctx, "problem in floor or ceiling color", current);
}

static void	find_ratio(t_map *map)
{
	map->px = 0;
	while ((map->width * map->px < WWIDTH / 4) && (map->height
			* map->px < WHEIGHT / 3))
		map->px++;
	map->x_r = 1;
	map->y_r = 1;
	map->mmap_height = map->height;
	map->mmap_width = map->width;
	if (map->height > WHEIGHT >> 2)
	{
		map->x_r = 1 + map->height / (WHEIGHT >> 2);
		map->mmap_height = map->height / map->x_r;
	}
	if (map->width > WWIDTH >> 2)
	{
		map->y_r = 1 + map->width / (WWIDTH >> 2);
		map->mmap_width = map->width / map->y_r;
	}
}
