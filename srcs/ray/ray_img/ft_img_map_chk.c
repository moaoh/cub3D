/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_map_chk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 07:29:08 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 10:39:36 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray.h"

t_img	*ft_map_wall(t_ray_info *ray_info, t_loop_info *info)
{
	if (info->side == 0)
	{
		if (ray_info->pos_x < info->map.x)
			return (&ray_info->img[1]);
		else
			return (&ray_info->img[2]);
	}
	else
	{
		if (ray_info->pos_y < info->map.y)
			return (&ray_info->img[3]);
		else
			return (&ray_info->img[4]);
	}
}

t_img	*ft_map_sprite(t_ray_info *ray_info)
{
	return (&ray_info->img[5]);
}
