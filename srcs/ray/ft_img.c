/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 06:01:10 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/25 07:02:29 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ft_my_mlx_pixel_put(t_img img, int y, int x, int color)
{
	y = y - 1;
	img.data[y * (img.size_l / 4) + x] = color;
}

// 유저의 현재위치와 바라보고있는 방향을 기준으로 판단.
void	ft_map_wall(t_ray_info *ray_info, t_loop_info *info, int x)
{
	// 동서
	// w = x --
	// e = x ++
	// printf("%d %d\n", ray_info->imgs.EA_img.width, ray_info->imgs.EA_img.height);
	if (info->side == 1)
	{
		// 동 e
		if (ray_info->pos_X < info->map.X)
		{
			double obj_x;
			if (info->side == 0)
				obj_x = ray_info->pos_Y + info->perpWallDist * info->ray.Y;
			else
				obj_x = ray_info->pos_X + info->perpWallDist * info->ray.X;
				
			info->color = 0xcc0000;
		}
		// 서 w
		else
			info->color = 0xFF6633;
	}
	// 남북
	// s = y ++
	// n = y --
	else if (info->side == 0)
	{
		// 남 s
		if (ray_info->pos_Y < info->map.Y)
			info->color = 0xf8e862;
		// 북 n
		else
			info->color = 0x119933;
	}
}

void	ft_img_change(t_ray_info *ray_info, int x, int start, int end, int color)
{
	int temp;
	int color; 

	temp = start;
	while (temp <= end)
	{
		ft_img_map_chk();
		ft_my_mlx_pixel_put(ray_info->imgs.main_img, temp, x, color);
		temp++;
	}
}


void	ft_map_splite(t_ray_info *ray_info, t_loop_info *info, int x)
{
	info->color = 0x00FF00;
}

void	ft_img(t_ray_info *ray_info, t_loop_info *info, int x)
{
	// 벽.
	if (ray_info->map[info->map.Y][info->map.X] == '1')
		ft_map_wall(ray_info, info, x);	
	// splite
	else if (ray_info->map[info->map.Y][info->map.X] == '2')
		ft_map_splite(ray_info, info, x);
	else
		info->color = 0x123145;

	ft_img_change(ray_info, x, 0, info->drawStart - 1, 0x1DA06A);
	ft_img_change(ray_info, x, info->drawStart, info->drawEnd, info->color);
	ft_img_change(ray_info, x, info->drawEnd, ray_info->screen_Y - 1, 0xFFFFFF);
}