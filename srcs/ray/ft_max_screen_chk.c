/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_screen_chk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 08:12:19 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 10:26:04 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ft_max_screen_chk(t_ray_info *info, t_map *map)
{
	int	w_max;
	int	h_max;

	mlx_get_screen_size(info->mlx, &w_max, &h_max);
	if (map->screen.x > w_max)
	{
		info->screen_x = w_max;
		map->screen.x = w_max;
	}
	if (map->screen.y > h_max)
	{
		info->screen_y = h_max;
		map->screen.y = h_max;
	}
}
