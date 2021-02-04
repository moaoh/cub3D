/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_info.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:29:23 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/05 07:25:20 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef VALUE_INFO_H
#	define VALUE_INFO_H

#	include "../cub3d.h"

int			ft_value_info(char *line, t_map *map, t_cub_info *cub_chk);
int			ft_value_screen(char *line, t_map *map, int cub_chk);
int			ft_value_texture(char *line, t_map *map, int cub_chk);
int			ft_value_sprite(char *line, t_map *map, int cub_chk);
int			ft_value_color(char *line, t_map *map, int cub_chk);
int			ft_map(char *line, t_map *map);

void		ft_value_free(char **str);

#	endif
