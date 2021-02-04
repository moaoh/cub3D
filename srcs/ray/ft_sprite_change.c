/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_change.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:26:14 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/04 07:46:26 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	ft_sprite_draw_Y(t_ray_info *ray_info, t_img *img, t_sprite_info *sp, int x)
{
	int 	y;
	int		color;

	y = sp->drawStartY;
	while (y < sp->drawEndY)
	{
		sp->d = (y - sp->vMoveScreen) * 256 - ray_info->screen_Y * 128 + sp->spriteHeight * 128;
		sp->texY = ((sp->d * img->height) / sp->spriteHeight) / 256;
		color = img->data[img->width * sp->texY + sp->texX];
		if((color & 0x00FFFFFF) != 0)
			ft_my_mlx_pixel_put(ray_info->img[0], y, x, color);
		y++;
	}
}

void		ft_sprite_change(t_ray_info *ray_info, t_sprite_info *sp)
{
	int		x;
	int		y;
	int		color;
	t_img	*img;

	img = ft_map_sprite(ray_info);
	x = sp->drawStartX;
	while (x <= sp->drawEndX)
	{
		sp->texX = \
			(int)((256 * (x - (-sp->spriteWidth / 2 + sp->spriteScreenX)) * \
				img->width / sp->spriteWidth) / 256);
		if(sp->transformY > 0 && x > 0 && \
			x < ray_info->screen_X && sp->transformY < ray_info->SP_dist[x])
			ft_sprite_draw_Y(ray_info, img, sp, x);
		x++;
	}
}