/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:29:03 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 09:59:49 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "value_info.h"

static char			*ft_color_chk(char *str)
{
	int		i;

	i = 0;
	if (!str)
		ft_error("Invalid color value.");
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (_WRONG);
		i++;
	}
	return (str);
}

static int			ft_value_inc(char **num, t_map *map)
{
	if (!(ft_color_chk(num[0])) || \
		!(ft_color_chk(num[1])) || \
		!(ft_color_chk(num[2])))
		ft_error("Invalid color value.");
	else
	{
		map->c_color.r = ft_atoi(num[0]);
		map->c_color.g = ft_atoi(num[1]);
		map->c_color.b = ft_atoi(num[2]);
	}
	return (_RIGHT);
}

static int			ft_value_inf(char **num, t_map *map)
{
	if (!(ft_color_chk(num[0])) || \
		!(ft_color_chk(num[1])) || \
		!(ft_color_chk(num[2])))
		ft_error("Invalid color value.");
	else
	{
		map->f_color.r = ft_atoi(num[0]);
		map->f_color.g = ft_atoi(num[1]);
		map->f_color.b = ft_atoi(num[2]);
	}
	return (_RIGHT);
}

int					ft_value_color(char *line, t_map *map, int cub_chk)
{
	char	**str;
	char	**num;

	if (cub_chk != 1)
		ft_error("duplicate color value.");
	str = ft_split(line, ' ');
	num = ft_split(str[1], ',');
	if (!(ft_strncmp(str[0], "F", 1)))
		ft_value_inf(num, map);
	else if (!(ft_strncmp(str[0], "C", 1)))
		ft_value_inc(num, map);
	else
		ft_error("Invalid color value.");
	ft_value_free(str);
	ft_value_free(num);
	return (0);
}
