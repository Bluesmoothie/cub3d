/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:29:39 by sithomas          #+#    #+#             */
/*   Updated: 2025/05/14 14:17:53 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include "libft.h"

//	parse.c
void	parse(int ac, char **av, t_context *ctx);

// directions.c
void	directions(char *current, int i, t_context *cxt);

//	parse_utils.c
int		forward_char(char *str, char sep);
char	**ft_realloc_tab(char **tab, int max, int size);
void	check_first_and_last_line(t_map *map);
void	free_map(t_map *map);
void	free_chartab(char **chartab);

//	parse_utils_2.c
void	empty_gnl_buff(int fd);
void	error_empty_buff(t_context *ctx, char *message);
void	error_empty_buff_2(t_context *ctx, char *message, char *tofree);
void	error_empty_buff_3(t_context *ctx, char *message, char *tofree,
			void *tofree2);
void	error_map(t_context *ctx, char **charmap);

//	ceiling_floor.c
void	ceiling(t_context *ctx, char *current, int pos, int *tab);

//	parse_map.c
void	fill_map(t_context *ctx);

//	parse_map_2.c
int		max_height(char **tab);
int		max_width(char **tab);
void	fill_int_tab(t_context *ctx, char **charmap);

//	check_map.c
void	check_map(t_map *map);

//	init_player.c
void	init_player(t_context *ctx);