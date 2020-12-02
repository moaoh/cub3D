/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:29:23 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/02 17:08:17 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef	MAP_INFO_H
#	define	MAP_INFO_H

#	include "../cub3d.h"

int			ft_map_info(char *line, t_map *map);

int			ft_map_resolution(char *line, t_map *map);
int			ft_map_texure(char *line, t_map *map);
int			ft_map_sprite(char *line, t_map *map);
int			ft_map_color(char *line, t_map *map);

#	endif
