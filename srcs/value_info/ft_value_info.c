/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:37:00 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 09:21:46 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "value_info.h"

void		ft_value_free(char **str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	ft_map_condition_chk(t_cub_info *cub_chk)
{
	if (cub_chk->r == 1 && cub_chk->r == 1 && cub_chk->no == 1 && \
		cub_chk->so == 1 && cub_chk->we == 1 && cub_chk->ea == 1 && \
		cub_chk->s == 1 && cub_chk->f == 1 && cub_chk->c == 1)
		return (_RIGHT);
	return (_WRONG);
}

static int	ft_value_chk(char *line, t_map *map, t_cub_info *cub_chk)
{
	if (!ft_strncmp(line, "R ", 2))
		ft_value_screen(line, map, (int)++cub_chk->r);
	else if (!ft_strncmp(line, "NO ", 3))
		ft_value_texture(line, map, (int)++cub_chk->no);
	else if (!ft_strncmp(line, "SO ", 3))
		ft_value_texture(line, map, (int)++cub_chk->so);
	else if (!ft_strncmp(line, "WE ", 3))
		ft_value_texture(line, map, (int)++cub_chk->we);
	else if (!ft_strncmp(line, "EA ", 3))
		ft_value_texture(line, map, (int)++cub_chk->ea);
	else if (!ft_strncmp(line, "S ", 2))
		ft_value_sprite(line, map, (int)++cub_chk->s);
	else if (!ft_strncmp(line, "F ", 2))
		ft_value_color(line, map, (int)++cub_chk->f);
	else if (!ft_strncmp(line, "C ", 2))
		ft_value_color(line, map, (int)++cub_chk->c);
	else if (line[0] == '\0')
		return (_RIGHT);
	else if (ft_map_condition_chk(cub_chk))
		ft_map(line, map);
	else
		return (_WRONG);
	return (_RIGHT);
}

int			ft_value_info(char *line, t_map *map, t_cub_info *cub_chk)
{
	if (!(ft_value_chk(line, map, cub_chk)))
		ft_error("Invalid format.");
	return (_RIGHT);
}
