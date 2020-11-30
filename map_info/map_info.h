/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:29:23 by junmkang          #+#    #+#             */
/*   Updated: 2020/11/30 20:22:06 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef	MAP_INFO_H
#	define	MAP_INFO_H

#	include "../cub3d.h"
#	include <unistd.h>

#	define	_ERROR	-1

typedef struct		s_cub_info
{
	int				r;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				s;
	int				f;
	int				c;
}					t_cub_info;

#	endif
