/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:17:32 by ygille            #+#    #+#             */
/*   Updated: 2025/04/22 17:21:24 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Display error and exit properly
*/
void	error(char *error, char *arg)
{
	display_error(error, arg);
	exit_call();
}

/*
**	Display an error
*/
void	display_error(char *error, char *arg)
{
	printf("Error\n %s", error);
	if (arg)
		printf(" : %s\n", arg);
}
