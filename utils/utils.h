/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:26:17 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/03 20:04:18 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef	UTILS_H
#	define	UTILS_H

#	include "../cub3d.h"
#	include <unistd.h>

char			**ft_split(char const *s, char c);
void			*ft_memcpy(void *destination, const void *source, size_t num);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_atoi(const char *str);

t_list          *ft_lstnew(void *content);
void            ft_lstadd_front(t_list **lst, t_list *new);
int             ft_lstsize(t_list *lst);
t_list          *ft_lstlast(t_list *lst);
void            ft_lstadd_back(t_list **lst, t_list *new);
void            ft_lstdelone(t_list *lst, void (*del)(void*));
void            ft_lstclear(t_list **lst, void (*del)(void*));
void            ft_lstiter(t_list *lst, void (*f)(void *));
t_list          *ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));

#	endif
