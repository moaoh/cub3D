/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:38:55 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/27 23:55:53 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "value_info.h"

static char			*ft_get_singlemap(char *buff, char *line)
{
	char			**str;
	int				count;

	count = 0;
	buff = ft_strjoin(!(buff) ? "" : buff, line);
	return (buff);
}

int					ft_map(char *line, t_map *map)
{
	char			*s;

	s = "\n";
	line = ft_strjoin(line, s);
	map->map.buff = ft_get_singlemap(map->map.buff, line);
	return (0);
}
