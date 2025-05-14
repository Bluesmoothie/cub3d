/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:48:19 by sithomas          #+#    #+#             */
/*   Updated: 2025/05/14 14:17:35 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	empty_gnl_buff(int fd)
{
	char	*str;

	while (1)
	{
		str = get_next_line(fd);
		if (str)
			free(str);
		else
			break ;
	}
}

void	error_empty_buff(t_context *ctx, char *message)
{
	empty_gnl_buff(ctx->fd);
	error(message, NULL);
}

void	error_empty_buff_2(t_context *ctx, char *message, char *tofree)
{
	if (tofree)
		free(tofree);
	empty_gnl_buff(ctx->fd);
	error(message, NULL);
}

void	error_empty_buff_3(t_context *ctx, char *message, char *tofree,
		void *tofree2)
{
	if (tofree)
		free(tofree);
	if (tofree2)
		free(tofree2);
	empty_gnl_buff(ctx->fd);
	error(message, NULL);
}

void	error_map(t_context *ctx, char **charmap)
{
	deinit_textures(ctx);
	deinit_video(ctx->mlx);
	free_chartab(charmap);
	close(ctx->fd);
	printf("malloc error");
	exit(0);
}
