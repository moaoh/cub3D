/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 23:36:59 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/03 20:02:23 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list		*ft_lstnew(void *content)
{
	t_list		*num;

	num = (t_list *)malloc(sizeof(t_list));
	if (!num)
		return (NULL);
	num->content = content;
	num->next = NULL;
	return (num);
}
