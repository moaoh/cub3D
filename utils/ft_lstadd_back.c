/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 00:12:47 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/03 21:36:21 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	temp = 0;
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
	//printf("%s\n", temp->next->content);
	// printf("%s\n", temp->content);
}
