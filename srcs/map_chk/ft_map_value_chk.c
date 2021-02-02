/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_value_chk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:05:50 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/03 05:21:50 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_chk.h"

static int		ft_chk_map_num(char c)
{
	if (c == '1' || c == '0' || c == '2')
		return (1);
	return (0);
}

static int		ft_chk_map_player(char c)
{
	if (c == 'E' || c == 'W' || c == 'N' || c == 'S')
		return (1);
	return (0);
}

int				ft_chk_map_null(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int				*ft_map_value_chk(char c, int i, int j, t_map_player *player)
{
	if (ft_chk_map_player(c))
	{
		if (!ft_chk_map_player(player->dir))
		{
			player->dir = c;
			player->y = i;
			player->x = j;
		}
		else
			ft_error("Multiple Direction Values.");
	}
	else if (!ft_chk_map_num(c) && !ft_chk_map_player(c) && !ft_chk_map_null(c))
	{
		printf("map value = %c\n", c);
		ft_error("Invalid map value.");
	}
	return (0);
}
