/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 06:01:10 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 06:03:47 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray.h"

void			ft_my_mlx_pixel_put(t_img img, int y, int x, int color)
{
	img.data[y * (img.size_l / 4) + x] = color;
}

void			ft_wall(t_ray_info *ray_info, t_loop_info *info, int *x)
{
	ray_info->img_x = (*x);
	ft_wall_change(ray_info, info, 0, info->drawStart - 1);
	ft_wall_change(ray_info, info, info->drawStart, info->drawEnd);
	ft_wall_change(ray_info, info, info->drawEnd, ray_info->screen_Y - 1);
}

void			ft_sprite(t_ray_info *ray_info, t_sprite_info *sp)
{
	ft_sprite_change(ray_info, sp);
}