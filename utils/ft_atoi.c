/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:38:02 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/02 14:30:46 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		ft_atoi(const char *str)
{
	unsigned int		sum;
	unsigned int		num;
	int					i;

	num = 1;
	i = 0;
	while (str[i] && (str[i] == 32 || (9 <= str[i] && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			num *= -1;
		i++;
	}
	sum = 0;
	while ('0' <= str[i] && str[i] <= '9' && str[i])
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	return (num * sum);
}
