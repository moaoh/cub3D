/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 03:36:35 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/04 07:25:35 by junmkang         ###   ########.fr       */
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
	// sprite의 위치정보를 담음. 
	while (sp_i < ray_info->SP_count)
	{
		ray_info->SP_pwd.spriteOrder[sp_i] = sp_i;
		ray_info->SP_pwd.spriteDistance[sp_i] = \
		(ray_info->pos_Y - ray_info->SP_pos[sp_i].y) * (ray_info->pos_Y - ray_info->SP_pos[sp_i].y) + \
		(ray_info->pos_X - ray_info->SP_pos[sp_i].x) * (ray_info->pos_X - ray_info->SP_pos[sp_i].x);
		sp_i++;
	}
	// 담은 내용들을 정렬하는 파트. (먼곳에서 가까운 곳.)
	sortsprites(ray_info->SP_pwd.spriteOrder, ray_info->SP_pwd.spriteDistance, ray_info->SP_count);
	
	sp_i = 0;
	while (sp_i < ray_info->SP_count)
	{
		// printf("%d : %lf\n", sp_i, ray_info->SP_pwd.spriteDistance[sp_i]);
		// 카메라를 기준으로 스프라이트.
		// 플레이어의 위치값을 기준으로 sprite가 정해지기때문에 이동하지않는 이상 값은 변하지않아야한다.
		sp->spriteX = ray_info->SP_pos[ray_info->SP_pwd.spriteOrder[sp_i]].x - ray_info->pos_X;
		sp->spriteY = ray_info->SP_pos[ray_info->SP_pwd.spriteOrder[sp_i]].y - ray_info->pos_Y;
		// printf("%lf %lf\n", ray_info->pos_Y, ray_info->pos_X);
		// printf("%lf %lf\n", ray_info->SP_pos[ray_info->SP_pwd.spriteOrder[sp_i]].y, ray_info->SP_pos[ray_info->SP_pwd.spriteOrder[sp_i]].x);
		// printf("%lf %lf\n", sp->spriteY, sp->spriteX);

		// 카메라 행렬. 계산에 필요한 부분. 플레이어가 회전하거나 이동하여도 값이 변하면 안되고,
		// 스프라이트가 항상 고정되게 바라보게 하기위한 부분.
		sp->invDet = 1.0 / (ray_info->plane_X * ray_info->dir_Y - ray_info->dir_X * ray_info->plane_Y);
		// printf("%lf\n", sp->invDet);
		
		// 플레이어와 sprite간에 상대적 위치 (?)
		sp->transformX = sp->invDet * (ray_info->dir_Y * sp->spriteX - ray_info->dir_X * sp->spriteY);
		sp->transformY = sp->invDet * (-ray_info->plane_Y * sp->spriteX + ray_info->plane_X * sp->spriteY);
		// if (sp->transformX == 0)
		// 	printf("%lf %lf %lf %lf\n", ray_info->plane_Y, sp->spriteX, ray_info->plane_X, sp->spriteY); 
		// printf("%lf %lf\n", sp->transformY, sp->transformX);
		
		sp->spriteScreenX = (int)((ray_info->screen_X / 2) * (1 + sp->transformX / sp->transformY)); // 문제가 생긴다면 이부분을 다시확인.
		
		sp->vMoveScreen = (int)(vMove / sp->transformY); // 문제가 생긴다면 이부분을 다시확인.

		sp->spriteHeight = (int)fabs((ray_info->screen_Y / sp->transformY) / vDiv); // 문제가 생긴다면 이부분을 다시확인.
		// printf("%d\n", sp->spriteHeight);
		// printf("%d %lf %f\n", ray_info->screen_Y, sp->transformY, fabs((ray_info->screen_Y / sp->transformY)));
		
		sp->drawStartY = -sp->spriteHeight / 2 + ray_info->screen_Y / 2 + sp->vMoveScreen;
		if(sp->drawStartY < 0) sp->drawStartY = 0;
		sp->drawEndY = sp->spriteHeight / 2 + ray_info->screen_Y / 2 + sp->vMoveScreen;
		if(sp->drawEndY >= ray_info->screen_Y) sp->drawEndY = ray_info->screen_Y - 1;

		// printf("%d %d\n", sp->drawStartY, sp->drawEndY);

		sp->spriteWidth = (int)fabs((ray_info->screen_Y / sp->transformY) / uDiv); // 문제가 생긴다면 이부분을 다시확인.
		sp->drawStartX = -sp->spriteWidth / 2 + sp->spriteScreenX;
		if(sp->drawStartX < 0) sp->drawStartX = 0;
		sp->drawEndX = sp->spriteWidth / 2 + sp->spriteScreenX;
		if(sp->drawEndX >= ray_info->screen_X) sp->drawEndX = ray_info->screen_X - 1;

		// printf("%d %d\n", sp->drawStartX, sp->drawEndX);
		// printf("%d %d %d %d\n", sp->drawStartX, sp->drawEndX, sp->drawStartY, sp->drawEndY);
		ft_sprite(ray_info, sp);

		sp_i++;
	}
}