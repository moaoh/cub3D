/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_info.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:29:23 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/27 08:30:35 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef VALUE_INFO_H
#	define VALUE_INFO_H

#	include "../cub3d.h"

int			ft_value_info(char *line, t_map *map, t_cub_info *cub_chk);

char		**ft_get_doublemap(char *buff);

int			ft_value_screen(char *line, t_map *map, int cub_chk);
int			ft_value_texure(char *line, t_map *map, int cub_chk);
int			ft_value_sprite(char *line, t_map *map, int cub_chk);
int			ft_value_color(char *line, t_map *map, int cub_chk);

int			ft_map(char *line, t_map *map);

#	endif
