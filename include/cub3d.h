/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:38:21 by ygille            #+#    #+#             */
/*   Updated: 2025/04/29 15:35:23 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# include "mlx.h"

# include "libft.h"

# include "error.h"
# include "struct.h"
# include "video.h"
# include "parse.h"
# include "inputs.h"

# define PSTEP_SIZE		0.0625
# define CSTEP_SIZE		6.0
# define MCSTEP_SIZE	0.01

enum	e_tiletypes
{
	T_OPENDOOR = -2,
	T_EMPTY = -1,
	T_HALL = 0,
	T_WALL = 1,
	T_PLAYERN = 2,
	T_PLAYERS = 3,
	T_PLAYERE = 4,
	T_PLAYERW = 5,
	T_CLOSEDOOR = 6
};

//	main.c

//	error.c
void	error(char *error, char *arg);
void	display_error(char *error, char *arg);

//	exit.c
void	exit_set_ctx(t_context *ctx);
void	exit_call(void);
void	free_exit(t_context *ctx);
int		destroy_handler(void);

//	init.c
void	init_ctx(t_context *ctx);
void	init_hooks_loops(t_context *ctx);

#endif