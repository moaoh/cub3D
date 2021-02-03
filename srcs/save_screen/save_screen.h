/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_screen.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 06:55:26 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/03 09:03:37 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SAVES_CREEN_H
#	define SAVES_CREEN_H

#	include "../cub3d.h"

void	save_screen_chk(char *line, t_map *map);
void	save_screen(t_ray_info *ray_info);

#	endif