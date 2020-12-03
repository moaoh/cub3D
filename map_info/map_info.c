/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:37:00 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/03 15:13:52 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"

// 길이를 잡는 조건도 추가를 해서 반례를 잡아줘야함
static int		ft_map_chk(char	*line, t_map *map, t_cub_info *cub_chk)
{
	// Resolution (해상도)
	if (!ft_strncmp(line, "R ", 2))
		ft_map_resolution(line, map, (int)++cub_chk->r);
	// texure (파일같은 경우에는 char 형식으로 담아도 사용가능)
	else if (!ft_strncmp(line, "NO ", 3))
		ft_map_texure(line, map, (int)++cub_chk->no);
	else if (!ft_strncmp(line, "SO ", 3))
		ft_map_texure(line, map, (int)++cub_chk->so);
	else if (!ft_strncmp(line, "WE ", 3))
		ft_map_texure(line, map, (int)++cub_chk->we);
	else if (!ft_strncmp(line, "EA ", 3))
		ft_map_texure(line, map, (int)++cub_chk->ea);
	// sprite
	else if (!ft_strncmp(line, "S ", 2))
		ft_map_sprite(line, map, (int)++cub_chk->s);
	// color
	else if (!ft_strncmp(line, "F ", 2))
		ft_map_color(line, map, (int)++cub_chk->f);
	else if (!ft_strncmp(line, "C ", 2))
		ft_map_color(line, map, (int)++cub_chk->c);

	// map 은 마지막에 와야함
	// map
	// else
		// ft_map(line, map);
	return (0);
}

int				ft_map_info(char *line, t_map *map, t_cub_info *cub_chk)
{
	if (!(ft_map_chk(line, map, cub_chk)))
		return (_WRONG);
	return (0);
}
