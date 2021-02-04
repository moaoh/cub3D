/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:48:12 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 03:49:03 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void			ray_putin_info(t_ray_info *info, t_map *map)
{
	ray_cub_info(info, map);
	player_dir(info, map->player.dir);
	player_plane(info, map->player.dir);
	ray_map_info(info, map);
	ray_sp_info(info, map);

	info->moveSpeed = 0.05;
	info->rotSpeed = 0.05;

	info->SP_dist = (double *)malloc(sizeof(double) * info->screen_X + 1);
	info->SP_pwd.spriteOrder = (int *)malloc(sizeof(int) * info->SP_count + 1);
	info->SP_pwd.spriteDistance = (double *)malloc(sizeof(double) * info->SP_count + 1);
}

static void			ft_imgs_info(t_ray_info *info, t_map *map)
{
	info->img[0].img = mlx_new_image(info->mlx, map->screen.X, map->screen.Y);
	info->img[0].data = 
	(int *)mlx_get_data_addr(info->img[0].img, &info->img[0].bpp, \
						&info->img[0].size_l, &info->img[0].endian);
	ft_img_texture_info(info);
}

static void			ray_info_free(t_ray_info *info)
{
	free(info->SP_dist);
	free(info->SP_pwd.spriteDistance);
	free(info->SP_pwd.spriteOrder);
	free(info->texture.NO);
	free(info->texture.WE);
	free(info->texture.SO);
	free(info->texture.EA);
}

int					cub3d(t_map *map)
{
	t_ray_info	info;
	
	ray_putin_info(&info, map);
	ft_max_screen_chk(&info, map);
	
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, map->screen.X, map->screen.Y, "cub3d");
	ft_imgs_info(&info, map);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	
	mlx_hook(info.win, _KeyPress, 0, &key_press, &info);
	mlx_hook(info.win, _DestroyNotify, 0, &screen_close, &info);
	mlx_loop(info.mlx);
	ray_info_free(&info);
	
	return (0);
}

// 로데브
