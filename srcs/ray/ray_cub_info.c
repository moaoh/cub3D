/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cub_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 06:10:59 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 10:37:15 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void			player_dir(t_ray_info *info, char dir)
{
	if (dir == 'E')
	{
		info->dir_y = 0;
		info->dir_x = +1;
	}
	else if (dir == 'W')
	{
		info->dir_y = 0;
		info->dir_x = -1;
	}
	else if (dir == 'N')
	{
		info->dir_y = -1;
		info->dir_x = 0;
	}
	else if (dir == 'S')
	{
		info->dir_y = +1;
		info->dir_x = 0;
	}
}

void			player_plane(t_ray_info *info, char dir)
{
	if (dir == 'E')
	{
		info->plane_y = -0.66;
		info->plane_x = 0;
	}
	else if (dir == 'W')
	{
		info->plane_y = 0.66;
		info->plane_x = 0;
	}
	else if (dir == 'N')
	{
		info->plane_y = 0;
		info->plane_x = -0.66;
	}
	else if (dir == 'S')
	{
		info->plane_y = 0;
		info->plane_x = +0.66;
	}
}

void			ray_map_info(t_ray_info *info, t_map *map)
{
	info->map = map->map.map;
	info->c_color.r = map->c_color.r;
	info->c_color.g = map->c_color.g;
	info->c_color.b = map->c_color.b;
	info->f_color.r = map->f_color.r;
	info->f_color.g = map->f_color.g;
	info->f_color.b = map->f_color.b;
	info->texture.ea = map->texture.ea;
	info->texture.we = map->texture.we;
	info->texture.so = map->texture.so;
	info->texture.no = map->texture.no;
	info->texture.s = map->sprite.s;
}

void			ray_sp_info(t_ray_info *info, t_map *map)
{
	int			i;

	i = 0;
	info->sp_count = map->sp_count;
	info->sp_pos = malloc(sizeof(t_sprite_pos) * info->sp_count + 1);
	while (i < info->sp_count)
	{
		info->sp_pos[i].y = map->sp_pos[i].y;
		info->sp_pos[i].x = map->sp_pos[i].x;
		info->sp_pos[i].type = map->sp_pos[i].type;
		i++;
	}
	free(map->sp_pos);
}

void			ray_cub_info(t_ray_info *info, t_map *map)
{
	info->save_bool = map->save_bool;
	info->screen_y = map->screen.y;
	info->screen_x = map->screen.x;
	info->pos_y = map->player.y + 0.5;
	info->pos_x = map->player.x + 0.5;
}
