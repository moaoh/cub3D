/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 06:01:10 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/27 14:51:15 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void			ft_my_mlx_pixel_put(t_img img, int y, int x, int color)
{
	img.data[y * (img.size_l / 4) + x] = color;
}

void			ft_texture_mapping(t_ray_info *ray_info, t_loop_info *info, t_img *img, t_img_calc *calc)
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

void			ft_img_change(t_ray_info *ray_info, t_loop_info *info, t_img *img, int start, int end)
{
	int			temp;
	t_img_calc	calc;

	ft_texture_mapping(ray_info, info, img, &calc);
	temp = start;
	while (temp <= end)
	{
		// img 대입.
		calc.img_y = (int)(img->height * calc.obj_y / info->lineHeight);
		calc.color = img->data[calc.img_y * (img->size_l / 4) + calc.img_x];
		
		if (start == 0 && end == info->drawStart - 1) calc.color = 0x1DA06A;
		else if (start == info->drawEnd && end == ray_info->screen_Y - 1) calc.color = 0xFFFFFF;
		ft_my_mlx_pixel_put(ray_info->imgs.main_img, temp, ray_info->img_x, calc.color);
		calc.obj_y++;
		temp++;
	}
}

void	ft_img(t_ray_info *ray_info, t_loop_info *info, int x)
{
	t_img img;

	ray_info->img_x = x;
	img = ft_img_map_chk(ray_info, info, x);
	// 기존 함수들 생성.
	ft_img_change(ray_info, info, &img, 0, info->drawStart - 1);
	ft_img_change(ray_info, info, &img, info->drawStart, info->drawEnd);
	ft_img_change(ray_info, info, &img, info->drawEnd, ray_info->screen_Y - 1);
}