/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:41:34 by ygille            #+#    #+#             */
/*   Updated: 2025/04/23 12:41:23 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keyPress_handler(int keycode, t_kin *kin)
{
	if (keycode == XK_Escape)
		exit_call();
	else if (keycode == XK_w)
		kin->movUp = true;
	else if (keycode == XK_s)
		kin->movDown = true;
	else if (keycode == XK_a)
		kin->movLeft = true;
	else if (keycode == XK_d)
		kin->movRight = true;
	else if (keycode == XK_KP_Left)
		kin->viewLeft = true;
	else if (keycode == XK_KP_Right)
		kin->viewRight = true;
	return (0);
}

int	keyRelease_handler(int keycode, t_kin *kin)
{
	if (keycode == XK_w)
		kin->movUp = false;
	else if (keycode == XK_s)
		kin->movDown = false;
	else if (keycode == XK_a)
		kin->movLeft = false;
	else if (keycode == XK_d)
		kin->movRight = false;
	else if (keycode == XK_KP_Left)
		kin->viewLeft = false;
	else if (keycode == XK_KP_Right)
		kin->viewRight = false;
	return (0);
}
