/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:11:14 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/23 13:53:42 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_av(char **av);
static void	fill_paths(int fd, t_textures *paths);
static void	ceiling_floor(char *current, int pos, t_textures *paths);

void	parse(int ac, char **av, t_context *ctx)
{
	int			fd;
	
	if (ac != 2)
		error("wrong number of arguments");
	fd = check_av(av);
	ft_bzero(&ctx->txt_path, 4 * sizeof(void *));
	fill_paths(fd, &ctx->txt_path);
}

static int	check_av(char **av)
{
	int	i;
	int	fd;
	
	i = 0;
	if (!av[0] || !av[0][0])
		error("empty argument");
	while (av[0][i])
		i++;
	if (i < 3)
		error("wrong argument format");
	i -= 3;
	// if (ft_strncmp(av[1] + i, ".cub", 3))
	// 	error("description file must end with .cub");
	fd = open(av[1], O_RDWR);
	if (fd == -1)
		error("open fail, please check file name and permissions");
	return (fd);
}

static void	fill_paths(int fd, t_textures *paths)
{
	char		*current;
	int			i;
	int			j;

	j = 0;
	while (1)
	{
		current = get_next_line(fd);
		if (!current || !current[0])
			error("please check input file");
		i = 0;
		while (current[i] == ' ')
			i++;
		if (current[i] == '\n')
			continue ;
		if (j++ < 4)
			directions(current, i, paths);
		else if (j < 7)
			ceiling_floor(current, i, paths);
		free(current);
		if (j == 7)
			break ;
	}
}

static void	ceiling_floor(char *current, int pos, t_textures *paths)
{
	if (current[pos] == 'C')
		ceiling(current, pos, paths, 2);
	else if (current[pos] == 'F')
		ceiling(current, pos, paths, 1);
	else
		error("problem in floor or ceiling color");
}

// floodfill
