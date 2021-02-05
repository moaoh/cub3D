/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 01:04:39 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 09:27:12 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char				**ft_free(char **str, int x)
{
	int				i;

	i = 0;
	while (i < x)
	{
		free(str[x]);
		i++;
	}
	free(str);
	return (NULL);
}

static int				ft_count(char const *s, char c)
{
	int				i;
	int				count;
	int				x;

	count = 0;
	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int				chk(char const *s, char c, int i)
{
	int				count;

	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (count);
		count++;
		i++;
	}
	return (count);
}

static char				**share(char **str, char const *s, char c)
{
	int				i;
	int				x;
	int				tru;
	int				count;

	i = 0;
	x = 0;
	count = ft_count(s, c);
	while (count > x && s[i])
	{
		tru = chk(s, c, i);
		if (tru)
		{
			str[x] = (char *)malloc(sizeof(char *) * (tru + 1));
			if (!str[x])
				return (ft_free(str, x));
			ft_memcpy(str[x], &s[i], tru);
			str[x][tru] = '\0';
			x++;
		}
		i += tru + 1;
	}
	return (str);
}

char					**ft_split(char const *s, char c)
{
	char			**str;
	int				count;

	if (!s)
		return (0);
	count = ft_count(s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	str = share(str, s, c);
	if (!str)
	{
		free(str);
		return (0);
	}
	str[count] = 0;
	return (str);
}
