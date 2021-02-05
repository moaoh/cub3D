/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:01:48 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 10:41:28 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RAY_STRUCT_H
#	define RAY_STRUCT_H

#	include "ray.h"
#	include "../cub3d.h"

/*
** sprite -------------------------------------------------
*/

typedef struct			s_sprite_info
{
	double				sprite_y;
	double				sprite_x;
	double				inv_det;
	double				transform_y;
	double				transform_x;
	int					sprite_screen_x;
	int					v_move_screen;
	int					sprite_height;
	int					draw_start_y;
	int					draw_end_y;
	int					sprite_width;
	int					draw_start_x;
	int					draw_end_x;
	int					tex_x;
	int					tex_y;
	int					d;
}						t_sprite_info;

typedef struct			s_dist_sprite
{
	double				sp_dist;
}						t_dist_sprite;

typedef struct			s_sprite_pwd
{
	int					*sprite_order;
	double				*sprite_distance;
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

typedef struct			s_ray_texture
{
	char				*ea;
	char				*we;
	char				*so;
	char				*no;
	char				*s;
}						t_ray_texture;

typedef struct			s_ray_info
{
	int					screen_y;
	int					screen_x;
	double				pos_y;
	double				pos_x;
	double				dir_y;
	double				dir_x;
	double				plane_y;
	double				plane_x;
	void				*mlx;
	void				*win;
	char				**map;
	t_map_color			f_color;
	t_map_color			c_color;

	double				move_speed;
	double				rot_speed;

	double				old_dir_x;
	double				old_plane_x;

	int					img_x;
	t_ray_texture		texture;
	t_img				img[10];
	int					save_bool;

	t_sprite_pos		*sp_pos;
	t_sprite_pwd		sp_pwd;
	int					sp_count;
	double				*sp_dist;
}						t_ray_info;

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
	double				x;
	double				y;
}						t_loop_ray;

typedef	struct			s_loop_side_dist
{
	double				x;
	double				y;
}						t_loop_side_dist;

typedef struct			s_loop_map
{
	int					y;
	int					x;
}						t_loop_map;

typedef struct			s_loop_delta_dist
{
	double				y;
	double				x;
}						t_loop_delta_dist;

typedef struct			s_loop_step
{
	int					y;
	int					x;
}						t_loop_step;

typedef struct			s_loop_info
{
	double				camera_x;
	t_loop_ray			ray;
	t_loop_side_dist	side_dist;
	t_loop_map			map;
	t_loop_delta_dist	delta_dist;
	t_loop_step			step;
	int					side;
	double				perp_wall_dist;
	int					line_height;
	int					draw_start;
	int					draw_end;
	int					color;
	t_img_calc			calc;
}						t_loop_info;

#	endif
