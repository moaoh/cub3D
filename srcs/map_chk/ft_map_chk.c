/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_chk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:57:26 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/07 03:08:34 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_chk.h"

static int		ft_map_y_count(char *s, char c)
{
	int				i;
	int				count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void		ft_chk_validation(t_map *map, \
				char **chk_map, t_map_player *player, int y_size)
{
	int		i;
	int		j;
	int		len;
	int		sp_num;

	i = 0;
	sp_num = map->sp_count - 1;
	while (chk_map[++i])
	{
		j = 0;
		len = ft_strlen(chk_map[i]);
		while (++j < len && chk_map[i][j])
		{
			ft_map_value_chk(chk_map[i][j], i, j, player);
			ft_map_validity(chk_map, i, j, y_size);
			if (chk_map[i][j] == '2')
			{
				map->sp_pos[sp_num].y = i + 0.5;
				map->sp_pos[sp_num].x = j + 0.5;
				map->sp_pos[sp_num].type = chk_map[i][j];
				sp_num--;
			}
		}
	}
}

int				ft_sp_count(char **chk_map)
{
	int			i;
	int			j;
	int			len;
	int			count;

	i = 0;
	count = 0;
	while (chk_map[i])
	{
		j = 0;
		len = ft_strlen(chk_map[i]);
		while (j < len && chk_map[i][j])
		{
			if (chk_map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int				ft_map_chk(t_map *map)
{
	int		y_size;

	y_size = ft_map_y_count(map->map.buff, '\n');
	map->map.map = ft_split(map->map.buff, '\n');
	free(map->map.buff);
	map->sp_count = ft_sp_count(map->map.map);
	if (!(map->sp_pos = malloc(sizeof(t_sprite_pos) * map->sp_count)))
		ft_error("malloc error. map_chk");
	ft_chk_validation(map, map->map.map, &map->player, y_size);
	if (!map->player.dir)
		ft_error("have no dir.");
	return (0);
}
