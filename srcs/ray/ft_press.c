/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:27:16 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 11:02:35 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int screen_close(void)
{

	exit(0);
	return (0);
}

static int	key_press_ws(int key, t_ray_info *info)
{
	if (key == KEY_W)
	{
		if (info->map[(int)(info->pos_y + info->dir_y * info->move_speed)][(int)(info->pos_x)] == '1' || \
			info->map[(int)(info->pos_y)][(int)(info->pos_x + info->dir_x * info->move_speed)] == '1')
				return (0);
		if (info->map[(int)(info->pos_y + info->dir_y * info->move_speed)][(int)(info->pos_x)])
			info->pos_y += info->dir_y * info->move_speed;
		if(info->map[(int)(info->pos_y)][(int)(info->pos_x + info->dir_x * info->move_speed)])
			info->pos_x += info->dir_x * info->move_speed;
	}
	if (key == KEY_S)
	{
		if (info->map[(int)(info->pos_y - info->dir_y * info->move_speed)][(int)(info->pos_x)] == '1' || \
			info->map[(int)(info->pos_y)][(int)(info->pos_x - info->dir_x * info->move_speed)] == '1')
				return (0);
		if (info->map[(int)(info->pos_y - info->dir_y * info->move_speed)][(int)(info->pos_x)])
			info->pos_y -= info->dir_y * info->move_speed;
		if (info->map[(int)(info->pos_y)][(int)(info->pos_x - info->dir_x * info->move_speed)])
			info->pos_x -= info->dir_x * info->move_speed;
	}
	return (0);
}

static int	key_press_ad(int key, t_ray_info *info)
{
	if (key == KEY_A)
	{
		if (info->map[(int)(info->pos_y + info->dir_x * info->move_speed)][(int)(info->pos_x)] == '1' || \
			info->map[(int)(info->pos_y)][(int)(info->pos_x - info->dir_y * info->move_speed)] == '1')
				return (0);
		if (info->map[(int)(info->pos_y + info->dir_x * info->move_speed)][(int)(info->pos_x)])
			info->pos_y += info->dir_x * info->move_speed;
		if (info->map[(int)(info->pos_y)][(int)(info->pos_x - info->dir_y * info->move_speed)])
			info->pos_x -= info->dir_y * info->move_speed;
	}
	if (key == KEY_D)
	{
		if (info->map[(int)(info->pos_y - info->dir_x * info->move_speed)][(int)(info->pos_x)] == '1' || \
			info->map[(int)(info->pos_y)][(int)(info->pos_x + info->dir_y * info->move_speed)] == '1')
				return (0);
		if (info->map[(int)(info->pos_y - info->dir_x * info->move_speed)][(int)(info->pos_x)])
			info->pos_y -= info->dir_x * info->move_speed;
		if (info->map[(int)(info->pos_y)][(int)(info->pos_x + info->dir_y * info->move_speed)])
			info->pos_x += info->dir_y * info->move_speed;
	}
	return (0);
}

static int	key_press_lr(int key, t_ray_info *info)
{
	if (key == KEY_LEFT)
	{
		info->old_dir_x = info->dir_x;
		info->dir_x = info->dir_x * cos(info->rot_speed) - info->dir_y * sin(info->rot_speed);
		info->dir_y = info->old_dir_x * sin(info->rot_speed) + info->dir_y * cos(info->rot_speed);
		info->old_dir_x = info->plane_x;
		info->plane_x = info->plane_x * cos(info->rot_speed) - info->plane_y * sin(info->rot_speed);
		info->plane_y = info->old_dir_x * sin(info->rot_speed) + info->plane_y * cos(info->rot_speed);
	}
	if (key == KEY_RIGHT)
	{
		info->old_dir_x = info->dir_x;
		info->dir_x = info->dir_x * cos(-info->rot_speed) - info->dir_y * sin(-info->rot_speed);
		info->dir_y = info->old_dir_x * sin(-info->rot_speed) + info->dir_y * cos(-info->rot_speed);
		info->old_dir_x = info->plane_x;
		info->plane_x = info->plane_x * cos(-info->rot_speed) - info->plane_y * sin(-info->rot_speed);
		info->plane_y = info->old_dir_x * sin(-info->rot_speed) + info->plane_y * cos(-info->rot_speed);
	}
	return (0);
}

int			key_press(int key, t_ray_info *info)
{
	if (key == KEY_W || key == KEY_S)
		key_press_ws(key, info);
	if (key == KEY_A || key == KEY_D)
		key_press_ad(key, info);
	if (key == KEY_LEFT || key == KEY_RIGHT)
		key_press_lr(key, info);
	if (key == KEY_ESC)
	{
		printf("bye :D\n");	
		exit(0);
	}
    return (0);
}
