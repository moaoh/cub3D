/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 06:01:10 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 10:38:54 by junmkang         ###   ########.fr       */
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
	ft_wall_change(ray_info, info, 0, info->draw_start - 1);
	ft_wall_change(ray_info, info, info->draw_start, info->draw_end);
	ft_wall_change(ray_info, info, info->draw_end, ray_info->screen_y - 1);
}

void			ft_sprite(t_ray_info *ray_info, t_sprite_info *sp)
{
	ft_sprite_change(ray_info, sp);
}
