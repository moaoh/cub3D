/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_chk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:57:26 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/04 20:59:05 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_chk.h"

static int		ft_chk_num(char c)
{
	if (c != 1 && c != 0 && c != 2)
		return (1);
	return (0);
}

static char		ft_chk_user_Direction(char **map)
{
	int		i;
	int		j;
	char	temp;
	char	c;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		while (map[i][j])
		{
			printf("%c", temp);
			temp = map[i][j];
			if (ft_chk_num(temp))
				if (temp == 'N' || temp == 'S' || \
					temp == 'W' || temp == 'E')
				{
					if (!c)
						c = temp;
					else
						return (0);
				}
			j++;
		}
		j = 0;
		i++;
	}
	return (c);
}

int				ft_map_chk(char **map)
{
	char	c;
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(c = ft_chk_user_Direction(map)))
		return (_WRONG);
	return (0);
}
