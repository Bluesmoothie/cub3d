/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:14:28 by ygille            #+#    #+#             */
/*   Updated: 2025/04/29 15:43:29 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

//Mlx errors
# define EMWIN			"Mlx new window failed"
# define EMINIT			"Mlx init failed"
# define EMNEWIMAGE		"Mlx new image failed"
# define EMGETDATA		"Mlx get data addr failed"

//Textures errors
# define ETLOAD			"Failed to load"
# define ETSIZE			"All textures must be the same size"

enum	e_ecodes
{
	SUCCESS = 0,
	CALL,
	STORE
};

#endif