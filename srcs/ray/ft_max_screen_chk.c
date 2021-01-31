/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_screen_chk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 08:12:19 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/31 16:00:20 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ft_max_screen_chk(t_ray_info *info, t_map *map)
{
	int	w_max;
	int	h_max;

	mlx_get_screen_size(info->mlx, &w_max, &h_max);
	if (map->screen.X > w_max || map->screen.Y > h_max)
	{
		printf("your screen size = %d %d\n", map->screen.X, map->screen.Y);
		printf("Max screen size = %d %d\n", w_max, h_max);
		ft_error("over screen.");
	}
	// if (map->screen.X > w_max)
	// 	map->screen.X = w_max - 1;
	// if (map->screen.Y > h_max)
	// 	map->screen.Y = h_max - 1;
}