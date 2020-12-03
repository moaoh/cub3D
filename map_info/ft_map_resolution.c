/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:26:50 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/03 19:04:03 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"

static int			ft_resolution_chk(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (_WRONG);
		i++;
	}
	return (1);
}

int					ft_map_resolution(char *line, t_map *map, int cub_chk)
{
	char		**str;

	str = ft_split(line, ' ');
	if (cub_chk != 1 || ft_strlen(str[0]) != 1 || str[3] != '\0')
	{
		if (cub_chk != 1)
			perror("duplicate resolution value.");
		else
			perror("Invalid resolution value.");
		exit(0);
	}
	if (!(ft_resolution_chk(str[1])) || \
		!(ft_resolution_chk(str[2])))
	{
		perror("Invalid resolution value.2");
		exit(0);
	}
	else
	{
		map->resolution.R_X = ft_atoi(str[1]);
		map->resolution.R_Y = ft_atoi(str[2]);
	}
	return (0);
}
