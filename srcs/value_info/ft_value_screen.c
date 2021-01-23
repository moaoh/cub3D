/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:26:50 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/23 10:24:51 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "value_info.h"

static int			ft_screen_chk(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (_WRONG);
		i++;
	}
	return (1);
}

// 해상도의 최대범위를 정해서 막는 파트를 따로 만들어줘야함.
int					ft_value_screen(char *line, t_map *map, int cub_chk)
{
	char		**str;

	str = ft_split(line, ' ');
	if (cub_chk != 1 || ft_strlen(str[0]) != 1 || str[3] != NULL)
	{
		if (cub_chk != 1)
			ft_error("duplicate screen value.");
		else
			ft_error("Invalid screen value.");
	}
	if (!(ft_screen_chk(str[1])) || \
		!(ft_screen_chk(str[2])))
		ft_error("Invalid screen value.2");
	else
	{
		map->screen.X = ft_atoi(str[1]);
		map->screen.Y = ft_atoi(str[2]);
	}
	return (0);
}
