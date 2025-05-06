/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:05:04 by ygille            #+#    #+#             */
/*   Updated: 2025/05/06 16:53:04 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Calculate the correct column of the texture to display
*/
int	calc_txtx(t_raycast *rc, t_txtinfos *txt, t_player *player)
{
	double	wallx;
	int		txtx;

	if (rc->side == SIDE_NS)
		wallx = player->posy + rc->walldist * rc->rayy;
	else
		wallx = player->posx + rc->walldist * rc->rayx;
	txtx = (wallx - floor(wallx)) * (double)txt->width;
	if ((rc->side == SIDE_NS && rc->rayx > 0)
		|| (rc->side == SIDE_EW && rc->rayy < 0))
		txtx = txt->width - txtx - 1;
	return (txtx);
}

int	*get_dir(t_raycast *rc, t_txtdata *txt)
{
	int			*result;

	if (rc->side == SIDE_NS)
	{
		if (rc->stepx > 0)
			return (txt->no);
		else
			return (txt->so);
	}
	else
	{
		if (rc->stepy > 0)
			return (txt->we);
		else
			return (txt->ea);
	}
	return (result);
}

bool	out_of_map(t_map *map, int x, int y)
{
	return (x >= map->height || y >= map->width || x < 0 || y < 0);
}

t_rendering	calc_render_params(t_txtinfos *infos, t_player *player,
	t_raycast *rc)
{
	t_rendering	render;

	render.txtstep = 1.0 * infos->height / rc->lineheight;
	render.txty = (rc->sy - WHEIGHT / 2 + rc->lineheight / 2) * render.txtstep;
	render.txtx = calc_txtx(rc, infos, player);
	return (render);
}
