/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:39:35 by ygille            #+#    #+#             */
/*   Updated: 2025/04/23 12:56:18 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	debug_inputs(t_context *ctx)
{
	if (ctx->kin.movDown)
		printf("Currently moving Down\n");
	if (ctx->kin.movUp)
		printf("Currently moving Up\n");
	if (ctx->kin.movLeft)
		printf("Currently moving Left\n");
	if (ctx->kin.movRight)
		printf("Currently moving Right\n");
	if (ctx->kin.viewLeft)
		printf("Currently watching Left\n");
	if (ctx->kin.viewRight)
		printf("Currently watching Right\n");
}

int	renderer(t_context *ctx)
{
	static size_t	timer = 0;
	static size_t	frame = 0;

	if (!(timer % 200))
	{
		frame++;
		// printf("Rendering frame %zu timer %zu\n", frame, timer);
		debug_inputs(ctx);
	}
	return (timer++);
}
