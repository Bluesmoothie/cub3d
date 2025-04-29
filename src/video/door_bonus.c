/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:35:48 by ygille            #+#    #+#             */
/*   Updated: 2025/04/29 15:49:54 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	get_player_dir(t_player *player);
static void	try_interact(t_map *map, int x, int y);

void	render_door(t_context *ctx, t_raycast rc, int screenx)
{
	const int	*txt = ctx->txt.cd;
	t_rendering	render;

	render.txtstep = 1.0 * ctx->txt_infos.height / rc.lineheight;
	render.txty = (rc.sy - WHEIGHT / 2 + rc.lineheight / 2) * render.txtstep;
	render.y = rc.sy;
	render.txtx = calc_txtx(&rc, &ctx->txt_infos, &ctx->player);
	while (render.y <= rc.ey)
	{
		render_pixel(ctx->mlx.img_data,
			trans_pixel(ctx->mlx.img_data[screenx + render.y * WWIDTH],
				txt[render.txtx + (int)render.txty * ctx->txt_infos.width]),
			screenx, render.y);
		render.txty += render.txtstep;
		if ((int)render.txty >= ctx->txt_infos.height)
			render.txty = (double)(ctx->txt_infos.height - 1);
		render.y++;
	}
}

/*
**	Verif if player watch a door and open it if he interact with it
*/
void	interact_door(t_context *ctx)
{
	const char	dir = get_player_dir(&ctx->player);

	if (dir == 'n')
		try_interact(&ctx->map, (int)ctx->player.posx - 1,
			(int)ctx->player.posy);
	else if (dir == 's')
		try_interact(&ctx->map, (int)ctx->player.posx + 1,
			(int)ctx->player.posy);
	else if (dir == 'e')
		try_interact(&ctx->map, (int)ctx->player.posx,
			(int)ctx->player.posy + 1);
	else
		try_interact(&ctx->map, (int)ctx->player.posx,
			(int)ctx->player.posy - 1);
}

static char	get_player_dir(t_player *player)
{
	if (fabs(player->dirx) >= 0.5)
	{
		if (player->dirx < 0)
			return ('n');
		else
			return ('s');
	}
	else
	{
		if (player->diry < 0)
			return ('w');
		else
			return ('e');
	}
}

static void	try_interact(t_map *map, int x, int y)
{
	if (y >= map->width || x >= map->height || x < 0 || y < 0)
		return ;
	if (map->map[x][y] == T_OPENDOOR)
		map->map[x][y] = T_CLOSEDOOR;
	else if (map->map[x][y] == T_CLOSEDOOR)
		map->map[x][y] = T_OPENDOOR;
}
