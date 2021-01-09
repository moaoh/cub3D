/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_value_chk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:05:50 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/09 12:55:55 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_chk.h"

static int		ft_chk_map_num(char c)
{
	if (c == '1' || c == '0' || c == '2')
		return (1);
	return (0);
}

static int		ft_chk_map_user(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int				ft_chk_map_null(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int				*ft_map_value_chk(char c, int i, int j, t_map_user *user)
{
	if (ft_chk_map_user(c))
	{
		if (!ft_chk_map_user(user->dir))
		{
			user->dir = c;
			user->y = i;
			user->x = j;
		}
		else
		{
			perror("Multiple Direction Values.");
			exit(0);
		}
	}
	else if (!ft_chk_map_num(c) && !ft_chk_map_user(c) && !ft_chk_map_null(c))
	{
		perror("Invalid map value.");
		exit(0);
	}
	return (0);
}
