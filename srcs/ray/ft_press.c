/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:27:16 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/06 17:08:45 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int				screen_close(void)
{
	
	exit(0);
	return (0);
}

static int		key_press_ws(int key, t_ray_info *info, \
						double move_y, double move_x)
{
	if (key == KEY_W)
	{
		if (info->map[(int)(info->pos_y + move_y)][(int)(info->pos_x)] == '1' \
		|| info->map[(int)(info->pos_y)][(int)(info->pos_x + move_x)] == '1')
			return (0);
		info->pos_y += move_y;
		info->pos_x += move_x;
	}
	if (key == KEY_S)
	{
		if (info->map[(int)(info->pos_y - move_y)][(int)(info->pos_x)] == '1' \
		|| info->map[(int)(info->pos_y)][(int)(info->pos_x - move_x)] == '1')
			return (0);
		info->pos_y -= move_y;
		info->pos_x -= move_x;
	}
	return (0);
}

static int		key_press_ad(int key, t_ray_info *info, \
						double move_y, double move_x)
{
	if (key == KEY_A)
	{
		if (info->map[(int)(info->pos_y + move_x)][(int)(info->pos_x)] == '1' \
		|| info->map[(int)(info->pos_y)][(int)(info->pos_x - move_y)] == '1')
			return (0);
		info->pos_y += move_x;
		info->pos_x -= move_y;
	}
	if (key == KEY_D)
	{
		if (info->map[(int)(info->pos_y - move_x)][(int)(info->pos_x)] == '1' \
		|| info->map[(int)(info->pos_y)][(int)(info->pos_x + move_y)] == '1')
			return (0);
		info->pos_y -= move_x;
		info->pos_x += move_y;
	}
	return (0);
}

static int		key_press_lr(t_ray_info *info, double c, double s)
{
	info->old_dir_x = info->dir_x;
	info->dir_x = info->dir_x * c - info->dir_y * s;
	info->dir_y = info->old_dir_x * s + info->dir_y * c;
	info->old_dir_x = info->plane_x;
	info->plane_x = info->plane_x * c - info->plane_y * s;
	info->plane_y = info->old_dir_x * s + info->plane_y * c;
	return (0);
}

int				key_press(int key, t_ray_info *info)
{
	t_key	key_info;

	key_info.move_x = info->dir_x * info->move_speed;
	key_info.move_y = info->dir_y * info->move_speed;
	key_info.p_c = cos(info->rot_speed);
	key_info.p_s = sin(info->rot_speed);
	key_info.m_c = cos(-info->rot_speed);
	key_info.m_s = sin(-info->rot_speed);
	if (key == KEY_W || key == KEY_S)
		key_press_ws(key, info, key_info.move_y, key_info.move_x);
	if (key == KEY_A || key == KEY_D)
		key_press_ad(key, info, key_info.move_y, key_info.move_x);
	if (key == KEY_LEFT)
		key_press_lr(info, key_info.p_c, key_info.p_s);
	if (key == KEY_RIGHT)
		key_press_lr(info, key_info.m_c, key_info.m_s);
	if (key == KEY_ESC)
	{
		printf("bye :D\n");
		exit(0);
	}
	return (0);
}
