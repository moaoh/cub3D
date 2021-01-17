/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 03:34:18 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/16 19:08:53 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void verLine (t_ray_info *info, int x, int y1, int y2, int color)
{
	int temp;

	temp = y1;
	while (temp <= y2)
	{
		mlx_pixel_put(info->mlx, info->win, x, temp, color);
		temp++;
	}
}

int			main_loop(t_ray_info *ray_info)
{
	int		x;
	t_loop_info		info;

	x = 0;
	while(x < ray_info->screen_X)
	{
		info.cameraX = 2 * x / (double)ray_info->screen_X - 1;
		
		info.ray.Y = ray_info->dir_Y + info.cameraX * ray_info->plane_Y;
		info.ray.X = ray_info->dir_X + info.cameraX * ray_info->plane_X;

		// printf("pos = %lf\n", ray_info->pos_Y);
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

		int drawStart = (-info.lineHeight / 2) + (ray_info->screen_Y / 2);
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = (info.lineHeight / 2) + (ray_info->screen_Y / 2);
        if (drawEnd >= ray_info->screen_Y)
            drawEnd = ray_info->screen_Y - 1;

// ----------------------------------------------------------------------------

        int color;
        if (ray_info->map[info.map.Y][info.map.X] == 1)
            color = 0xFF0000;
        else if (ray_info->map[info.map.Y][info.map.X] == 2)
            color = 0x00FF00;
        else if (ray_info->map[info.map.Y][info.map.X] == 3)
            color = 0x0000FF;
        else if (ray_info->map[info.map.Y][info.map.X] == 4)
            color = 0xFFFFFF;
        else
            color = 0x123145;

        // x, y side의 밝기를 달리해줌.
        if (info.side == 1)
            color = color / 2;
        /* 
            verLine 함수는 세로 줄을 긋는다.
            이 함수는 x좌표에서 drawStart~drawEnd까지 color 색으로 픽셀을 그린다.
            (x, drawStart) ~ (x, drawEnd)까지 color색이 되고
            x가 점점 증가하면 화면의 왼쪽 끝부터 오른쪽 끝까지 쭉 무언가가 그려지는 것을 상상해보자.
        */
		verLine(ray_info, x, 0, drawStart - 1, 0xFFFFFF);
		verLine(ray_info, x, drawStart, drawEnd, color);
		verLine(ray_info, x, drawEnd, ray_info->screen_Y - 1, 0xFFFFFF);
	}

// ----------------------------------------------------------------------------

	return (0);
}