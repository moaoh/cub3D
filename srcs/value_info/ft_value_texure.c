/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_texure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:25:39 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/23 11:09:18 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "value_info.h"

static int		ft_texure_chk(char *str)
{
	if (!(str[0] == '.' && str[1] == '/'))
		ft_error("Invalid texure format");
	return (_RIGHT);
}

static int		ft_texure(char *s1, char *s2, t_map *map)
{
	if (!ft_strncmp(s1, "NO", 2) && ft_texure_chk(s2))
		map->texure.NO = ft_strdup(s2, ft_strlen(s2));
	else if (!ft_strncmp(s1, "SO", 2) && ft_texure_chk(s2))
		map->texure.SO = ft_strdup(s2, ft_strlen(s2));
	else if (!ft_strncmp(s1, "WE", 2) && ft_texure_chk(s2))
		map->texure.WE = ft_strdup(s2, ft_strlen(s2));
	else if (!ft_strncmp(s1, "EA", 2) && ft_texure_chk(s2))
		map->texure.EA = ft_strdup(s2, ft_strlen(s2));
	else
		ft_error("Invalid texure value.");
	return (_RIGHT);
}

int				ft_value_texure(char *line, t_map *map, int cub_chk)
{
	char	**str;

	if (cub_chk != 1)
		ft_error("duplicate texure value.");
	str = ft_split(line, ' ');
	ft_texure(str[0], str[1], map);
	return (0);
}
