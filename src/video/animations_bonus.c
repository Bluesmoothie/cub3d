/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:41:45 by ygille            #+#    #+#             */
/*   Updated: 2025/04/25 15:49:12 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*choose_txt(t_context *ctx);
static int	calc_ftxtx(t_raycast *rc, t_fire *txt, t_player *player);
static int	trans_pixel(int orig, int txt);

void	render_fire(t_context *ctx, t_raycast rc, int screenx)
{
	const int	*txt = choose_txt(ctx);
	t_rendering	render;

	render.txtstep = 1.0 * ctx->fire.height / rc.lineheight;
	render.txty = (rc.sy - WHEIGHT / 2 + rc.lineheight / 2) * render.txtstep;
	render.y = rc.sy;
	render.txtx = calc_ftxtx(&rc, &ctx->fire, &ctx->player);
	while (render.y <= rc.ey)
	{
		render_pixel(ctx->mlx.img_data,
			trans_pixel(ctx->mlx.img_data[screenx + render.y * WWIDTH],
				txt[render.txtx + (int)render.txty * ctx->fire.width]),
			screenx, render.y);
		render.txty += render.txtstep;
		if ((int)render.txty >= ctx->fire.height)
			render.txty = (double)(ctx->fire.height - 1);
		render.y++;
	}
}

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

static int	calc_ftxtx(t_raycast *rc, t_fire *txt, t_player *player)
{
	double	wallx;
	int		txtx;

	if (!rc->side)
		wallx = player->posy + rc->walldist * rc->raydiry;
	else
		wallx = player->posx + rc->walldist * rc->raydirx;
	wallx -= floor(wallx);
	txtx = (int)(wallx * (double)txt->width);
	if ((!rc->side && rc->raydirx > 0) || (rc->side && rc->raydiry < 0))
		txtx = txt->width - txtx - 1;
	return (txtx);
}

static int	trans_pixel(int orig, int txt)
{
	if (txt == NOCOLOR)
		return (orig);
	return (txt);
}
