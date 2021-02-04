/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cub_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 06:10:59 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 03:04:51 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void			player_dir(t_ray_info *info, char dir)
{
	if (dir == 'E')
	{
		info->dir_Y = 0;
		info->dir_X = +1;
	}
	else if (dir == 'W')
	{
		info->dir_Y = 0;
		info->dir_X = -1;
	}
	else if (dir == 'N')
	{
		info->dir_Y = -1;
		info->dir_X = 0;
	}
	else if (dir == 'S')
	{
		info->dir_Y = +1;
		info->dir_X = 0;
	}
}

void			player_plane(t_ray_info *info, char dir)
{
	if (dir == 'E')
	{
		info->plane_Y = -0.66;
		info->plane_X = 0;
	}
	else if (dir == 'W')
	{
		info->plane_Y = 0.66;
		info->plane_X = 0;
	}
	else if (dir == 'N')
	{
		info->plane_Y = 0;
		info->plane_X = -0.66;
	}
	else if (dir == 'S')
	{
		info->plane_Y = 0;
		info->plane_X = +0.66;
	}
}

void			ray_map_info(t_ray_info *info, t_map *map)
{
	info->map = map->map.map;

	info->c_color.R = map->c_color.R;
	info->c_color.G = map->c_color.G;
	info->c_color.B = map->c_color.B;
	info->f_color.R = map->f_color.R;
	info->f_color.G = map->f_color.G;
	info->f_color.B = map->f_color.B;
	
	info->texture.EA = map->texture.EA;
	info->texture.WE = map->texture.WE;
	info->texture.SO = map->texture.SO;
	info->texture.NO = map->texture.NO;
	info->texture.S = map->sprite.S;

	// free(map->map.map);
}

void			ray_sp_info(t_ray_info *info, t_map *map)
{
	int			i;

	i = 0;
	info->SP_count = map->SP_count;
	info->SP_pos = malloc(sizeof(t_sprite_pos) * info->SP_count + 1);
	while (i < info->SP_count)
	{
		info->SP_pos[i].y = map->SP_pos[i].y;
		info->SP_pos[i].x = map->SP_pos[i].x;
		info->SP_pos[i].type = map->SP_pos[i].type;
		i++;
	}
	free(map->SP_pos);
}

void			ray_cub_info(t_ray_info *info, t_map *map)
{
	info->save_bool = map->save_bool;

	info->screen_Y = map->screen.Y;
	info->screen_X = map->screen.X;
	info->pos_Y = map->player.y + 0.5;
	info->pos_X = map->player.x + 0.5;
}