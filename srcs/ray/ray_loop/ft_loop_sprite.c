/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 03:36:35 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 00:04:52 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray.h"

/*
** transform sprite with the inverse camera matrix (sp->invDet)
** [ planeX   dirX ] -1                               [ dirY      -dirX ]
** [               ] =  1/(planeX*dirY-dirX*planeY) * [                 ]
** [ planeY   dirY ]                                  [ -planeY  planeX ]
*/

static void		ft_loop_sprite_value \
				(t_ray_info *ray_info, t_sprite_info *sp, int *sp_i)
{
	sp->spriteX = \
	ray_info->SP_pos[ray_info->SP_pwd.spriteOrder[(*sp_i)]].x - ray_info->pos_X;
	sp->spriteY = \
	ray_info->SP_pos[ray_info->SP_pwd.spriteOrder[(*sp_i)]].y - ray_info->pos_Y;
	sp->invDet = 1.0 / (ray_info->plane_X * ray_info->dir_Y - \
						ray_info->dir_X * ray_info->plane_Y);
	sp->transformX = sp->invDet * (ray_info->dir_Y * sp->spriteX - \
									ray_info->dir_X * sp->spriteY);
	sp->transformY = sp->invDet * (-ray_info->plane_Y * sp->spriteX + \
									ray_info->plane_X * sp->spriteY);
	sp->spriteScreenX = \
	(int)((ray_info->screen_X / 2) * \
	(1 + sp->transformX / sp->transformY));
	sp->vMoveScreen = (int)(vMove / sp->transformY);
}

static void		ft_loop_sprite_draw \
				(t_ray_info *ray_info, t_sprite_info *sp, int *sp_i)
{
	sp->spriteHeight = (int)fabs((ray_info->screen_Y / sp->transformY) / vDiv);
	sp->drawStartY = \
	-sp->spriteHeight / 2 + ray_info->screen_Y / 2 + sp->vMoveScreen;
	if (sp->drawStartY < 0)
		sp->drawStartY = 0;
	sp->drawEndY = \
	sp->spriteHeight / 2 + ray_info->screen_Y / 2 + sp->vMoveScreen;
	if (sp->drawEndY >= ray_info->screen_Y)
		sp->drawEndY = ray_info->screen_Y - 1;
	sp->spriteWidth = (int)fabs((ray_info->screen_Y / sp->transformY) / uDiv);
	sp->drawStartX = -sp->spriteWidth / 2 + sp->spriteScreenX;
	if (sp->drawStartX < 0)
		sp->drawStartX = 0;
	sp->drawEndX = sp->spriteWidth / 2 + sp->spriteScreenX;
	if (sp->drawEndX >= ray_info->screen_X)
		sp->drawEndX = ray_info->screen_X - 1;
}

void			ft_loop_sprite(t_ray_info *ray_info, t_sprite_info *sp)
{
	int			sp_i;

	ft_loop_sprite_info(ray_info, sp);
	sp_i = 0;
	while (sp_i < ray_info->SP_count)
	{
		ft_loop_sprite_value(ray_info, sp, &sp_i);
		ft_loop_sprite_draw(ray_info, sp, &sp_i);
		ft_sprite(ray_info, sp);
		sp_i++;
	}
}
