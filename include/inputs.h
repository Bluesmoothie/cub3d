/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:41:57 by ygille            #+#    #+#             */
/*   Updated: 2025/04/25 12:04:03 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

# define XK_MISCELLANY
# define XK_LATIN1

# include <X11/keysymdef.h>
# include <X11/X.h>

//	inputs/keyboard.c
int	keypress_handler(int keycode, t_kin *kin);
int	keyrelease_handler(int keycode, t_kin *kin);

#endif