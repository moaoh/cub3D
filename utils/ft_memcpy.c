/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:56:40 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/02 16:43:20 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned char	*des;
	unsigned char	*sou;
	size_t			i;

	if (!destination && !source)
		return (0);
	des = (unsigned char *)destination;
	sou = (unsigned char *)source;
	i = 0;
	while (i < num)
	{
		des[i] = sou[i];
		i++;
	}
	return (des);
}
