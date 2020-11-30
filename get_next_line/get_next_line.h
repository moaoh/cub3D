/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:46:26 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/30 19:06:43 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#	include <stdlib.h>
#	include <limits.h>
#	include <unistd.h>

#	define _ERROR	-1
#	define _EOF		0
#	define _GOOD	1

#	ifndef BUFFER_SIZE
#	define BUFFER_SIZE 100
#	endif

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s, int len);
char		*ft_strjoin(char const *s1, char const *s2);

#	endif
