/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:25:39 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 09:29:39 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "value_info.h"

static int		ft_texture_chk(char *str)
{
	if (!(str[0] == '.' && str[1] == '/'))
		ft_error("Invalid texture format");
	return (_RIGHT);
}

static int		ft_texture(char *s1, char *s2, t_map *map)
{
	if (!ft_strncmp(s1, "NO", 2) && ft_texture_chk(s2))
		map->texture.NO = s2;
	else if (!ft_strncmp(s1, "SO", 2) && ft_texture_chk(s2))
		map->texture.SO = s2;
	else if (!ft_strncmp(s1, "WE", 2) && ft_texture_chk(s2))
		map->texture.WE = s2;
	else if (!ft_strncmp(s1, "EA", 2) && ft_texture_chk(s2))
		map->texture.EA = s2;
	else
		ft_error("Invalid texture value.");
	return (_RIGHT);
}

int				ft_value_texture(char *line, t_map *map, int cub_chk)
{
	char	**str;

	if (cub_chk != 1)
		ft_error("duplicate texture value.");
	str = ft_split(line, ' ');
	ft_texture(str[0], str[1], map);
	free(str);
	free(str[0]);
	return (0);
}
