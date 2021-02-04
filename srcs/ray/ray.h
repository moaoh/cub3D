/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 23:36:11 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/04 23:48:15 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RAY_H
#	define RAY_H

#	include "../cub3d.h"
#	include "ray_struct.h"
#	include "press.h"

#	define uDiv 1
#	define vDiv 1
#	define vMove 0.0

/*
** cub3d --------------------------------------------------
*/

int			cub3d(t_map map);

/*
** ft_img_texture_info ----------------------------------------------
*/

void		ft_img_texture_info(t_ray_info *ray_info);

/*
** ft_press ---------------------------------------------------------
*/

int			key_press(int key, t_ray_info *info);
int			screen_close(void);

/*
** ft_max_screen_chk ------------------------------------------------
*/

void		ft_max_screen_chk(t_ray_info *info, t_map *map);

/*
** ray_putin_info -----------------------------------------
*/

void		player_dir(t_ray_info *info, char dir);
void		player_plane(t_ray_info *info, char dir);
void		ray_map_info(t_ray_info *info, t_map *map);
void		ray_sp_info(t_ray_info *info, t_map *map);
void		ray_cub_info(t_ray_info *info, t_map *map);

/*
** main_loop ----------------------------------------------
*/

int		main_loop(t_ray_info *ray_info);

/*
** ft_loop_sprite ----------------------------------------------
*/

void	ft_loop_sprite(t_ray_info *ray_info, t_sprite_info *sp);

/*
** change ----------------------------------------------------
*/

void	ft_wall_change(t_ray_info *ray_info, t_loop_info *info, int start, int end);
void	ft_sprite_change(t_ray_info *ray_info, t_sprite_info *sp);

/*
** ft_img_map_chk ---------------------------------------------------
*/

t_img	*ft_map_wall(t_ray_info *ray_info, t_loop_info *info);
t_img	*ft_map_sprite(t_ray_info *ray_info);

/*
** ft_loop_wall ----------------------------------------------------
*/

void	ft_loop_wall(t_ray_info *ray_info, t_loop_info *info);

/*
** ft_loop_sprite ----------------------------------------------------
*/

void		ft_loop_sprite_info(t_ray_info *ray_info, t_sprite_info *sp);

/*
** ft_img -----------------------------------------------------------
*/

void	ft_my_mlx_pixel_put(t_img img, int y, int x, int color);
void	ft_wall(t_ray_info *ray_info, t_loop_info *info, int *x);
void	ft_sprite(t_ray_info *ray_info, t_sprite_info *sp);

#	endif