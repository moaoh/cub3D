/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:26:17 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/02 16:44:22 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef	UTILS_H
#	define	UTILS_H

#	include "../cub3d.h"
#	include <unistd.h>

char		**ft_split(char const *s, char c);
void		*ft_memcpy(void *destination, const void *source, size_t num);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
int			ft_atoi(const char *str);

#	endif
