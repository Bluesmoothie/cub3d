/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:38:21 by ygille            #+#    #+#             */
/*   Updated: 2025/04/23 12:36:24 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>

# include "mlx.h"

# include "libft.h"

# include "error.h"
# include "struct.h"
# include "video.h"
# include "inputs.h"

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
void	init_textures(t_context *ctx);
void	deinit_textures(t_context *ctx);

#endif