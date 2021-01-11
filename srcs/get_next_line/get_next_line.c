/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:46:05 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/18 18:02:53 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			chk_2(char *memory, int c)
{
	int				i;

	i = 0;
	while (memory[i])
	{
		if (memory[i] == c)
			return (i);
		i++;
	}
	if (memory[i] == c)
		return (i);
	return (-1);
}

static char			*chk(char *memory, int c)
{
	int				i;

	i = 0;
	while (memory[i])
	{
		if (memory[i] == c)
			return (&memory[i]);
		i++;
	}
	if (memory[i] == c)
		return (&memory[i]);
	return (NULL);
}

static int			ft_print(char **memory, char **line)
{
	char	*temp;
	int		chk_len;

	chk_len = chk_2(*memory, '\n');
	if (chk_len >= 0)
	{
		if (!(*line = ft_strdup(*memory, chk_len)))
			return (_ERROR);
		temp = ft_strdup(*memory + chk_len + 1, ft_strlen(*memory) - chk_len);
		if (!temp)
			return (_ERROR);
		if (*memory)
			free(*memory);
		*memory = temp;
		return (_GOOD);
	}
	else
	{
		*line = *memory;
		*memory = NULL;
		return (_EOF);
	}
}

int					get_next_line(int fd, char **line)
{
	static char		*memory[OPEN_MAX + 1];
	char			*buf;
	char			*temp;
	int				buff_len;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || OPEN_MAX < fd)
		return (_ERROR);
	if (!(buf = (char *)malloc(sizeof(char ) * (BUFFER_SIZE + 1))))
		return (_ERROR);
	if (!memory[fd])
		memory[fd] = ft_strdup("", 1);
	while ((buff_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[buff_len] = '\0';
		temp = ft_strjoin(!(memory[fd]) ? "" : memory[fd], buf);
		if (memory[fd])
			free(memory[fd]);
		memory[fd] = temp;
		if ((chk(memory[fd], '\n')) || buff_len <= 0)
			break ;
	}
	free(buf);
	if (buff_len < 0)
		return (_ERROR);
	return (ft_print(&memory[fd], line));
}
