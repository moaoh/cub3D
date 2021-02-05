/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_screen.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 06:55:26 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 09:56:47 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SAVE_SCREEN_H
#	define SAVE_SCREEN_H

#	include "../cub3d.h"

void	save_screen_chk(char *line, t_map *map);
void	save_screen(t_ray_info *ray_info);

#	endif
