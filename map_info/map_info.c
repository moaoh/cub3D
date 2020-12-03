/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:37:00 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/03 19:54:49 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"

static int	ft_map_condition_chk(t_cub_info *cub_chk)
{
	if (cub_chk->r == 1 && cub_chk->r == 1 && cub_chk->no == 1 && \
		cub_chk->so == 1 && cub_chk->we == 1 && cub_chk->ea == 1 && \
		cub_chk->s == 1 && cub_chk->f == 1 && cub_chk->c == 1)
		return (_RIGHT);
	return (_WRONG);
}

// 길이를 잡는 조건도 추가를 해서 반례를 잡아줘야함
static int	ft_map_chk(char	*line, t_map *map, t_cub_info *cub_chk, t_list *lst)
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
	else if (ft_map_condition_chk(cub_chk))
		ft_map(line, map, lst);
	else if (line[0] == '\0')
		return (_RIGHT);
	else
		return (_WRONG);
	return (_RIGHT);
}

int			ft_map_info(char *line, t_map *map, t_cub_info *cub_chk, t_list *lst)
{
	if (!(ft_map_chk(line, map, cub_chk, lst)))
	{
		perror("Invalid format");
		exit(0);
	}
	return (_RIGHT);
}
