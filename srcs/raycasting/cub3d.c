/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:48:12 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/14 06:15:45 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void			player_dir(t_ray_info *info, char dir)
{
	if (dir == 'E')
	{
		info->dir_Y = 0;
		info->dir_X = +1;
	}
	else if (dir == 'W')
	{
		info->dir_Y = 0;
		info->dir_X = -1;
	}
	else if (dir == 'N')
	{
		info->dir_Y = -1;
		info->dir_X = 0;
	}
	else if (dir == 'S')
	{
		info->dir_Y = +1;
		info->dir_X = 0;
	}
}

static void			player_plane(t_ray_info *info, char dir)
{
	if (dir == 'E')
	{
		info->plane_Y = -0.66;
		info->plane_X = 0;
	}
	else if (dir == 'W')
	{
		info->plane_Y = 0.66;
		info->plane_X = 0;
	}
	else if (dir == 'N')
	{
		info->plane_Y = 0;
		info->plane_X = -0.66;
	}
	else if (dir == 'S')
	{
		info->plane_Y = 0;
		info->plane_X = +0.66;
	}
}

static void			ray_putin_info(t_ray_info *info, t_map *map)
{
	info->screen_Y = map->screen.Y;
	info->screen_X = map->screen.X;
	info->pos_Y = map->player.y;
	info->pos_X = map->player.x;
	player_dir(info, map->player.dir);
	player_plane(info, map->player.dir);
	info->map = map->map.map;

	info->moveSpeed = 20;
	info->rotSpeed = 0.05;
}

int					cub3d(t_map map)
{
	t_ray_info	info;

	ray_putin_info(&info, &map);
	info.mlx = mlx_init();

	info.win = mlx_new_window(info.mlx, map.screen.X, map.screen.Y, "cub3d");
	mlx_loop_hook(info.mlx, &main_loop, &info);

	mlx_hook(info.win, 2, 0, &key_press, &info);
	mlx_loop(info.mlx);
	
	return (0);
}

// 로데브
