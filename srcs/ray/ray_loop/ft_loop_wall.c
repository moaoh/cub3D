/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 07:20:49 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 10:59:32 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray.h"

static void			ft_loop_wall_info(t_ray_info *ray_info, \
										t_loop_info *info, int x)
{
	info->camera_x = 2 * x / (double)ray_info->screen_x - 1;
	info->ray.x = ray_info->dir_x + info->camera_x * ray_info->plane_x;
	info->ray.y = ray_info->dir_y + info->camera_x * ray_info->plane_y;
	info->map.x = (int)ray_info->pos_x;
	info->map.y = (int)ray_info->pos_y;
	info->delta_dist.x = fabs(1 / info->ray.x);
	info->delta_dist.y = fabs(1 / info->ray.y);
}

static void			ft_loop_wall_dir(t_ray_info *ray_info, t_loop_info *info)
{
	if (info->ray.y < 0)
	{
		info->step.y = -1;
		info->side_dist.y = (ray_info->pos_y - info->map.y) * \
			info->delta_dist.y;
	}
	else
	{
		info->step.y = 1;
		info->side_dist.y = (info->map.y + 1.0 - ray_info->pos_y) * \
			info->delta_dist.y;
	}
	if (info->ray.x < 0)
	{
		info->step.x = -1;
		info->side_dist.x = (ray_info->pos_x - info->map.x) * \
			info->delta_dist.x;
	}
	else
	{
		info->step.x = 1;
		info->side_dist.x = (info->map.x + 1.0 - ray_info->pos_x) * \
			info->delta_dist.x;
	}
}

static void			ft_loop_wall_chk_dda(t_ray_info *ray_info, \
											t_loop_info *info)
{
	int				tmp;

	tmp = 0;
	while (1)
	{
		if (info->side_dist.x < info->side_dist.y)
		{
			info->side_dist.x += info->delta_dist.x;
			info->map.x += info->step.x;
			info->side = 0;
		}
		else
		{
			info->side_dist.y += info->delta_dist.y;
			info->map.y += info->step.y;
			info->side = 1;
		}
		if (ray_info->map[info->map.y][info->map.x] == '1')
			break ;
	}
}

static void			ft_loop_wall_dda(t_ray_info *ray_info, \
										t_loop_info *info, int *x)
{
	if (info->side == 0)
		info->perp_wall_dist = \
		(info->map.x - ray_info->pos_x + (1 - info->step.x) / 2) / info->ray.x;
	else
		info->perp_wall_dist = \
		(info->map.y - ray_info->pos_y + (1 - info->step.y) / 2) / info->ray.y;
	info->line_height = (int)(ray_info->screen_y / info->perp_wall_dist);
	if (info->line_height < 0)
		info->line_height = INT_MAX;
	info->draw_start = (-info->line_height / 2) + (ray_info->screen_y / 2);
	if (info->draw_start < 0)
		info->draw_start = 0;
	info->draw_end = (info->line_height / 2) + (ray_info->screen_y / 2);
	if (info->draw_end >= ray_info->screen_y)
		info->draw_end = ray_info->screen_y - 1;
	(*x)++;
	ray_info->sp_dist[(*x)] = info->perp_wall_dist;
}

void				ft_loop_wall(t_ray_info *ray_info, t_loop_info *info)
{
	int				x;

	x = 0;
	while (x < ray_info->screen_x)
	{
		ft_loop_wall_info(ray_info, info, x);
		ft_loop_wall_dir(ray_info, info);
		ft_loop_wall_chk_dda(ray_info, info);
		ft_loop_wall_dda(ray_info, info, &x);
		ft_wall(ray_info, info, &x);
	}
}
