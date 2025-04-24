/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:03:24 by ygille            #+#    #+#             */
/*   Updated: 2025/04/23 19:01:59 by ygille           ###   ########.fr       */
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

//	video/player.c
void	player_moves(t_context *ctx);
void	camera_moves(t_context *ctx);

//	video/mlx.c
void	init_video(t_mlx *mlx);
void	deinit_video(t_mlx mlx);

//	video/render.c
int		renderer(t_context *ctx);
void	render_pixel(int *frame, int color, int x, int y);


void	render_test(t_context *ctx);

#endif