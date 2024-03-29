/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_change.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:35:55 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 12:20:34 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray.h"

static void		ft_wall_mapping(t_ray_info *ray_info, t_loop_info *info, \
								t_img *img, t_img_calc *calc)
{
	if (info->side == 0)
		calc->obj_x = ray_info->pos_y + info->perp_wall_dist * info->ray.y;
	else
		calc->obj_x = ray_info->pos_x + info->perp_wall_dist * info->ray.x;
	calc->img_x = (int)(img->width * (calc->obj_x - floor(calc->obj_x)));
	if (img->type == 'E' || img->type == 'N')
		calc->img_x = img->width - calc->img_x - 1;
	calc->obj_y = 0;
	if (info->draw_start == 0)
		calc->obj_y = \
		(double)(info->line_height / 2) - (double)(ray_info->screen_y / 2);
}

static void		ft_cf(t_ray_info *ray_info, t_loop_info *info, \
						int start, int end)
{
	if (start == 0 && end == info->draw_start - 1)
	{
		info->calc.color = (ray_info->c_color.r << 16) | \
							(ray_info->c_color.g << 8) | ray_info->c_color.b;
	}
	else if (start == info->draw_end && end == ray_info->screen_y - 1)
	{
		info->calc.color = (ray_info->f_color.r << 16) | \
							(ray_info->f_color.g << 8) | ray_info->f_color.b;
	}
}

void			ft_wall_change(t_ray_info *ray_info, t_loop_info *info, \
								int start, int end)
{
	int			temp;
	t_img		*img;

	img = ft_map_wall(ray_info, info);
	ft_wall_mapping(ray_info, info, img, &info->calc);
	temp = start;
	while (temp <= end)
	{
		info->calc.img_y = \
		(int)(img->height * info->calc.obj_y / info->line_height);
		info->calc.color = img->data[info->calc.img_y * \
							(img->size_l / 4) + info->calc.img_x];
		ft_cf(ray_info, info, start, end);
		ft_my_mlx_pixel_put(ray_info->img[0], temp, \
							ray_info->img_x, info->calc.color);
		info->calc.obj_y++;
		temp++;
	}
}
