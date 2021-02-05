# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 13:37:51 by junmkang          #+#    #+#              #
#    Updated: 2021/02/05 14:05:59 by junmkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
FLAG = -Wall -Wextra -Werror -I


SRCS =	srcs/main.c \
		srcs/save_screen/save_screen.c \
		srcs/get_next_line/get_next_line.c srcs/get_next_line/get_next_line_utils.c \
		srcs/map_chk/ft_map_chk.c srcs/map_chk/ft_map_validity.c srcs/map_chk/ft_map_value_chk.c \
		srcs/value_info/ft_value_info.c srcs/value_info/ft_value_screen.c \
		srcs/value_info/ft_value_texture.c srcs/value_info/ft_value_sprite.c srcs/value_info/ft_map.c \
		srcs/ray/cub3d.c srcs/ray/ft_max_screen_chk.c srcs/ray/ft_press.c srcs/ray/ray_cub_info.c \
		srcs/ray/ray_img/ft_img.c srcs/ray/ray_img/ft_img_texture_info.c srcs/ray/ray_img/ft_img_map_chk.c \
		srcs/ray/ray_img/ft_wall_change.c srcs/ray/ray_img/ft_sprite_change.c \
		srcs/ray/ray_loop/main_loop.c srcs/ray/ray_loop/ft_loop_wall.c \
		srcs/ray/ray_loop/ft_loop_sprite.c srcs/ray/ray_loop/ft_loop_sprite_sort.c

OBJS	= $(SRCS:.c=.o)

RM		= rm -f
MLX		= libmlx.dylib

all :	$(NAME)

$(NAME) : $(mlx) $(OBJS)
		$(cc) $(FLAG) -o $(NAME) $(OBJS)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all
