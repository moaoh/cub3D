/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:29:03 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/03 19:03:36 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"

static char			*ft_color_chk(char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		perror("Invalid color value.");
		exit(0);
	}
	while(str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (_WRONG);
		i++;
	}
	return (str);
}

static int			ft_map_inc(char **num, t_map *map)
{
	if (!(ft_color_chk(num[0])) || \
		!(ft_color_chk(num[1])) || \
		!(ft_color_chk(num[2])))
	{
		perror("Invalid color value.");
		exit(0);
	}
	else
	{
		map->c_color.R = ft_atoi(num[0]);
		map->c_color.G = ft_atoi(num[1]);
		map->c_color.B = ft_atoi(num[2]);
	}

	return (_RIGHT);
}

static int			ft_map_inf(char **num, t_map *map)
{
	if (!(ft_color_chk(num[0])) || \
		!(ft_color_chk(num[1])) || \
		!(ft_color_chk(num[2])))
	{
		perror("Invalid color value.");
		exit(0);
	}
	else
	{
		map->f_color.R = ft_atoi(num[0]);
		map->f_color.G = ft_atoi(num[1]);
		map->f_color.B = ft_atoi(num[2]);
	}

	return (_RIGHT);
}

int					ft_map_color(char *line, t_map *map, int cub_chk)
{
	char	**str;
	char	**num;

	if (cub_chk != 1)
	{
		perror("duplicate color value.");
		exit(0);
	}
	str = ft_split(line, ' ');
	num = ft_split(str[1], ',');
	if (!(ft_strncmp(str[0], "F", 1)))
		ft_map_inf(num, map);
	else if (!(ft_strncmp(str[0], "C", 1)))
		ft_map_inc(num, map);
	else
	{
		perror("Invalid color value.");
		exit(0);
	}
	return (0);
}
