/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:30:48 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/27 23:38:20 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t				i;
	unsigned char		*st1;
	unsigned char		*st2;

	i = 0;
	st1 = (unsigned char *)str1;
	st2 = (unsigned char *)str2;
	while (st1[i] != '\0' && st2[i] != '\0' && i < n)
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	if (st1[i] != st2[i] && i != n)
		return (st1[i] - st2[i]);
	return (0);
}
