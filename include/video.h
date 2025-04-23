/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:03:24 by ygille            #+#    #+#             */
/*   Updated: 2025/04/23 15:01:05 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIDEO_H
# define VIDEO_H

# define WWIDTH		2048
# define WHEIGHT	1024
# define WTITLE		"CUB3D"

# include "struct.h"

//	video/color.c
int		get_bgcolor(int color[3]);
int		get_color(int t, int r, int g, int b);

//	video/mlx.c
void	init_video(t_mlx *mlx);
void	deinit_video(t_mlx mlx);

//	video/render.c
int		renderer(t_context *ctx);

#endif