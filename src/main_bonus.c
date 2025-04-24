/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:38:48 by ygille            #+#    #+#             */
/*   Updated: 2025/04/24 19:30:51 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_context	ctx;

	init_ctx(&ctx);
	parse(argc, argv, &ctx);
	init_video(&ctx.mlx);
	init_textures(&ctx);
	mlx_mouse_hide(ctx.mlx.id, ctx.mlx.win);
	init_hooks_loops(&ctx);
	exit_call();
	return (EXIT_SUCCESS);
}
