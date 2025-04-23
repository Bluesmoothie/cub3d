/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:29:39 by sithomas          #+#    #+#             */
/*   Updated: 2025/04/23 14:19:45 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "cub3d.h"

//	parse.c
void	parse(int ac, char **av, t_context *ctx);

// directions.c 
void directions(char *current, int i, t_textures *txt);

//	parse_utils.c
int	forward_char(char *str, char sep);

//	ceiling_floor.c
void ceiling(char *current, int pos, int *tab);

