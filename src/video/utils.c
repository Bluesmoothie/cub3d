/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:05:04 by ygille            #+#    #+#             */
/*   Updated: 2025/04/24 16:54:43 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calc_txtx(t_raycast *rc, t_txtinfos *txt, t_player *player)
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

int	*get_dir(t_raycast *rc, t_txtdata *txt)
{
	int			*result;

	if(!rc->side)
	{
		if (rc->stepx > 0)
			return (txt->so);
		else
			return (txt->no);
	}
	else
	{
		if (rc->stepy > 0)
			return (txt->ea);
		else
			return (txt->we);
	}
	return (result);
}


