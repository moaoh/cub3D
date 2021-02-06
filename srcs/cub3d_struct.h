/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:47:35 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/06 13:06:38 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CUB3D_STRUCT_H
#	define CUB3D_STRUCT_H

/*
** sprite_count -------------------------------------------
*/

typedef struct				s_sprite_pos
{
	double					y;
	double					x;
	char					type;
}							t_sprite_pos;

/*
** map ----------------------------------------------------
*/

typedef struct				s_map_screen
{
	int						x;
	int						y;
}							t_map_screen;

typedef struct				s_map_texture
{
	char					*no;
	char					*so;
	char					*we;
	char					*ea;
}							t_map_texture;

typedef struct				s_map_sprite
{
	char					*s;
}							t_map_sprite;

typedef	struct				s_map_color
{
	int						r;
	int						g;
	int						b;
}							t_map_color;

typedef struct				s_map_map
{
	char					**map;
	char					*buff;
}							t_map_map;

typedef struct				s_map_player
{
	char					dir;
	int						y;
	int						x;
}							t_map_player;

typedef struct				s_map
{
	t_map_screen			screen;
	t_map_texture			texture;
	t_map_sprite			sprite;
	t_map_color				f_color;
	t_map_color				c_color;
	t_map_map				map;
	t_map_player			player;
	t_sprite_pos			*sp_pos;
	int						sp_count;
	int						save_bool;
}							t_map;

/*
** map chk ------------------------------------------------
*/

typedef struct				s_cub_info
{
	int						r;
	int						no;
	int						so;
	int						we;
	int						ea;
	int						s;
	int						f;
	int						c;
}							t_cub_info;

#	endif
