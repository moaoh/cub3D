# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 13:37:51 by junmkang          #+#    #+#              #
#    Updated: 2021/02/05 15:10:35 by junmkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

# library
UTILS_DIR = ./utils/
UTILS_NAME = \
	ft_split.c \
	ft_atoi.c \
	ft_memcpy.c \
	ft_strncmp.c

SRCS_DIR = ./srcs/
SRCS_NAME = \
	main.c

SCREEN_DIR = ./save_screen/
SCREEN_NAME = \
	save_screen.c

GNL_DIR = ./get_next_line/
GNL_NAME = \
	get_next_line.c \
	get_next_line_utils.c

MAP_DIR = ./map_chk/
MAP_NAME = \
	ft_map_chk.c \
	ft_map_validity.c \
	ft_map_value_chk.c

V_INFO_DIR = ./value_info/
V_INFO_NAME = \
	ft_value_info.c \
	ft_value_screen.c \
	ft_value_texture.c \
	ft_value_sprite.c \
	ft_map.c

RAY_DIR = ./ray/
RAY_NAME = \
	cub3d.c  \
	ft_max_screen_chk.c \
	ft_press.c \
	ray_cub_info.c 

R_IMG_DIR = ./ray_img/
R_IMG_NAME = \
	ft_img.c \
	ft_img_texture_info.c \
	ft_img_map_chk.c \
	ft_wall_change.c \
	ft_sprite_change.c

R_LOOP_DIR = ./ray_loop/
R_LOOP_NAME = \
	main_loop.c \
	ft_loop_wall.c \
	ft_loop_sprite.c \
	ft_loop_sprite_sort.c

BASIC = $(addprefix $(UTILS_DIR), $(UTILS_NAME)) \
		$(addprefix $(SRCS_DIR), $(SRCS_NAME)) \
		$(addprefix $(SCREEN_DIR), $(SCREEN_NAME)) \
		$(addprefix $(GNL_DIR), $(GNL_NAME)) \
		$(addprefix $(MAP_DIR), $(MAP_NAME)) \
		$(addprefix $(V_INFO_DIR), $(V_INFO_NAME)) \
		$(addprefix $(RAY_DIR), $(RAY_NAME)) \
		$(addprefix $(R_IMG_DIR), $(R_IMG_NAME)) \
		$(addprefix $(R_LOOP_DIR), $(R_LOOP_NAME))

HEADERS = \
		$(UTILS_DIR)utils.h \
		$(SRCS_DIR)cub3d.h \
		$(SRCS_DIR)cub3d_struct.h \
		$(SCREEN_DIR)save_screen.h \
		$(GNL_DIR)get_next_line.h \
		$(MAP_DIR)map_chk.h \
		$(V_INFO_DIR)value_info.h \
		$(RAY_DIR)ray.h \
		$(RAY_DIR)ray_struct.h \
		$(RAY_DIR)press.h

OBJS	= $(BASIC:.c=.o)

CC = gcc
FLAG = -Wall -Wextra -Werror -I

RM		= rm -f
MLX		= libmlx.dylib
LIBS	= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAG) -o $(NAME) $(OBJS) $(LIBS)
	
norm :
	norminette $(BASIC) $(HEADERS)

%.o : %.c
	$(CC) $(FLAG) -c $*.c -o $@

clean :
	$(RM) $(UTILS_DIR) *.o
	$(RM) $(UTILS_DIR) *.o 
	$(RM) $(SRCS_DIR) *.o 
	$(RM) $(SRCS_DIR) *.o 
	$(RM) $(SCREEN_DIR) *.o 
	$(RM) $(GNL_DIR) *.o 
	$(RM) $(MAP_DIR) *.o 
	$(RM) $(V_INFO_DIR) *.o 
	$(RM) $(RAY_DIR) *.o 
	$(RM) $(RAY_DIR) *.o 
	$(RM) $(RAY_DIR) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME)
