/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:26:17 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/09 12:56:51 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef UTILS_H
#	define UTILS_H

#	include "../cub3d.h"
#	include <unistd.h>

char			**ft_split(char const *s, char c);
void			*ft_memcpy(void *destination, const void *source, size_t num);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_atoi(const char *str);

#	endif
