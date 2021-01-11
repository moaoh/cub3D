/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 07:08:18 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/12 07:48:43 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CUB2D_STRUCT_H
#	define CUB2D_STRUCT_H

#	include "cub2d.h"
#	include "../cub3d.h"


typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_cub2d_info
{
	void		*mlx;
	void		*win;
	t_img		img;
	char		**map;
}				t_cub2d_info;

#	endif