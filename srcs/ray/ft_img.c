/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 06:01:10 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/04 06:38:32 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void			ft_my_mlx_pixel_put(t_img img, int y, int x, int color)
{
	img.data[y * (img.size_l / 4) + x] = color;
}

void		ft_wall(t_ray_info *ray_info, t_loop_info *info, int *x)
{
	ray_info->img_x = (*x);
	ft_wall_change(ray_info, info, 0, info->drawStart - 1);
	ft_wall_change(ray_info, info, info->drawStart, info->drawEnd);
	ft_wall_change(ray_info, info, info->drawEnd, ray_info->screen_Y - 1);
}

void		ft_sprite(t_ray_info *ray_info, t_loop_info *info, t_sprite_info *sp)
{
	ft_sprite_change(ray_info, info, sp);
}

// void	ft_img(t_ray_info *ray_info, t_loop_info *info, t_sprite_info *sp, int x)
// {
// 	t_img *img;

// 	ray_info->img_x = x;
// 	img = ft_img_map_chk(ray_info, info);
// 	if (img->type != '2')
// 	{
// 		ft_wall(ray_info, info, &x);
// 	}
// 	else
// 	{
// 		ft_sprite(ray_info, info, sp);
// 	}
// }