/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:27:16 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/12 02:44:54 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

// 추가적인 공부가 필요함 
int key_press(int key, t_ray_info *info)
{
	double oldDirX;
	double oldPlaneX;

	printf("key : %d\n", key);
	if (key == KEY_W)
	{
		printf("key : %d\n", key);
		if (!info->map[(int)(info->pos_Y + info->dir_Y * info->moveSpeed)][(int)(info->pos_X)])
			info->pos_Y += info->dir_Y * info->moveSpeed;
		if (!info->map[(int)(info->pos_Y)][(int)(info->pos_X + info->dir_X * info->moveSpeed)])
			info->pos_X += info->dir_X * info->moveSpeed;
	}
	if (key == KEY_S)
	{
		if (!info->map[(int)(info->pos_Y - info->dir_Y * info->moveSpeed)][(int)(info->pos_X)])
			info->pos_Y -= info->dir_Y * info->moveSpeed;
		if (!info->map[(int)(info->pos_Y)][(int)(info->pos_X - info->dir_X * info->moveSpeed)])
			info->pos_X -= info->dir_X * info->moveSpeed;
	}
	if (key == KEY_A)
	{
		oldDirX = info->dir_X;
		info->dir_Y = oldDirX * sin(info->rotSpeed) + info->dir_Y * cos(info->rotSpeed);
		info->dir_X = info->dir_X * cos(info->rotSpeed) - info->dir_Y * sin(info->rotSpeed);
		oldPlaneX = info->plane_X;
		info->plane_Y = oldPlaneX * sin(info->rotSpeed) + info->plane_Y * cos(info->rotSpeed);
		info->plane_X = info->plane_X * cos(info->rotSpeed) - info->plane_Y * sin(info->rotSpeed);
	}
	if (key == KEY_D)
	{
		oldDirX = info->dir_X;
		info->dir_Y = oldDirX * sin(-info->rotSpeed) + info->dir_Y * cos(-info->rotSpeed);
		info->dir_X = info->dir_X * cos(-info->rotSpeed) - info->dir_Y * sin(-info->rotSpeed);
		oldPlaneX = info->plane_X;
		info->plane_Y = oldPlaneX * sin(-info->rotSpeed) + info->plane_Y * cos(-info->rotSpeed);
		info->plane_X = info->plane_X * cos(-info->rotSpeed) - info->plane_Y * sin(-info->rotSpeed);
	}
    
    return (0);
}