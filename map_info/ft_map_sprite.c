/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:26:31 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/03 15:05:31 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"

// strcpy()

static int	ft_sprite_chk(char *str)
{
	if (!(str[0] == '.' && str[1] == '/'))
	{
		perror("Invalid sprite format");
		exit(0);
	}
	return (_RIGHT);
}

int		ft_map_sprite(char *line, t_map *map, int cub_chk)
{
	char	**str;

	if (cub_chk != 1)
	{
		perror("Invalid sprite value.");
		exit(0);
	}
	str = ft_split(line, ' ');
	if (!ft_strncmp(str[0], "S", 1) && ft_sprite_chk(str[1]))
		map->sprite.S = ft_strdup(str[1], ft_strlen(str[1]));
	else
	{
		perror("Invalid sprite format");
		exit(0);
	}

	return (0);
}
