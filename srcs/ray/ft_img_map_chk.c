/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_map_chk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 07:29:08 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/04 07:16:14 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

// 유저의 현재위치와 바라보고있는 방향을 기준으로 판단.
// 방향에 따라 알맞는 img 반환.
t_img	*ft_map_wall(t_ray_info *ray_info, t_loop_info *info)
{
	// 동서
	// w = x --
	// e = x ++
	if (info->side == 0)
	{
		// 남 s
		if (ray_info->pos_X < info->map.X)
			return (&ray_info->img[1]);
		// 북 n
		else
			return (&ray_info->img[2]);
	}
	// 남북
	// s = y ++
	// n = y --
	else
	{
		// 동 e
		if (ray_info->pos_Y < info->map.Y)
			return (&ray_info->img[3]);
		// 서 w
		else
			return (&ray_info->img[4]);
	}
}

t_img	*ft_map_sprite(t_ray_info *ray_info)
{
	return (&ray_info->img[5]);
}
