/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:26:12 by ygille            #+#    #+#             */
/*   Updated: 2025/04/29 15:50:17 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	collision_check(t_context *ctx, char op);
static void	apply_rot(t_player *p, double step_size);

/*
**	Compute player moves
*/
void	player_moves(t_context *ctx)
{
	collision_check(ctx, COL_STORE);
	if (ctx->kin.movdown)
	{
		ctx->player.posx -= ctx->player.dirx * PSTEP_SIZE;
		ctx->player.posy -= ctx->player.diry * PSTEP_SIZE;
	}
	if (ctx->kin.movup)
	{
		ctx->player.posx += ctx->player.dirx * PSTEP_SIZE;
		ctx->player.posy += ctx->player.diry * PSTEP_SIZE;
	}
	if (ctx->kin.movleft)
	{
		ctx->player.posx -= ctx->player.diry * PSTEP_SIZE;
		ctx->player.posy += ctx->player.dirx * PSTEP_SIZE;
	}
	if (ctx->kin.movright)
	{
		ctx->player.posx += ctx->player.diry * PSTEP_SIZE;
		ctx->player.posy -= ctx->player.dirx * PSTEP_SIZE;
	}
	collision_check(ctx, COL_CHECK);
}

void	camera_moves(t_context *ctx)
{
	static int		x = 0;
	static int		y = 0;
	double			movx;

	mlx_mouse_get_pos(ctx->mlx.id, ctx->mlx.win, &x, &y);
	movx = (double)(x - WWIDTH / 2);
	if (movx)
	{
		mlx_mouse_move(ctx->mlx.id, ctx->mlx.win, WWIDTH / 2, WHEIGHT / 2);
		apply_rot(&ctx->player, -MCSTEP_SIZE * movx);
	}
	if (ctx->kin.viewright)
		apply_rot(&ctx->player, CSTEP_SIZE);
	if (ctx->kin.viewleft)
		apply_rot(&ctx->player, -CSTEP_SIZE);
}

static void	apply_rot(t_player *p, double step_size)
{
	const double	mem = p->dirx;

	p->dirx = p->dirx * cos(step_size) - p->diry * sin (step_size);
	p->diry = mem * sin(step_size) + p->diry * cos(step_size);
}

static void	collision_check(t_context *ctx, char op)
{
	static double	x;
	static double	y;

	if (op == COL_STORE)
	{
		x = ctx->player.posx;
		y = ctx->player.posy;
		return ;
	}
	if (out_of_map(&ctx->map, ctx->player.posx, y)
		|| (ctx->map.map[(int)(ctx->player.posx)][(int)(y)] != T_HALL
		&& ctx->map.map[(int)(ctx->player.posx)][(int)(y)] != T_OPENDOOR))
		ctx->player.posx = x;
	if (out_of_map(&ctx->map, x, ctx->player.posy)
		|| (ctx->map.map[(int)(x)][(int)(ctx->player.posy)] != T_HALL
		&& ctx->map.map[(int)(x)][(int)(ctx->player.posy)] != T_OPENDOOR))
		ctx->player.posy = y;
}
