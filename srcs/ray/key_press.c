/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:27:16 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/15 03:07:20 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

// int		key_press(int key, t_ray_info *info)
// {
// 	printf("key : %d\n", key);
// }

// 추가적인 공부가 필요함 
int key_press(int key, t_ray_info *info)
{
	if (key == KEY_W)
	{
		if (info->map[(int)(info->pos_Y + info->dir_Y * info->moveSpeed)][(int)(info->pos_X)])
			info->pos_Y += info->dir_Y * info->moveSpeed;
		if(info->map[(int)(info->pos_Y)][(int)(info->pos_X + info->dir_X * info->moveSpeed)])
			info->pos_X += info->dir_X * info->moveSpeed;
	}
	if (key == KEY_S)
	{
		if (info->map[(int)(info->pos_Y - info->dir_Y * info->moveSpeed)][(int)(info->pos_X)])
			info->pos_Y -= info->dir_Y * info->moveSpeed;
		if (info->map[(int)(info->pos_Y)][(int)(info->pos_X - info->dir_X * info->moveSpeed)])
			info->pos_X -= info->dir_X * info->moveSpeed;
	}
	if (key == KEY_A)
	{
		info->oldDirX = info->dir_X;
		info->dir_Y = info->oldDirX * sin(info->rotSpeed) + info->dir_Y * cos(info->rotSpeed);
		info->dir_X = info->dir_X * cos(info->rotSpeed) - info->dir_Y * sin(info->rotSpeed);
		info->oldPlaneX = info->plane_X;
		info->plane_Y = info->oldPlaneX * sin(info->rotSpeed) + info->plane_Y * cos(info->rotSpeed);
		info->plane_X = info->plane_X * cos(info->rotSpeed) - info->plane_Y * sin(info->rotSpeed);
	}
	if (key == KEY_D)
	{
		info->oldDirX = info->dir_X;
		info->dir_Y = info->oldDirX * sin(-info->rotSpeed) + info->dir_Y * cos(-info->rotSpeed);
		info->dir_X = info->dir_X * cos(-info->rotSpeed) - info->dir_Y * sin(-info->rotSpeed);
		info->oldPlaneX = info->plane_X;
		info->plane_Y = info->oldPlaneX * sin(-info->rotSpeed) + info->plane_Y * cos(-info->rotSpeed);
		info->plane_X = info->plane_X * cos(-info->rotSpeed) - info->plane_Y * sin(-info->rotSpeed);
	}
	if (key == KEY_ESC)
		exit(0);
    
    return (0);
}