/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:14:28 by ygille            #+#    #+#             */
/*   Updated: 2025/03/19 22:43:20 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define EMWIN	"mlx new window failed"
# define EMINIT	"mlx init failed"

enum	e_ecodes
{
	SUCCESS = 0,
	CALL,
	STORE
};

#endif