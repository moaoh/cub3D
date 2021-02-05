/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 03:36:35 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 10:54:20 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ray.h"

/*
** transform sprite with the inverse camera matrix (sp->inv_det)
** [ planeX   dirX ] -1                               [ dirY      -dirX ]
** [               ] =  1/(planeX*dirY-dirX*planeY) * [                 ]
** [ planeY   dirY ]                                  [ -planeY  planeX ]
*/

static void		ft_loop_sprite_value(t_ray_info *ray_info, \
									t_sprite_info *sp, int *sp_i)
{
	sp->sprite_x = \
	ray_info->sp_pos[ray_info->sp_pwd.sprite_order[(*sp_i)]].x - \
	ray_info->pos_x;
	sp->sprite_y = \
	ray_info->sp_pos[ray_info->sp_pwd.sprite_order[(*sp_i)]].y - \
	ray_info->pos_y;
	sp->inv_det = 1.0 / (ray_info->plane_x * ray_info->dir_y - \
						ray_info->dir_x * ray_info->plane_y);
	sp->transform_x = sp->inv_det * (ray_info->dir_y * sp->sprite_x - \
									ray_info->dir_x * sp->sprite_y);
	sp->transform_y = sp->inv_det * (-ray_info->plane_y * sp->sprite_x + \
									ray_info->plane_x * sp->sprite_y);
	sp->sprite_screen_x = \
	(int)((ray_info->screen_x / 2) * \
	(1 + sp->transform_x / sp->transform_y));
	sp->v_move_screen = (int)(_VMOVE / sp->transform_y);
}

static void		ft_loop_sprite_draw(t_ray_info *ray_info, \
									t_sprite_info *sp, int *sp_i)
{
	sp->sprite_height = \
	(int)fabs((ray_info->screen_y / sp->transform_y) / _VDIR);
	sp->draw_start_y = \
	-sp->sprite_height / 2 + ray_info->screen_y / 2 + sp->v_move_screen;
	if (sp->draw_start_y < 0)
		sp->draw_start_y = 0;
	sp->draw_end_y = \
	sp->sprite_height / 2 + ray_info->screen_y / 2 + sp->v_move_screen;
	if (sp->draw_end_y >= ray_info->screen_y)
		sp->draw_end_y = ray_info->screen_y - 1;
	sp->sprite_width = \
	(int)fabs((ray_info->screen_y / sp->transform_y) / _UDIR);
	sp->draw_start_x = -sp->sprite_width / 2 + sp->sprite_screen_x;
	if (sp->draw_start_x < 0)
		sp->draw_start_x = 0;
	sp->draw_end_x = sp->sprite_width / 2 + sp->sprite_screen_x;
	if (sp->draw_end_x >= ray_info->screen_x)
		sp->draw_end_x = ray_info->screen_x - 1;
}

void			ft_loop_sprite(t_ray_info *ray_info, t_sprite_info *sp)
{
	int			sp_i;

	ft_loop_sprite_info(ray_info, sp);
	sp_i = 0;
	while (sp_i < ray_info->sp_count)
	{
		ft_loop_sprite_value(ray_info, sp, &sp_i);
		ft_loop_sprite_draw(ray_info, sp, &sp_i);
		ft_sprite(ray_info, sp);
		sp_i++;
	}
}
