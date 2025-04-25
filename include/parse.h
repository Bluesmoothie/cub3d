/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:29:39 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/25 12:03:45 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "cub3d.h"

//	parse.c
void	parse(int ac, char **av, t_context *ctx);

// directions.c 
void	directions(char *current, int i, t_textures *txt);

//	parse_utils.c
int		forward_char(char *str, char sep);
char	**ft_realloc_tab(char **tab, int max, int size);
void	check_first_and_last_line(t_map *map);
void	free_map(t_map *map);
void	free_chartab(char **chartab);

//	ceiling_floor.c
void	ceiling(char *current, int pos, int *tab);

//	parse_map.c
void	fill_map(int fd, t_context *ctx);

//	parse_map_2.c
int		max_height(char **tab);
int		max_width(char **tab);
void	fill_int_tab(t_context *ctx, char **charmap);

//	check_map.c
void	check_map(t_map *map);

//	init_player.c
void	init_player(t_context *ctx);