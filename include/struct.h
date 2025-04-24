/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:06:35 by ygille            #+#    #+#             */
/*   Updated: 2025/04/24 14:54:58 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_raycast
{
	double	cameraX;
	double	raydirX;
	double	raydirY;
	double	sidedistX;
	double	sidedistY;
	double	deltadistX;
	double	deltadistY;
	double	walldist;
	int 	lineheight;
	int 	sy;
	int 	ey;
	int 	mapX;
	int 	mapY;
	int 	stepX;
	int 	stepY;
	bool 	side;
}	t_raycast;

typedef struct s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}	t_player;

typedef struct s_map
{
	int		**map;
	int		width;
	int		height;
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

typedef struct s_min
{

}	t_min;

typedef struct s_mlx
{
	void		*id;
	void		*win;
	void		*img;
	void		*img_data;
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
	t_min		min;
	t_map		map;
	t_player	player;
}	t_context;

#endif