/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 03:34:18 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 06:03:29 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray.h"

int					main_loop(t_ray_info *ray_info)
{
	t_loop_info		info;
	t_sprite_info	sp;

	ft_loop_wall(ray_info, &info);
	ft_loop_sprite(ray_info, &sp);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, ray_info->img[0].img);
	if (ray_info->save_bool)
		save_screen(ray_info);
	mlx_put_image_to_window(ray_info->mlx, ray_info->win, \
							ray_info->img[0].img, 0, 0);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, ray_info->win);
	return (0);
}
