/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:06:35 by ygille            #+#    #+#             */
/*   Updated: 2025/04/23 14:12:17 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct	s_kin
{
	bool	viewRight;
	bool	viewLeft;
	bool	movUp;
	bool	movDown;
	bool	movRight;
	bool	movLeft;
}	t_kin;

typedef struct	s_min
{

}	t_min;

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
}	t_textures;

typedef struct s_txtinfos
{
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
}	t_txtinfos;

typedef struct s_context
{
	t_mlx		mlx;
	t_textures	txt;
	int		floor[3];
	int		ceiling[3];
	t_txtinfos	txt_infos;
	t_textures	txt_id;
	t_textures	txt_path;
	t_kin		kin;
	t_min		min;
}	t_context;

#endif