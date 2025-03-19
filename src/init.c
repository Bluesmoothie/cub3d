/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:19:51 by ygille            #+#    #+#             */
/*   Updated: 2025/03/19 22:42:43 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ctx(t_context *ctx)
{
	ctx->mlx.id = NULL;
	ctx->mlx.win = NULL;
	ctx->mlx.img = NULL;
	ctx->mlx.img_data = NULL;
	exit_set_ctx(ctx);
}
