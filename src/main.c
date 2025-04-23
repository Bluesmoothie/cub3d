/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:38:48 by ygille            #+#    #+#             */
/*   Updated: 2025/04/23 14:10:10 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_context	ctx;

	init_ctx(&ctx);
	init_video(&ctx.mlx);
	parse(argc, argv, &ctx);
	// init_textures(&ctx);
	init_hooks_loops(&ctx);
	exit_call();
	return (EXIT_SUCCESS);
}
