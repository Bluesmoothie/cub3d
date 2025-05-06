/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:41:45 by ygille            #+#    #+#             */
/*   Updated: 2025/05/06 15:54:07 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*choose_txt(t_context *ctx);

void	render_fire(t_context *ctx, t_raycast rc, int screenx)
{
	const int	*txt = choose_txt(ctx);
	t_rendering	render;

	render = calc_render_params(&ctx->fire.txtinfos, &ctx->player, &rc);
	while (rc.sy <= rc.ey)
	{
		render_pixel(ctx->mlx.img_data,
			trans_pixel(ctx->mlx.img_data[screenx + rc.sy * WWIDTH],
				txt[render.txtx + (int)render.txty * ctx->fire.txtinfos.width]),
			screenx, rc.sy);
		render.txty += render.txtstep;
		if ((int)render.txty >= ctx->fire.txtinfos.height)
			render.txty = (double)(ctx->fire.txtinfos.height - 1);
		rc.sy++;
	}
}

/*
**	Choose a different texture depending on frame number to play the animation
*/
static int	*choose_txt(t_context *ctx)
{
	const int	choice = (ctx->frame / 3) % 8;

	if (choice == 0)
		return (ctx->fire.f1_img);
	if (choice == 1)
		return (ctx->fire.f2_img);
	if (choice == 2)
		return (ctx->fire.f3_img);
	if (choice == 3)
		return (ctx->fire.f4_img);
	if (choice == 4)
		return (ctx->fire.f5_img);
	if (choice == 5)
		return (ctx->fire.f6_img);
	if (choice == 6)
		return (ctx->fire.f7_img);
	return (ctx->fire.f8_img);
}
