/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:01:48 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/31 20:57:55 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RAY_STRUCT_H
#	define RAY_STRUCT_H

#	include "ray.h"
#	include "../cub3d.h"

/*
** img ----------------------------------------------------
*/

typedef struct			s_img
{
	void				*img;
	int					*data;
	int					size_l;
	int					bpp;
	int					endian;
	int					width;
	int					height;
	char				type;
}						t_img;

/*
** t_img_calc ---------------------------------------------
*/

typedef struct			s_img_calc
{
	double				obj_x;
	double				obj_y;
	int					img_x;
	int					img_y;
	int					color;
}						t_img_calc;

/*
** cub3d_info ---------------------------------------------
*/

typedef struct		s_ray_texture
{
	char			*EA;
	char			*WE;
	char			*SO;
	char			*NO;
	char			*S;
}					t_ray_texture;


typedef struct		s_ray_info
{
	int				screen_Y;
	int				screen_X;
	double			pos_Y;
	double			pos_X;
	double			dir_Y;
	double			dir_X;
	double			plane_Y;
	double			plane_X;
	void			*mlx;
	void			*win;
	char			**map;
	t_map_color		f_color;
	t_map_color		c_color;

	double			moveSpeed;
	double			rotSpeed;
	
	double			oldDirX;
	double			oldPlaneX;

	int				img_x;
	t_ray_texture	texture;
	t_img			img[10];
	int				save_bool;
}					t_ray_info;

/*
** loop ---------------------------------------------------
*/

typedef	struct			s_loop_ray
{
	double				X;
	double				Y;
}						t_loop_ray;

typedef	struct			s_loop_sideDist
{
	double				X;
	double				Y;
}						t_loop_sideDist;

typedef struct			s_loop_map
{
	int					Y;
	int					X;	
}						t_loop_map;

typedef struct			s_loop_deltaDist
{
	double				Y;
	double				X;
}						t_loop_deltaDist;

typedef struct			s_loop_step
{
	int					Y;
	int					X;
}						t_loop_step;

typedef struct			s_loop_info
{
	double				cameraX;
	t_loop_ray			ray;
	t_loop_sideDist		sideDist;
	t_loop_map			map;
	t_loop_deltaDist	deltaDist;
	t_loop_step			step;
	int					side;
	double				perpWallDist;
	int					lineHeight;
	int					drawStart;
	int					drawEnd;
	int					color;
}						t_loop_info;

#	endif