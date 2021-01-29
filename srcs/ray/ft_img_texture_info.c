/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_texture_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 09:57:14 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/29 11:52:46 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void			ft_img_texture_chk(t_ray_info *ray_info)
{
	if (!ray_info->imgs.EA_img.img)
		ft_error("The EA file does not exist.");
	if (!ray_info->imgs.WE_img.img)
		ft_error("The WE file does not exist.");
	if (!ray_info->imgs.SO_img.img)
		ft_error("The SO file does not exist.");
	if (!ray_info->imgs.NO_img.img)
		ft_error("The NO file does not exist.");
	if (!ray_info->imgs.S_img.img)
		ft_error("The SP file does not exist.");
}

static void			ft_img_texture_putin(t_ray_info *ray_info, \
											char *texture, t_img *img)
{
	img->img = mlx_png_file_to_image(ray_info->mlx, texture, &img->width, &img->height);
	// img->img = mlx_xpm_file_to_image(ray_info->mlx, texture, &img->width, &img->height);
	img->data = \
	(int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
}

static void			ft_img_texture_type(t_ray_info *ray_info)
{
	ray_info->imgs.EA_img.type = 'E';
	ray_info->imgs.WE_img.type = 'W';
	ray_info->imgs.SO_img.type = 'S';
	ray_info->imgs.NO_img.type = 'N';
	ray_info->imgs.S_img.type = '2';
}

void				ft_img_texture_info(t_ray_info *ray_info)
{
	ft_img_texture_putin(ray_info, ray_info->texture.EA, &ray_info->imgs.EA_img);
	ft_img_texture_putin(ray_info, ray_info->texture.WE, &ray_info->imgs.WE_img);
	ft_img_texture_putin(ray_info, ray_info->texture.SO, &ray_info->imgs.SO_img);
	ft_img_texture_putin(ray_info, ray_info->texture.NO, &ray_info->imgs.NO_img);
	ft_img_texture_putin(ray_info, ray_info->texture.S, &ray_info->imgs.S_img);
	ft_img_texture_type(ray_info);
	ft_img_texture_chk(ray_info);
}