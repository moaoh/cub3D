/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:37:00 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/02 18:36:05 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"

static int		ft_map_chk(char	*line, t_map *map)
{
	// Resolution (해상도)
	if (ft_strncmp(line, "R ", 2))
		ft_map_resolution(line, map);
	// texure (파일같은 경우에는 char 형식으로 담아도 사용가능)
	else if (ft_strncmp(line, "NO ", 3))
		ft_map_texure(line, map);
	else if (ft_strncmp(line, "SO ", 3))
		ft_map_texure(line, map);
	else if (ft_strncmp(line, "WE ", 3))
		ft_map_texure(line, map);
	else if (ft_strncmp(line, "EA ", 3))
		ft_map_texure(line, map);
	// sprite
	else if (ft_strncmp(line, "S ", 2))
		ft_map_sprite(line, map);
	// color
	else if (ft_strncmp(line, "F ", 2))
		ft_map_color(line, map);
	else if (ft_strncmp(line, "C ", 2))
		ft_map_color(line, map);
	// map
	// else
		// ft_map(line, map);
	return (0);
}

int				ft_map_info(char *line, t_map *map)
{
	if (!(ft_map_chk(line, map)))
		return (_WRONG);
	return (0);
}
