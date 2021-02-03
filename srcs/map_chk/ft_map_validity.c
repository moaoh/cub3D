/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:42:46 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/03 08:59:00 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_chk.h"

static void		in_num(int *nx, int *ny)
{
	nx[0] = 0;
	nx[1] = 1;
	nx[2] = 0;
	nx[3] = -1;
	ny[0] = 1;
	ny[1] = 0;
	ny[2] = -1;
	ny[3] = 0;
}

int				ft_map_validity(char **chk_map, int i, int j, int y_size)
{
	int			nx[4];
	int			ny[4];
	int			k;
	int			x;
	int			y;

	in_num(nx, ny);
	if (chk_map[i][j] != '1' && !ft_chk_map_null(chk_map[i][j]))
	{
		k = 3;
		while (k >= 0)
		{
			y = i + ny[k];
			x = j + nx[k];
			if (y < 0 || x < 0 || (size_t)(x) >= ft_strlen(chk_map[i]) || y >= y_size || \
				!chk_map[y][x] || chk_map[y][x] == ' ')
				ft_error("Invalid map format.");
			k--;
		}
	}
	return (0);
}
