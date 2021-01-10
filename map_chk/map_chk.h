/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chk.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:57:40 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/11 03:32:53 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MAP_CHK_H
#	define MAP_CHK_H

#	include "../cub3d.h"

int		ft_chk_map_null(char c);

int		*ft_map_value_chk(char c, int i, int j, t_map_player *player);
int		ft_map_validity(char **chk_map, int i, int j, int y_size);

int		ft_map_chk(t_map *map);

#	endif
