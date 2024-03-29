/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:48:12 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/07 03:09:08 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void		ray_putin_info(t_ray_info *info, t_map *map)
{
	ray_cub_info(info, map);
	player_dir(info, map->player.dir);
	player_plane(info, map->player.dir);
	ray_map_info(info, map);
	ray_sp_info(info, map);
	info->move_speed = 0.05;
	info->rot_speed = 0.05;
	if (!(info->sp_dist = \
	(double *)malloc(sizeof(double) * (info->screen_x + 1))))
		ft_error("malloc error. sp_dist");
	if (!(info->sp_pwd.sprite_order = \
	(int *)malloc(sizeof(int) * (info->sp_count + 1))))
		ft_error("malloc error. sprite_order");
	if (!(info->sp_pwd.sprite_distance = \
	(double *)malloc(sizeof(double) * (info->sp_count + 1))))
		ft_error("malloc error. sprite_distance");
}

static void		ft_imgs_info(t_ray_info *info, t_map *map)
{
	info->img[0].img = mlx_new_image(info->mlx, map->screen.x, map->screen.y);
	info->img[0].data = \
	(unsigned int *)mlx_get_data_addr(info->img[0].img, &info->img[0].bpp, \
						&info->img[0].size_l, &info->img[0].endian);
	ft_img_texture_info(info);
}

int				cub3d(t_map *map)
{
	t_ray_info	info;

	ray_putin_info(&info, map);
	ft_max_screen_chk(&info, map);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, map->screen.x, map->screen.y, "cub3d");
	ft_imgs_info(&info, map);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, _KEYPRESS, 0, &key_press, &info);
	mlx_hook(info.win, _DESTROYNOTIFY, 0, &screen_close, &info);
	mlx_loop(info.mlx);
	return (0);
}
