/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 23:36:11 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/12 03:22:46 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RAY_H
#	define RAY_H

#	include "../cub3d.h"
#	include "ray_struct.h"
#	include "key_press.h"

int		cub3d(t_map map);
int		main_loop(t_ray_info *info);
int		key_press(int key, t_ray_info *info);

#	endif