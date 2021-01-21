/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 03:34:18 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/22 00:54:18 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void  my_mlx_pixel_put(t_img img, int y, int x, int color)
{
	// printf("2test\n");
	// printf("size_l = %d\n", img.size_l);
	img.data[y * (img.size_l / 4) + x * (img.bpp / 32)] = color;
}

void img_change(t_ray_info *ray_info, int x, int start, int end, int color)
{
	int temp;

	
	temp = start;
	while (temp <= end)
	{
		// printf("%d %d %d %d\n", x, ray_info->screen_Y, temp, ray_info->screen_X);
		// if (x >= 0 && x < ray_info->screen_Y && \
		// 	temp >= 0 && temp < ray_info->screen_X)
		// {
			my_mlx_pixel_put(ray_info->img, temp, x, color);
		// }
		temp++;
	}
}

int			main_loop(t_ray_info *ray_info)
{
	int		x;
	t_loop_info		info;

	// printf("%s\n", map->texure.EA);
	x = 0;
	while(x < ray_info->screen_X)
	{
		info.cameraX = 2 * x / (double)ray_info->screen_X - 1;
		
		info.ray.Y = ray_info->dir_Y + info.cameraX * ray_info->plane_Y;
		info.ray.X = ray_info->dir_X + info.cameraX * ray_info->plane_X;

		info.map.Y = (int)ray_info->pos_Y;
		info.map.X = (int)ray_info->pos_X;
		
		info.deltaDist.Y = fabs(1 / info.ray.Y);
		info.deltaDist.X = fabs(1 / info.ray.X);

		if (info.ray.Y < 0)
		{
			info.step.Y = -1;
			info.sideDist.Y = (ray_info->pos_Y - info.map.Y) * info.deltaDist.Y;
		}
		else
		{
			info.step.Y = 1;
			info.sideDist.Y = (info.map.Y + 1.0 - ray_info->pos_Y) * info.deltaDist.Y;
		}
		if (info.ray.X < 0)
		{
			info.step.X = -1;
			info.sideDist.X = (ray_info->pos_X - info.map.X) * info.deltaDist.X;
		}
		else
		{
			info.step.X = 1;
			info.sideDist.X = (info.map.X + 1.0 - ray_info->pos_X) * info.deltaDist.X;
		}
		
		while (1)
		{
			if (info.sideDist.Y < info.sideDist.X)
			{
				info.sideDist.Y += info.deltaDist.Y;
				info.map.Y += info.step.Y;
				info.side = 0;
			}
			else
			{
				info.sideDist.X += info.deltaDist.X;
				info.map.X += info.step.X;
				info.side = 1;
			}
			if (ray_info->map[info.map.Y][info.map.X] == '1') 
				break;
		}

		if (info.side == 0)
			info.perpWallDist = (info.map.Y - ray_info->pos_Y + (1 - info.step.Y) / 2) / info.ray.Y;
		else
			info.perpWallDist = (info.map.X - ray_info->pos_X + (1 - info.step.X) / 2) / info.ray.X;
		
		info.lineHeight = ((int)ray_info->screen_Y / info.perpWallDist);
		x++;

		info.drawStart = (-info.lineHeight / 2) + (ray_info->screen_Y / 2);
        if (info.drawStart < 0)
            info.drawStart = 0;
        info.drawEnd = (info.lineHeight / 2) + (ray_info->screen_Y / 2);
        if (info.drawEnd >= ray_info->screen_Y)
            info.drawEnd = ray_info->screen_Y - 1;

// ----------------------------------------------------------------------------

        int color;
		
		// 벽.
        if (ray_info->map[info.map.Y][info.map.X] == 1)
            color = 0xFF0000;
		// splite
        else if (ray_info->map[info.map.Y][info.map.X] == 2)
            color = 0x00FF00;
        else
            color = 0x123145;

        // x, y side의 밝기를 달리해줌.
        if (info.side == 1)
            color = color / 2;

		img_change(ray_info, x, 0, info.drawStart - 1, 0xFFFFFF);
		img_change(ray_info, x, info.drawStart, info.drawEnd, color);
		img_change(ray_info, x, info.drawEnd, ray_info->screen_Y - 1, 0xFFFFFF);

		mlx_put_image_to_window(ray_info->mlx, ray_info->win, ray_info->img.img, 0, 0);
		// printf("%d %d %d\n", x, info.drawStart, info.drawEnd);
	}

// ----------------------------------------------------------------------------

	return (0);
}