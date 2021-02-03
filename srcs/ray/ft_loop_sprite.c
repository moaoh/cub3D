/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 03:36:35 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/03 09:23:22 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void		sort_order(t_pair *orders, int sp_count)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < sp_count)
	{
		j = 0;
		while (j < sp_count - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

void		sortsprites(int *order, double *dist, int sp_count)
{
	int		i;
	t_pair	*sprites;
	
	i = 0;
	sprites = (t_pair*)malloc(sizeof(t_pair) * sp_count);
	while (i < sp_count)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	sort_order(sprites, sp_count);
	i = 0;
	while (i < sp_count)
	{
		dist[i] = sprites[sp_count - i - 1].first;
		order[i] = sprites[sp_count - i - 1].second;
		i++;
	}
	free(sprites);
}

void		ft_loop_sprite(t_ray_info *ray_info, t_sprite_info *sp)
{
	int		sp_i;

	sp_i = 0;
	while (sp_i < ray_info->SP_count)
	{
		ray_info->SP_pwd.spriteOrder[sp_i] = sp_i;
		ray_info->SP_pwd.spriteDistance[sp_i] = \
		(ray_info->pos_Y - ray_info->SP_pos[sp_i].y) * (ray_info->pos_Y - ray_info->SP_pos[sp_i].y) + \
		(ray_info->pos_X - ray_info->SP_pos[sp_i].x) * (ray_info->pos_X - ray_info->SP_pos[sp_i].x);
		sp_i++;
	}
	sortsprites(ray_info->SP_pwd.spriteOrder, ray_info->SP_pwd.spriteDistance, ray_info->SP_count);
	sp_i = 0;
	while (sp_i < ray_info->SP_count)
	{
		sp->spriteY = ray_info->SP_pos[ray_info->SP_pwd.spriteOrder[sp_i]].y - ray_info->pos_Y;
		sp->spriteX = ray_info->SP_pos[ray_info->SP_pwd.spriteOrder[sp_i]].x - ray_info->pos_X;

		sp->invDet = 1.0 / (ray_info->plane_Y * ray_info->dir_Y - ray_info->dir_X * ray_info->plane_X);

		sp->transformY = sp->invDet * (-ray_info->plane_Y * sp->spriteX + ray_info->plane_X * sp->spriteY);
		sp->transformX = sp->invDet * (ray_info->dir_Y * sp->spriteX - ray_info->dir_X * sp->spriteY);

		sp->spriteScreenX = (int)((ray_info->screen_X / 2) * (1 + sp->transformX / sp->transformY));
		
		sp->vMoveScreen = (int)(vMove / sp->transformY);
		
		sp->spriteHeight = (int)fabs((ray_info->screen_Y / sp->transformY) / vDiv);
		sp->drawStartY = -sp->spriteHeight / 2 + ray_info->screen_Y / 2 + sp->vMoveScreen;
		if(sp->drawStartY < 0) sp->drawStartY = 0;
		sp->drawEndY = sp->spriteHeight / 2 + ray_info->screen_Y / 2 + sp->vMoveScreen;
		if(sp->drawEndY >= ray_info->screen_Y) sp->drawEndY = ray_info->screen_Y - 1;

		sp->spriteWidth = (int)fabs((ray_info->screen_Y / sp->transformY) / uDiv);
		sp->drawStartX = -sp->spriteWidth / 2 + sp->spriteScreenX;
		if(sp->drawStartX < 0) sp->drawStartX = 0;
		sp->drawEndX = sp->spriteWidth / 2 + sp->spriteScreenX;
		if(sp->drawEndX >= ray_info->screen_X) sp->drawEndX = ray_info->screen_X - 1;
		sp_i++;
	}
}