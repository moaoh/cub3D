/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_change.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:26:14 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/04 05:09:52 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	ft_sprite_change(t_ray_info *ray_info, t_sprite_info *sp, int start, int end)
{
	int	temp;

	temp = 0;
	// while (temp <= end)
	// {
	// 	int texX = (int)((256 * (temp - (-sp->spriteWidth / 2 + sp->spriteScreenX)) * sp->texWidth / sp->spriteWidth) / 256);
	// 	temp++;
	// }
	// printf("%d\n", sp->drawEndX);
	// printf("%d %d\n", sp->drawStartX, sp->drawEndX);
	for(int stripe = sp->drawStartX; stripe < sp->drawEndX; stripe++)
	{
		int texX = (int)((256 * (stripe - (-sp->spriteWidth / 2 + sp->spriteScreenX)) * ray_info->img[5].width / sp->spriteWidth) / 256);
		//the conditions in the if are:
		//1) it's in front of camera plane so you don't see things behind you
		//2) it's on the screen (left)
		//3) it's on the screen (right)
		//4) ZBuffer, with perpendicular distance
		if(sp->transformY > 0 && stripe > 0 && stripe < ray_info->screen_X && sp->transformY < ray_info->SP_dist[stripe])
		for(int y = sp->drawStartY; y < sp->drawEndY; y++) //for every pixel of the current stripe
		{
			int d = (y-sp->vMoveScreen) * 256 - ray_info->img[5].height * 128 + sp->spriteHeight * 128; //256 and 128 factors to avoid floats
			int texY = ((d * ray_info->img[5].height) / sp->spriteHeight) / 256;
			// int color = ray_info->img[5].data[ray_info->img[5].width * texY + texX]; //get current color from the texture
			int color = 0xFFFFFF;
			// printf("%d %d %d %d\n", sp->drawStartX, sp->drawEndX, sp->drawStartY, sp->drawEndY);
			ft_my_mlx_pixel_put(ray_info->img[0], stripe, y, color);
			// if((color & 0x00FFFFFF) != 0) ray_info->img[5].data[stripe] = color; //paint pixel if it isn't black, black is the invisible color
		}
	}
}