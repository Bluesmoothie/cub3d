/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:41:34 by ygille            #+#    #+#             */
/*   Updated: 2025/04/23 15:04:07 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keypress_handler(int keycode, t_kin *kin)
{
	if (keycode == XK_Escape)
		exit_call();
	else if (keycode == XK_w)
		kin->movup = true;
	else if (keycode == XK_s)
		kin->movdown = true;
	else if (keycode == XK_a)
		kin->movleft = true;
	else if (keycode == XK_d)
		kin->movright = true;
	else if (keycode == XK_Left)
		kin->viewleft = true;
	else if (keycode == XK_Right)
		kin->viewright = true;
	return (0);
}

int	keyrelease_handler(int keycode, t_kin *kin)
{
	if (keycode == XK_w)
		kin->movup = false;
	else if (keycode == XK_s)
		kin->movdown = false;
	else if (keycode == XK_a)
		kin->movleft = false;
	else if (keycode == XK_d)
		kin->movright = false;
	else if (keycode == XK_Left)
		kin->viewleft = false;
	else if (keycode == XK_Right)
		kin->viewright = false;
	return (0);
}
