/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:38:55 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/03 21:18:46 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_info.h"

// 탭인경우 4칸
int				ft_map(char *line, t_map *map, t_list *lst)
{
	char	**get_map_info;
	int		count;
	t_list	*new;

	new = ft_lstnew(line);
	ft_lstadd_back(&lst, new);

/*
	while (lst)
	{
		printf("%d %s\n",ft_lstsize(lst); lst->content);
		lst = lst->next;
	}
*/
	// *get_map_info = (char *)malloc(sizeof(char) * ft_strlen(line));

	return (0);
}
