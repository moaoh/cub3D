/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:01:48 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/09 13:14:23 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RAY_STRUCT_H
#	define RAY_STRUCT_H

#	include "ray.h"

typedef struct		s_pos
{
	int				y;
	int				x;
}					t_pos;

typedef struct		s_dir
{
	int				y;
	int				x;
}					t_dir;

typedef struct		s_plane
{
	int				y;
	int				x;
}					t_plane;

typedef	struct		s_ray
{
	t_pos			pos;
	t_dir			dir;
	t_plane			plane;
}					t_ray;

#	endif