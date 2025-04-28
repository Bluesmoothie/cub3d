/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:06:35 by ygille            #+#    #+#             */
/*   Updated: 2025/04/28 14:51:20 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct s_rendering
{
	double	txtstep;
	double	txty;
	int		y;
	int		txtx;
}	t_rendering;

typedef struct s_raycast
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	walldist;
	int		lineheight;
	int		sy;
	int		ey;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	bool	side;
}	t_raycast;

typedef struct s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
}	t_player;

typedef struct s_map
{
	int		**map;
	int		width;
	int		height;
	void	*mmap;
	int		*mmap_img;
}	t_map;

typedef struct s_txtinfos
{
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
}	t_txtinfos;

typedef struct s_kin
{
	bool	viewright;
	bool	viewleft;
	bool	movup;
	bool	movdown;
	bool	movright;
	bool	movleft;
}	t_kin;

typedef struct s_mlx
{
	void		*id;
	void		*win;
	void		*img;
	int			*img_data;
	t_txtinfos	screen;
}	t_mlx;

typedef struct s_textures
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}	t_textures;

typedef struct s_txtdata
{
	int		*no;
	int		*so;
	int		*we;
	int		*ea;
}	t_txtdata;

typedef struct s_fire
{
	void	*f1;
	void	*f2;
	void	*f3;
	void	*f4;
	void	*f5;
	void	*f6;
	void	*f7;
	void	*f8;	
	int		*f1_img;
	int		*f2_img;
	int		*f3_img;
	int		*f4_img;
	int		*f5_img;
	int		*f6_img;
	int		*f7_img;
	int		*f8_img;
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
}	t_fire;

typedef struct s_context
{
	t_mlx		mlx;
	t_txtdata	txt;
	t_textures	txt_id;
	t_textures	txt_path;
	int			floor[3];
	int			ceiling[3];
	t_txtinfos	txt_infos;
	t_kin		kin;
	t_map		map;
	t_player	player;
	t_fire		fire;
	size_t		frame;
}	t_context;

#endif