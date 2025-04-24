/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:26:12 by ygille            #+#    #+#             */
/*   Updated: 2025/04/24 19:28:29 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	collision_check(t_context *ctx, char op);
static void	mouse_camera_moves(t_context *ctx);

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
	const double	mem = ctx->player.dirx;

	if (ctx->kin.viewright)
	{
		ctx->player.dirx = ctx->player.dirx * cos(CSTEP_SIZE) - ctx->player.diry * sin (CSTEP_SIZE);
		ctx->player.diry = mem * sin(CSTEP_SIZE) + ctx->player.diry * cos(CSTEP_SIZE);
	}
	if (ctx->kin.viewleft)
	{
		ctx->player.dirx = ctx->player.dirx * cos(-CSTEP_SIZE) - ctx->player.diry * sin (-CSTEP_SIZE);
		ctx->player.diry = mem * sin(-CSTEP_SIZE) + ctx->player.diry * cos(-CSTEP_SIZE);
	}
	mouse_camera_moves(ctx);
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
	if (out_of_map(&ctx->map, ctx->player.posx, ctx->player.posy)
		|| ctx->map.map[(int)(ctx->player.posx)][(int)(ctx->player.posy)] != 0)
	{
		ctx->player.posx = x;
		ctx->player.posy = y;
	}
}

static void	mouse_camera_moves(t_context *ctx)
{
	const double	mem = ctx->player.dirx;
	static int		x = 0;
	static int		y = 0;
	double			movx;

	mlx_mouse_get_pos(ctx->mlx.id, ctx->mlx.win, &x, &y);
	movx = (double)(x - WWIDTH / 2);
	if (movx)
		mlx_mouse_move(ctx->mlx.id, ctx->mlx.win, WWIDTH / 2, WHEIGHT / 2);
	if (movx)
	{
		ctx->player.dirx = ctx->player.dirx * cos(-MCSTEP_SIZE * movx) - ctx->player.diry * sin (-MCSTEP_SIZE * movx);
		ctx->player.diry = mem * sin(-MCSTEP_SIZE * movx) + ctx->player.diry * cos(-MCSTEP_SIZE * movx);
	}
}
