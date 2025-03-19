/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:02:51 by ygille            #+#    #+#             */
/*   Updated: 2025/03/19 22:42:49 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_video(t_mlx *mlx)
{
	mlx->id = mlx_init();
	if (mlx->id == NULL)
		error(EMINIT);
	mlx->win = mlx_new_window(mlx->id, WHEIGHT, WWIDTH, WTITLE);
	if (mlx->win == NULL)
		error(EMWIN);
}

void	deinit_video(t_mlx mlx)
{
	if (mlx.id)
	{
		if (mlx.img)
			mlx_destroy_image(mlx.id, mlx.img);
		if (mlx.win)
			mlx_destroy_window(mlx.id, mlx.win);
		mlx_destroy_display(mlx.id);
		free(mlx.id);
	}
}
