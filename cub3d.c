#include "cub3d.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open("test.cub", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);

	return (0);
}
