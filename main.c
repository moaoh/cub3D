#include "cub3d.h"

// map 유효성 검사.
// map에 해당하는 값들을 담기.

static int		ft_file_name_chk(char *s)
{
	char	**str;

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

int					main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_map	map;
	t_cub_info	cub_chk;

	ft_file_name_chk(argv[1]);
	fd = open(argv[1], O_RDONLY);
	ft_cub_bzero(&cub_chk);
	while (get_next_line(fd, &line) > 0)
	{
		ft_map_info(line, &map, &cub_chk);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	printf("x = %d, y = %d", map.resolution.R_X, map.resolution.R_Y);
	// printf("R = %d, G = %d, B = %d", map.f_color.R, map.f_color.G, map.f_color.B);
	// printf("NO = %s", map.texure.NO);

	return (0);
}
