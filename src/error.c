/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:17:32 by ygille            #+#    #+#             */
/*   Updated: 2025/04/23 14:00:19 by sithomas         ###   ########.fr       */
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

void	malloc_error_txt(t_textures *txts)
{
	if (txts->EA)
		free(txts->EA);
	if (txts->NO)
		free(txts->NO);
	if (txts->WE)
		free(txts->WE);
	if (txts->SO)
		free(txts->SO);
	error("malloc error");
}