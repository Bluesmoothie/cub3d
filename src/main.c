/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:38:48 by ygille            #+#    #+#             */
/*   Updated: 2025/03/19 22:42:45 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_context	ctx;

	(void)argc;
	(void)argv;
	init_ctx(&ctx);
	init_video(&ctx.mlx);
	exit_call();
	return (EXIT_SUCCESS);
}
