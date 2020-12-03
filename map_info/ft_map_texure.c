/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_texure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:25:39 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/03 15:05:13 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"

// strcpy()
static int		ft_texure_chk(char *str)
{
	if (!(str[0] == '.' && str[1] == '/'))
	{
		perror("Invalid texure format");
		exit(0);
	}
	return (_RIGHT);
}

// 길이를 잡는 조건도 추가를 해서 반례를 잡아줘야함
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
	{
		perror("Invalid texure value.");
		exit(0);
	}
	return (_RIGHT);
}

int				ft_map_texure(char *line, t_map *map, int cub_chk)
{
	char	**str;

	if (cub_chk != 1)
	{
		perror("Invalid texure value.");
		exit(0);
	}
	str = ft_split(line, ' ');
	ft_texure(str[0], str[1], map);

	return (0);
}
