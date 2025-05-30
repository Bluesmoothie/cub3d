/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:06:35 by ygille            #+#    #+#             */
/*   Updated: 2025/05/14 10:09:40 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include <stdlib.h>

/*
**	This variables permit texture size adjustement
**	depending on the distance between the player and the texture
*/
typedef struct s_rendering
{
	double	txtstep;
	double	txty;
	int		txtx;
}	t_rendering;

/*
**	All variables needed for computing rays
*/
typedef struct s_raycast
{
	double	cam_angle;
	double	rayx;
	double	rayy;
	double	nextsidex;
	double	nextsidey;
	double	raystepx;
	double	raystepy;
	double	walldist;
	int		halfheight;
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
	double	viewx;
	double	viewy;
}	t_player;

typedef struct s_map
{
	int		**map;
	int		width;
	int		height;
	void	*mmap;
	int		x_r;
	int		y_r;
	int		mmap_width;
	int		mmap_height;
	int		*mmap_img;
	int		bpp;
	int		line_size;
	int		endian;
	int		px;
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
	bool	door;
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
	void	*cd;
}	t_textures;

typedef struct s_txtdata
{
	int		*no;
	int		*so;
	int		*we;
	int		*ea;
	int		*cd;
}	t_txtdata;

typedef struct s_fire
{
	void		*f1;
	void		*f2;
	void		*f3;
	void		*f4;
	void		*f5;
	void		*f6;
	void		*f7;
	void		*f8;	
	int			*f1_img;
	int			*f2_img;
	int			*f3_img;
	int			*f4_img;
	int			*f5_img;
	int			*f6_img;
	int			*f7_img;
	int			*f8_img;
	t_txtinfos	txtinfos;
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
	int			fd;
}	t_context;

#endif