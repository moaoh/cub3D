/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 06:01:10 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/03 09:01:23 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void			ft_my_mlx_pixel_put(t_img img, int y, int x, int color)
{
	img.data[y * (img.size_l / 4) + x] = color;
}

static void		ft_wall(t_ray_info *ray_info, t_loop_info *info)
{
	ft_wall_change(ray_info, info, 0, info->drawStart - 1);
	ft_wall_change(ray_info, info, info->drawStart, info->drawEnd);
	ft_wall_change(ray_info, info, info->drawEnd, ray_info->screen_Y - 1);
}

// static void		ft_sprite(t_ray_info *ray_info, t_loop_info *info, t_sprite_info *sp)
// {
	
// }

void	ft_img(t_ray_info *ray_info, t_loop_info *info, t_sprite_info *sp, int x)
{
	t_img *img;

	sp->drawEndX = sp->drawEndX;
	ray_info->img_x = x;
	img = ft_img_map_chk(ray_info, info);
	// if (img->type != '2')
	// {
		ft_wall(ray_info, info);
	// }
	// else
	// {
	// 	ft_sprite(ray_info, info, sp);
	// }
	
}