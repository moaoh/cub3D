/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:26:31 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 09:58:22 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "value_info.h"

static int	ft_sprite_chk(char *str)
{
	if (!(str[0] == '.' && str[1] == '/'))
		ft_error("Invalid sprite format");
	return (_RIGHT);
}

int			ft_value_sprite(char *line, t_map *map, int cub_chk)
{
	char	**str;

	if (cub_chk != 1)
		ft_error("duplicate sprite value.");
	str = ft_split(line, ' ');
	if (!ft_strncmp(str[0], "S", 1) && ft_sprite_chk(str[1]))
	{
		map->sprite.s = ft_strdup(str[1], ft_strlen(str[1]));
	}
	else
		ft_error("Invalid sprite format");
	ft_value_free(str);
	return (0);
}
