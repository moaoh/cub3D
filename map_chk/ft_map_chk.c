/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_chk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:57:26 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/11 03:32:03 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_chk.h"

static int		ft_map_y_count(char *s, char c)
{
	int				i;
	int				count;
	int				x;

	count = 0;
	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int		ft_chk_validation(char **chk_map, t_map_player *player, int y_size)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (chk_map[i])
	{
		j = 0;
		len = ft_strlen(chk_map[i]);
		while (j < len && chk_map[i][j])
		{
			ft_map_value_chk(chk_map[i][j], i, j, player);
			ft_map_validity(chk_map, i, j, y_size);
			j++;
		}
		i++;
	}
	return (0);
}

int				ft_map_chk(t_map *map)
{
	int		y_size;

	// map->dir = ft_strdup("", 1);
	y_size = ft_map_y_count(map->map.buff, '\n');
	map->map.map = ft_split(map->map.buff, '\n');
	ft_chk_validation(map->map.map, &map->player, y_size);
	return (0);
}
