/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 03:34:18 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/04 07:15:27 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void			ft_loop_info(t_ray_info *ray_info, t_loop_info *info, int x)
{
	info->cameraX = 2 * x / (double)ray_info->screen_X - 1;
	info->ray.X = ray_info->dir_X + info->cameraX * ray_info->plane_X;
	info->ray.Y = ray_info->dir_Y + info->cameraX * ray_info->plane_Y;
	info->map.X = (int)ray_info->pos_X;
	info->map.Y = (int)ray_info->pos_Y;
	info->deltaDist.X = fabs(1 / info->ray.X);
	info->deltaDist.Y = fabs(1 / info->ray.Y);
}

static void			ft_loop_wall_dir(t_ray_info *ray_info, t_loop_info *info)
{
	if (info->ray.Y < 0)
	{
		info->step.Y = -1;
		info->sideDist.Y = (ray_info->pos_Y - info->map.Y) * \
			info->deltaDist.Y;
	}
	else
	{
		info->step.Y = 1;
		info->sideDist.Y = (info->map.Y + 1.0 - ray_info->pos_Y) * \
			info->deltaDist.Y;
	}
	if (info->ray.X < 0)
	{
		info->step.X = -1;
		info->sideDist.X = (ray_info->pos_X - info->map.X) * \
			info->deltaDist.X;
	}
	else
	{
		info->step.X = 1;
		info->sideDist.X = (info->map.X + 1.0 - ray_info->pos_X) * \
			info->deltaDist.X;
	}
}

static void			ft_loop_chk_dda(t_ray_info *ray_info, t_loop_info *info)
{
	int				tmp;

	tmp = 0;
	while (1)
	{
		if (info->sideDist.X < info->sideDist.Y)
		{
			info->sideDist.X += info->deltaDist.X;
			info->map.X += info->step.X;
			info->side = 0;
		}
		else
		{
			info->sideDist.Y += info->deltaDist.Y;
			info->map.Y += info->step.Y;
			info->side = 1;
		}
		if (ray_info->map[info->map.Y][info->map.X] == '1')
			break ;
	}
}

static void			ft_loop_dda(t_ray_info *ray_info, t_loop_info *info, int *x)
{
	if (info->side == 0)
		info->perpWallDist = \
		(info->map.X - ray_info->pos_X + (1 - info->step.X) / 2) / info->ray.X;
	else
		info->perpWallDist = \
		(info->map.Y - ray_info->pos_Y + (1 - info->step.Y) / 2) / info->ray.Y;
	info->lineHeight = ((int)ray_info->screen_Y / info->perpWallDist);

	info->drawStart = (-info->lineHeight / 2) + (ray_info->screen_Y / 2);
	if (info->drawStart < 0)
		info->drawStart = 0;
	info->drawEnd = (info->lineHeight / 2) + (ray_info->screen_Y / 2);
	if (info->drawEnd >= ray_info->screen_Y)
		info->drawEnd = ray_info->screen_Y - 1;
	(*x)++;

	ray_info->SP_dist[(*x)] = info->perpWallDist;
}

int					main_loop(t_ray_info *ray_info)
{
	int				x;
	t_loop_info		info;
	t_sprite_info	sp;

	x = 0;
	while (x < ray_info->screen_X)
	{
		ft_loop_info(ray_info, &info, x);
		ft_loop_wall_dir(ray_info, &info);
		ft_loop_chk_dda(ray_info, &info);
		ft_loop_dda(ray_info, &info, &x);
		ft_wall(ray_info, &info, &x);
	}
	ft_loop_sprite(ray_info, &info, &sp);
	// ft_sprite(ray_info, &info, &sp);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, ray_info->img[0].img);
	if (ray_info->save_bool)
		save_screen(ray_info);
	mlx_put_image_to_window(ray_info->mlx, ray_info->win, \
							ray_info->img[0].img, 0, 0);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, ray_info->win);
	return (0);
}
