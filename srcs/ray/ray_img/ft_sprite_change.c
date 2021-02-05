/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_change.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:26:14 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 10:44:58 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray.h"

static void	ft_sprite_draw_y(t_ray_info *ray_info, t_img *img, \
							t_sprite_info *sp, int x)
{
	int		y;
	int		color;

	y = sp->draw_start_y;
	while (y < sp->draw_end_y)
	{
		sp->d = \
		(y - sp->v_move_screen) * 256 - ray_info->screen_y * 128 + \
		sp->sprite_height * 128;
		sp->tex_y = ((sp->d * img->height) / sp->sprite_height) / 256;
		color = img->data[img->width * sp->tex_y + sp->tex_x];
		if ((color & 0x00FFFFFF) != 0)
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
	x = sp->draw_start_x;
	while (x <= sp->draw_end_x)
	{
		sp->tex_x = \
			(int)((256 * (x - (-sp->sprite_width / 2 + sp->sprite_screen_x)) * \
				img->width / sp->sprite_width) / 256);
		if (sp->transform_y > 0 && x > 0 && \
			x < ray_info->screen_x && sp->transform_y < ray_info->sp_dist[x])
			ft_sprite_draw_y(ray_info, img, sp, x);
		x++;
	}
}
