/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:03:24 by ygille            #+#    #+#             */
/*   Updated: 2025/04/29 14:07:16 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIDEO_H
# define VIDEO_H

# define WWIDTH 2048
# define WHEIGHT 1024
# define PIXELMAP 10
# define WTITLE "CUB3D"

# include "struct.h"

enum	e_col_codes
{
	COL_STORE,
	COL_CHECK
};

//	video/color.c
int		get_bgcolor(int color[3]);
int		get_color(int t, int r, int g, int b);

//	video/player.c
void	player_moves(t_context *ctx);
void	camera_moves(t_context *ctx);

//	video/mlx.c
void	init_video(t_mlx *mlx);
void	deinit_video(t_mlx mlx);

//	video/raycasting.c
void	ray_cast(t_context *ctx);

//	video/render.c
int		renderer(t_context *ctx);
void	render_pixel(int *frame, int color, int x, int y);
void	render_texture(t_context *ctx, t_raycast rc, int screenx);

//	video/textures.c
void	init_textures(t_context *ctx);
void	deinit_textures(t_context *ctx);

//	video/utils.c
int		calc_txtx(t_raycast *rc, t_txtinfos *txt, t_player *player);
int		*get_dir(t_raycast *rc, t_txtdata *txt);
bool	out_of_map(t_map *map, int x, int y);

//	video/animation_bonus.c
void	render_fire(t_context *ctx, t_raycast rc, int screenx);

//	video/texture_bonus2.c
void	init_fire(t_context *ctx);

//	video/texture_bonus3.c
void	deinit_fire(t_context *ctx);
void	init_mmap(t_context *ctx);
void	deinit_mmap(t_context *ctx);

//	video/minimap_bonus.c
void	render_map(t_context *ctx);

#endif