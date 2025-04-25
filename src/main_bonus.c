/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:38:48 by ygille            #+#    #+#             */
/*   Updated: 2025/04/25 13:41:27 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_int.h"
#include <X11/extensions/Xfixes.h>

int	main(int argc, char **argv)
{
	t_context	ctx;
	t_xvar		*mlx;
	t_win_list	*win;

	init_ctx(&ctx);
	parse(argc, argv, &ctx);
	init_video(&ctx.mlx);
	init_textures(&ctx);
	mlx = (t_xvar *)ctx.mlx.id;
	win = (t_win_list *)ctx.mlx.win;
	XFixesHideCursor(mlx->display, win->window);
	init_hooks_loops(&ctx);
	exit_call();
	return (EXIT_SUCCESS);
}
