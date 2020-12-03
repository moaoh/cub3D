/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:23:44 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/03 20:02:09 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void			ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tomp;

	if (!lst)
		return ;
	while (*lst)
	{
		tomp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tomp;
	}
	*lst = NULL;
}
