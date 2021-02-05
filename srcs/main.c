/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:36:58 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 09:18:17 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_error(char *s)
{
	perror(s);
	exit(0);
}

static void			ft_file_name_chk(char *s)
{
	char			**str;

	if (!s)
		ft_error("Invalid filename");
	str = ft_split(s, '.');
	if (!str[1] || (ft_strncmp(str[1], "cub", 3)) || (ft_strlen(str[1]) != 3))
		ft_error("Invalid filename");
	ft_value_free(str);
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
	
	if (argv[2])
		save_screen_chk(argv[2], map);
	ft_file_name_chk(argv[1]);
	ft_cub_bzero(cub_chk);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("not file.");
	while (get_next_line(fd, &line) > 0)
	{
		ft_value_info(line, map, cub_chk);
		free(line);
	}
	free(line);
	ft_map_chk(map);
}

int					main(int argc, char **argv)
{
	t_map			map;
	t_cub_info		cub_chk;

	map.map.buff = 0;
	map.save_bool = 0;
	if (argc != 2 && argc != 3)
		ft_error("Invalid input value.");
	ft_info_chk(argv, &map, &cub_chk);
	cub3d(&map);
	return (0);
}
