/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:41:57 by ygille            #+#    #+#             */
/*   Updated: 2025/04/22 17:54:26 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

//	inputs/keyboard.c
int	keyPress_handler(t_kin *kin);
int	keyRelease_handler(t_min *kin);

//	inputs/mouse.c
int	mouse_handler(t_min *min);

#endif