/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:42:46 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/27 03:23:46 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_chk.h"

// 유효성 검사 파트.
int		ft_map_validity(char **chk_map, int i, int j, int y_size)
{
	int		nx[4] = {0, 1, 0, -1};
	int		ny[4] = {1, 0, -1, 0};
	int		k;
	int		x;
	int		y;
	
	if (chk_map[i][j] != '1' && !ft_chk_map_null(chk_map[i][j]))
	{
		k = 3;
		while (k >= 0)
		{
			y = i + ny[k];
			x = j + nx[k];
			if (y < 0 || x < 0 || \
				x >= ft_strlen(chk_map[i]) || y >= y_size)
			{
				perror("Invalid map format.");
				exit(0);
			}
			else 
				if (!chk_map[y][x] || chk_map[y][x] == ' ')
				{
					perror("Invalid map format.");
					exit(0);
				}
			k--;
		}
		
	}
	return (0);
}