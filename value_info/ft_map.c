/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:38:55 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/25 17:05:21 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "value_info.h"

// 탭인경우 4칸

/*
// tap 처리.
static int			ft_chk_malloc(char *line)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			count += 4;
		else
			count++;
		i++;
	}
	return (count);
}

static char			*ft_line_chk(char *line)
{
	char		*temp;
	int			count;
	int			i;
	int			j;

	i = 0;
	j = 0;
	count = ft_chk_malloc(line);
	printf("%d\n", count);
	if (!(temp = (char *)malloc(sizeof(char) * count)))
		return (_WRONG);
	while (line[i])
	{
		if (line[i] == '\t')
		{
			temp[j] = ' ';
			temp[j + 1] = ' ';
			temp[j + 2] = ' ';
			temp[j + 3] = ' ';
			j += 3;
		}
		j++;
		i++;
	}
	return (temp);
}
*/

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
