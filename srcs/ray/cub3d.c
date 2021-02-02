/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:48:12 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/03 06:06:58 by junmkang         ###   ########.fr       */
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
	info->save_bool = map->save_bool;

	info->screen_Y = map->screen.Y;
	info->screen_X = map->screen.X;
	info->pos_Y = map->player.y + 0.5;
	info->pos_X = map->player.x + 0.5;
	player_dir(info, map->player.dir);
	player_plane(info, map->player.dir);
	info->map = map->map.map;
	
	info->c_color.R = map->c_color.R;
	info->c_color.G = map->c_color.G;
	info->c_color.B = map->c_color.B;
	info->f_color.R = map->f_color.R;
	info->f_color.G = map->f_color.G;
	info->f_color.B = map->f_color.B;
	

	info->texture.EA = map->texure.EA;
	info->texture.WE = map->texure.WE;
	info->texture.SO = map->texure.SO;
	info->texture.NO = map->texure.NO;
	info->texture.S = map->sprite.S;

	info->moveSpeed = 0.05;
	info->rotSpeed = 0.05;
}

static void			ft_imgs_info(t_ray_info *info, t_map map)
{
	info->img[0].img = mlx_new_image(info->mlx, map.screen.X, map.screen.Y);
	info->img[0].data = 
	(int *)mlx_get_data_addr(info->img[0].img, &info->img[0].bpp, \
						&info->img[0].size_l, &info->img[0].endian);
	ft_img_texture_info(info);
}

int					cub3d(t_map map)
{
	t_ray_info	info;
	
	ray_putin_info(&info, &map);
	
	info.mlx = mlx_init();
	ft_max_screen_chk(&info, &map);
	info.win = mlx_new_window(info.mlx, map.screen.X, map.screen.Y, "cub3d");
	ft_imgs_info(&info, map);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	
	mlx_hook(info.win, _KeyPress, 0, &key_press, &info);
	mlx_hook(info.win, _DestroyNotify, 0, &screen_close, &info);
	mlx_loop(info.mlx);
	
	return (0);
}

// 로데브
