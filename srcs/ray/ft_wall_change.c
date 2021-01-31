/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_change.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:35:55 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/31 16:52:49 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void		ft_wall_mapping(t_ray_info *ray_info, t_loop_info *info, t_img *img, t_img_calc *calc)
{
	if (info->side == 0)
		calc->obj_x = ray_info->pos_X + info->perpWallDist * info->ray.X;
	else
		calc->obj_x = ray_info->pos_Y + info->perpWallDist * info->ray.Y;
	calc->img_x = (int)(img->width * (calc->obj_x - floor(calc->obj_x)));

	// e or n
	if (img->type == 'E' || img->type == 'N')
		calc->img_x = img->width - calc->img_x - 1;

	calc->obj_y = 0;
	if (info->drawStart == 0)
		calc->obj_y = (double)(info->lineHeight / 2) - (double)(ray_info->screen_Y / 2);
}

static void		ft_cf(t_ray_info *ray_info, t_loop_info *info, t_img_calc *calc, int start, int end)
{
	// 천장.
	if (start == 0 && end == info->drawStart - 1)
	{
		calc->color = (ray_info->c_color.R << 16)  | (ray_info->c_color.G << 8) | ray_info->c_color.B;
	}
	// 바닥.
	else if (start == info->drawEnd && end == ray_info->screen_Y - 1)
	{
		calc->color = (ray_info->f_color.R << 16) | (ray_info->f_color.G << 8) | ray_info->f_color.B;
	}
}

void			ft_wall_change(t_ray_info *ray_info, t_loop_info *info, t_img *img, int start, int end)
{
	int			temp;
	t_img_calc	calc;

	ft_wall_mapping(ray_info, info, img, &calc);
	temp = start;
	while (temp <= end)
	{
		// img 대입.
		calc.img_y = (int)(img->height * calc.obj_y / info->lineHeight);
		calc.color = img->data[calc.img_y * (img->size_l / 4) + calc.img_x];
		
		ft_cf(ray_info, info, &calc, start, end);
		ft_my_mlx_pixel_put(ray_info->img[0], temp, ray_info->img_x, calc.color);
		calc.obj_y++;
		temp++;
	}
}