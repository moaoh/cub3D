/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_chk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:57:26 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/26 02:09:52 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_chk.h"

// map 유효성 검사 
static int		ft_chk_validation(char **chk_map, char *dir)
{
	int		i;
	int		j;
	int		len;
	
	i = 0;
	while(chk_map[i])
	{
		j = 0;
		len = ft_strlen(chk_map[i]);
		while(j < len && chk_map[i][j])
		{
			ft_map_value_chk(chk_map[i][j], dir);
			// ft_map_validity(chk_map, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int				ft_map_chk(t_map *map)
{
	char	c;
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	// map->dir = ft_strdup("", 1);
	map->map.map = ft_split(map->map.buff, '\n');
	ft_chk_validation(map->map.map, &map->dir);
	return (0);
}
