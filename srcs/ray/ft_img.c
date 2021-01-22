/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 06:01:10 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/23 02:27:54 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ft_my_mlx_pixel_put(t_img img, int y, int x, int color)
{
	img.data[y * (img.size_l / 4) + x] = color;
}

void	ft_img_change(t_ray_info *ray_info, int x, int start, int end, int color)
{
	int temp;

	
	temp = start;
	while (temp <= end)
	{
		// printf("%d %d %d %d\n", x, ray_info->screen_Y, temp, ray_info->screen_X);
		if (x >= 0 && x < ray_info->screen_X && \
			temp >= 0 && temp < ray_info->screen_Y)
		{
			ft_my_mlx_pixel_put(ray_info->img, temp, x, color);
		}
		temp++;
	}
}

void	ft_img(t_ray_info *ray_info, t_loop_info *info, int x)
{
		
		// 벽.
		if (ray_info->map[info->map.Y][info->map.X] == 1)
		{
			info->color = 0x00FF00;
		}
		// splite
		else if (ray_info->map[info->map.Y][info->map.X] == 2)
			info->color = 0x00FF00;
		else
			info->color = 0x123145;

		// x, y side의 밝기를 달리해줌.
		if (info->side == 1)
			info->color = info->color / 2;

		ft_img_change(ray_info, x, 0, info->drawStart - 1, 0x1DA06A);
		ft_img_change(ray_info, x, info->drawStart, info->drawEnd, info->color);
		ft_img_change(ray_info, x, info->drawEnd, ray_info->screen_Y - 1, 0xFF6633);

		// printf("%d %d %d\n", x, info.drawStart, info.drawEnd);
}