/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 23:36:11 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/12 00:27:46 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RAY_H
#	define RAY_H

#	include "../cub3d.h"
#	include "ray_struct.h"

#	define KeyPress 2
#	define KeyRelease 3
#	define ButtonPress 4
#	define ButtonRelease 5

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define K_ESC 53

int		cub3d(t_map map);
int		main_loop(t_ray_info *info);
int		key_press(int key, t_ray_info *info);

#	endif