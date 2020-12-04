/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:47:35 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/04 15:38:29 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CUB3D_STRUCT_H
#	define CUB3D_STRUCT_H

#	include "cub3d.h"

// map
typedef struct				s_map_resolution
{
    int						R_X;
    int						R_Y;
}							t_map_resolution;

typedef struct				s_map_texure
{
	char					*NO;
	char					*SO;
	char					*WE;
	char					*EA;
}							t_map_texure;

typedef struct				s_map_sprite
{
	char					*S;
}							t_map_sprite;

typedef	struct				s_map_color
{
	int						R;
	int						G;
	int						B;
}							t_map_color;

typedef struct				s_map_map
{
	char					**map;
	char					*buff;
}							t_map_map;

typedef struct				s_map
{
	t_map_resolution		resolution;
	t_map_texure			texure;
	t_map_sprite			sprite;
	t_map_color				f_color;
	t_map_color				c_color;
	t_map_map				map;
}							t_map;

// map chk
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
