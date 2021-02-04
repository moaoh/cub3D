/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:38:55 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 08:08:25 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "value_info.h"

int					ft_map(char *line, t_map *map)
{
	char			*s;
	char			*temp;

	s = "\n";
	line = ft_strjoin(line, s); // x
	temp = ft_strjoin(!(map->map.buff) ? "" : map->map.buff, line);
	if (map->map.buff)
		free(map->map.buff);
	if (line)
		free(line);
	map->map.buff = temp;
	return (0);
}
