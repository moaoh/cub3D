/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:36:58 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/12 07:49:33 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// map 유효성 검사.
// map에 해당하는 값들을 담기.

static int			ft_file_name_chk(char *s)
{
	char			**str;

	if (!s)
	{
		perror("Invalid filename");
		exit(0);
	}
	str = ft_split(s, '.');
	if (!str[1] || (ft_strncmp(str[1], "cub", 3)) || (ft_strlen(str[1]) != 3))
	{
		perror("Invalid filename");
		exit(0);
	}
	return (_RIGHT);
}

static void			ft_cub_bzero(t_cub_info *cub_chk)
{
	cub_chk->r = 0;
	cub_chk->no = 0;
	cub_chk->so = 0;
	cub_chk->we = 0;
	cub_chk->ea = 0;
	cub_chk->s = 0;
	cub_chk->f = 0;
	cub_chk->c = 0;
}

static void			ft_info_chk(char **argv, t_map *map, t_cub_info *cub_chk)
{
	int				fd;
	char			*line;

	ft_file_name_chk(argv[1]);
	ft_cub_bzero(cub_chk);
	// fd = open("/Users/junmkang/42seoul/1.projects/cub3D/test.cub", O_RDONLY);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_value_info(line, map, cub_chk);
		free(line);
	}
	ft_map_chk(map);
}

// map이 newline으로 나누어져 있는경우 어떻게 진행을 해야하는가.
// 그냥 옳은것으로 판단하는게 훨씬 편안.
int					main(int argc, char **argv)
{
	t_map			map;
	t_cub_info		cub_chk;

	ft_info_chk(argv, &map, &cub_chk);
	cub3d(map);
	// cub2d(map);

	return (0);
}
