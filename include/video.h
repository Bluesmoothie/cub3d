/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:03:24 by ygille            #+#    #+#             */
/*   Updated: 2025/04/22 16:54:36 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIDEO_H
# define VIDEO_H

# define WWIDTH		1024
# define WHEIGHT	1024
# define WTITLE		"CUB3D"

//	video/mlx.c
void	init_video(t_mlx *mlx);
void	deinit_video(t_mlx mlx);

#endif