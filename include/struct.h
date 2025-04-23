/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:06:35 by ygille            #+#    #+#             */
/*   Updated: 2025/04/23 11:21:29 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_mlx
{
	void	*id;
	void	*win;
	void	*img;
	void	*img_data;
}	t_mlx;

typedef struct s_textures
{
	void	*NO;
	void	*SO;
	void	*WE;
	void	*EA;
	int		floor[3];
	int		ceiling[3];
}	t_textures;

typedef struct s_context
{
	t_mlx		mlx;
	t_textures	txt;
	t_textures	txt_path;
}	t_context;

#endif