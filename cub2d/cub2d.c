/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 06:55:49 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/12 07:32:02 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

static void cub2d_info(t_cub2d_info *info, t_map *map)
{
	info->map = map->map.map;
	// info->img.img = 
	// info->img.data = 
}

int cub2d(t_map map)
{
	t_cub2d_info info;

	cub2d_info(&info, &map);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, map.screen.X, map.screen.Y, "cub2d");

	return (0);
}