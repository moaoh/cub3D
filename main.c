#include "cub3d.h"

// map 유효성 검사.
// map에 해당하는 값들을 담기.
int     main(int argc, char **argv)
{
    int     fd;
    char    *line;
    t_map   map;

    fd = open("test_2.cub", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
		ft_map_info(line, &map);
        free(line);
    }
    printf("%s\n", line);
    free(line);
    // printf("x = %d, y = %d", map.resolution.R_X, map.resolution.R_Y);
    printf("R = %d, G = %d, B = %d", map.f_color.R, map.f_color.G, map.f_color.B);

    return (0);
}
