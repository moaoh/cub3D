/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:01:48 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/03 08:01:23 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RAY_STRUCT_H
#	define RAY_STRUCT_H

#	include "ray.h"
#	include "../cub3d.h"

/*
** sprite -------------------------------------------------
*/

typedef struct 			s_sprite_info
{
	double				spriteY;
	double				spriteX;
	double				invDet;
	double				transformY;
	double				transformX;
	int					spriteScreenX;
	int					vMoveScreen;
	int					spriteHeight;
	int					drawStartY;
	int					drawEndY;
	int					spriteWidth;
	int					drawStartX;
	int					drawEndX;
}						t_sprite_info;

typedef struct			s_dist_sprite
{
	double				SP_dist;
}						t_dist_sprite;


typedef struct 			s_sprite_pwd
{
	int					*spriteOrder;
	double				*spriteDistance;
}						t_sprite_pwd;

typedef struct			s_pair
{
	double				first;
	int					second;
}						t_pair;

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
	
	t_sprite_pos	*SP_pos;
	t_sprite_pwd	SP_pwd;
	int				SP_count;
	double			*SP_dist;
}					t_ray_info;

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
	t_img_calc			calc;
}						t_loop_info;

#	endif