/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_map_chk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 07:29:08 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/30 04:38:05 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

// 유저의 현재위치와 바라보고있는 방향을 기준으로 판단.
// 방향에 따라 알맞는 img 반환.
t_img	ft_map_wall(t_ray_info *ray_info, t_loop_info *info)
{
	// 동서
	// w = x --
	// e = x ++
	if (info->side == 1)
	{
		// 동 e
		if (ray_info->pos_X < info->map.X)
			return (ray_info->imgs.EA_img);
		// 서 w
		else
			return (ray_info->imgs.WE_img);
	}
	// 남북
	// s = y ++
	// n = y --
	else
	{
		// 남 s
		if (ray_info->pos_Y < info->map.Y)
			return (ray_info->imgs.SO_img);
		// 북 n
		else
			return (ray_info->imgs.NO_img);
	}
}

t_img	ft_map_sprite(t_ray_info *ray_info, t_loop_info *info)
{
	return (ray_info->imgs.S_img);
}

t_img	ft_img_map_chk(t_ray_info *ray_info, t_loop_info *info)
{
	// 벽.
	// sprite
	if (ray_info->map[info->map.Y][info->map.X] == '1')
	{
		return (ft_map_wall(ray_info, info));
	}
	else if (ray_info->map[info->map.Y][info->map.X] == '2')
	{
		return (ft_map_sprite(ray_info, info));
	}
	else
		ft_error("lt is not img.");
}