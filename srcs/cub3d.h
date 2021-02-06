/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:39:36 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/06 13:17:56 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CUB3D_H
#	define CUB3D_H

#	define _WRONG 0
#	define _RIGHT 1

/*
** header file --------------------------------------------
*/

#	include "../mlx/mlx.h"
#	include "cub3d_struct.h"
#	include "value_info/value_info.h"
#	include "../utils/utils.h"
#	include "get_next_line/get_next_line.h"
#	include "map_chk/map_chk.h"
#	include "ray/ray_struct.h"
#	include "save_screen/save_screen.h"
#	include "ray/ray.h"
#	include "ray/press.h"

#	include <stdio.h>
#	include <unistd.h>
#	include <stdlib.h>
#	include <string.h>
#	include <math.h>
#	include <fcntl.h>
#	include <limits.h>

void	ft_error(char *s);

#	endif
