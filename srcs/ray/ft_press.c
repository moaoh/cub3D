/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:27:16 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/03 03:14:05 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

// 추가적인 공부가 필요함
int key_press(int key, t_ray_info *info)
{
	if (key == KEY_W)
	{
		if (info->map[(int)(info->pos_Y + info->dir_Y * info->moveSpeed)][(int)(info->pos_X)] == '1' || \
			info->map[(int)(info->pos_Y)][(int)(info->pos_X + info->dir_X * info->moveSpeed)] == '1')
				return (0);
		if (info->map[(int)(info->pos_Y + info->dir_Y * info->moveSpeed)][(int)(info->pos_X)])
			info->pos_Y += info->dir_Y * info->moveSpeed;
		if(info->map[(int)(info->pos_Y)][(int)(info->pos_X + info->dir_X * info->moveSpeed)])
			info->pos_X += info->dir_X * info->moveSpeed;
	}
	if (key == KEY_S)
	{
		if (info->map[(int)(info->pos_Y - info->dir_Y * info->moveSpeed)][(int)(info->pos_X)] == '1' || \
			info->map[(int)(info->pos_Y)][(int)(info->pos_X - info->dir_X * info->moveSpeed)] == '1')
				return (0);
		if (info->map[(int)(info->pos_Y - info->dir_Y * info->moveSpeed)][(int)(info->pos_X)])
			info->pos_Y -= info->dir_Y * info->moveSpeed;
		if (info->map[(int)(info->pos_Y)][(int)(info->pos_X - info->dir_X * info->moveSpeed)])
			info->pos_X -= info->dir_X * info->moveSpeed;
	}
	if (key == KEY_A)
	{
		if (info->map[(int)(info->pos_Y + info->dir_X * info->moveSpeed)][(int)(info->pos_X)] == '1' || \
			info->map[(int)(info->pos_Y)][(int)(info->pos_X - info->dir_Y * info->moveSpeed)] == '1')
				return (0);
		if (info->map[(int)(info->pos_Y + info->dir_X * info->moveSpeed)][(int)(info->pos_X)])
			info->pos_Y += info->dir_X * info->moveSpeed;
		if (info->map[(int)(info->pos_Y)][(int)(info->pos_X - info->dir_Y * info->moveSpeed)])
			info->pos_X -= info->dir_Y * info->moveSpeed;
	}
	if (key == KEY_D)
	{
		if (info->map[(int)(info->pos_Y - info->dir_X * info->moveSpeed)][(int)(info->pos_X)] == '1' || \
			info->map[(int)(info->pos_Y)][(int)(info->pos_X + info->dir_Y * info->moveSpeed)] == '1')
				return (0);
		if (info->map[(int)(info->pos_Y - info->dir_X * info->moveSpeed)][(int)(info->pos_X)])
			info->pos_Y -= info->dir_X * info->moveSpeed;
		if (info->map[(int)(info->pos_Y)][(int)(info->pos_X + info->dir_Y * info->moveSpeed)])
			info->pos_X += info->dir_Y * info->moveSpeed;
	}
	if (key == KEY_left)
	{
		info->oldDirX = info->dir_X;
		info->dir_Y = info->oldDirX * sin(info->rotSpeed) + info->dir_Y * cos(info->rotSpeed);
		info->dir_X = info->dir_X * cos(info->rotSpeed) - info->dir_Y * sin(info->rotSpeed);
		info->oldPlaneX = info->plane_X;
		info->plane_Y = info->oldPlaneX * sin(info->rotSpeed) + info->plane_Y * cos(info->rotSpeed);
		info->plane_X = info->plane_X * cos(info->rotSpeed) - info->plane_Y * sin(info->rotSpeed);
	}
	if (key == KEY_right)
	{
		info->oldDirX = info->dir_X;
		info->dir_Y = info->oldDirX * sin(-info->rotSpeed) + info->dir_Y * cos(-info->rotSpeed);
		info->dir_X = info->dir_X * cos(-info->rotSpeed) - info->dir_Y * sin(-info->rotSpeed);
		info->oldPlaneX = info->plane_X;
		info->plane_Y = info->oldPlaneX * sin(-info->rotSpeed) + info->plane_Y * cos(-info->rotSpeed);
		info->plane_X = info->plane_X * cos(-info->rotSpeed) - info->plane_Y * sin(-info->rotSpeed);
	}
	if (key == KEY_ESC)
	{
		printf("bye :D\n");	
		exit(0);
	}
    
    return (0);
}

int screen_close(void)
{
	exit(0);
	return (0);
}