/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:38:21 by ygille            #+#    #+#             */
/*   Updated: 2025/03/21 18:14:16 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <X11/keysymdef.h>

# include "mlx.h"

# include "libft.h"

# include "error.h"
# include "struct.h"
# include "video.h"

//	main.c

//	error.c
void	error(char *error);
void	display_error(char *error);

//	exit.c
void	exit_set_ctx(t_context *ctx);
void	exit_call(void);
void	free_exit(t_context *ctx);

//	init.c
void	init_ctx(t_context *ctx);

#endif