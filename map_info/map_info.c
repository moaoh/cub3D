#include "map_info.h"

int		ft_map_chk(char	*line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
	else if (ft_strncmp(line, "NO ", 3) == 0)
	else if (ft_strncmp(line, "SO ", 3) == 0)
	else if (ft_strncmp(line, "WE ", 3) == 0)
	else if (ft_strncmp(line, "EA ", 3) == 0)
	else if (ft_strncmp(line, "S ", 2) == 0)
	else if (ft_strncmp(line, "F ", 2) == 0)
	else if (ft_strncmp(line, "C ", 2) == 0)
	else
		return (_ERROR);
}

int		ft_map_info(char *line)
{
	if (!(ft_map_chk(line)))
		return (_ERROR);
	
		
}
