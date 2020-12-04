/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:38:55 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/04 19:03:17 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "value_info.h"

// 탭인경우 8칸

static int			ft_chk_newline(char *line)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while(line[i])
	{
		if (line[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

static int			ft_newline_point(char *buff, int num)
{
	int		count;

	count = 0;
	while (buff[num])
	{
		if (buff[num] == '\n')
			break ;
		num++;
		count++;
	}
	return (count);
}

// line이 새롭게 들어올때마다 기존에 있는 값을 폐기하고 새로운 값을 포함하여 새롭게 생성.
static char			*ft_get_Singlemap(char *buff, char *line)
{
	char		**str;
	int			count;

	count = 0;
	buff = ft_strjoin(!(buff) ? "" : buff, line);

	return (buff);
}

int					ft_map(char *line, t_map *map)
{
	char	*s;

	s = "\n";
	line = ft_strjoin(line, s);
	map->map.buff = ft_get_Singlemap(map->map.buff, line);

	return (0);
}
