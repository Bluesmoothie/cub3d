/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:17:32 by ygille            #+#    #+#             */
/*   Updated: 2025/03/19 22:42:41 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(char *error)
{
	display_error(error);
	exit_call();
}

void	display_error(char *error)
{
	printf("Error : %s\n", error);
}
