/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:17:32 by ygille            #+#    #+#             */
/*   Updated: 2025/05/16 16:05:37 by sithomas         ###   ########.fr       */
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
	printf("Error\n%s\n", error);
	if (arg)
		printf(" : %s\n", arg);
}
