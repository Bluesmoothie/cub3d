/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:48:46 by ygille            #+#    #+#             */
/*   Updated: 2025/04/23 14:59:49 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "video.h"

int	get_bgcolor(int color[3])
{
	return (get_color(0, color[0], color[1], color[2]));
}

int	get_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
