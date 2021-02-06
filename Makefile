# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 13:37:51 by junmkang          #+#    #+#              #
#    Updated: 2021/02/06 12:26:01 by junmkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

# SRCS			=	srcs/main.c \
# 					srcs/save_screen/save_screen.c \
# 					srcs/get_next_line/get_next_line.c	srcs/get_next_line/get_next_line_utils.c	\
# 					srcs/map_chk/ft_map_chk.c	srcs/map_chk/ft_map_validity.c	srcs/map_chk/get_next_line_utils.c	\
# 					srcs/map_chk/ft_map_chk.c	srcs/map_chk/ft_map_validity.c	srcs/map_chk/ft_map_value_chk.c	\
# 					srcs/value_info/ft_value_info.c	srcs/value_info/ft_value_screen.c	srcs/value_info/ft_value_texture.c	srcs/value_info/ft_value_sprite.c	srcs/value_info/ft_map.c	\
# 					srcs/ray/cub3d.c	srcs/ray/ft_max_screen_chk.c	srcs/ray/ft_press.c	srcs/ray/ray_cub_info.c	\
# 					srcs/ray/ray_img/ft_img.c	srcs/ray/ray_img/ft_sprite_change.c	srcs/ray/ray_img/ft_wall_change.c	srcs/ray/ray_img/ft_img_map_chk.c	srcs/ray/ray_img/ft_img_texture_info.c	\
# 					srcs/ray/ray_loop/ft_loop_sprite.c	srcs/ray/ray_loop/ft_loop_sprite_sort.c	srcs/ray/ray_loop/ft_loop_wall.c	srcs/ray/ray_loop/main_loop.c	\
# 					utils/ft_memcpy.c	utils/ft_split.c	utils/ft_atoi.c	utils/ft_strncmp.c

UTILS_DIR = ./utils/
UTILS_NAME = \
	ft_memcpy.c \
	ft_split.c \
	ft_atoi.c \
	ft_strncmp.c

SRCS_DIR = ./srcs/
SRCS_NAME = \
	main.c

SCREEN_DIR = ./srcs/save_screen/
SCREEN_NAME = \
	save_screen.c

GNL_DIR = ./srcs/get_next_line/
GNL_NAME = \
	get_next_line.c \
	get_next_line_utils.c

MAP_DIR = ./srcs/map_chk/
MAP_NAME = \
	ft_map_chk.c \
	ft_map_validity.c \
	ft_map_value_chk.c

V_INFO_DIR = ./srcs/value_info/
V_INFO_NAME = \
	ft_value_info.c \
	ft_value_screen.c \
	ft_value_texture.c \
	ft_value_sprite.c \
	ft_map.c

RAY_DIR = ./srcs/ray/
RAY_NAME = \
	cub3d.c  \
	ft_max_screen_chk.c \
	ft_press.c \
	ray_cub_info.c 

R_IMG_DIR = ./srcs/ray/ray_img/
R_IMG_NAME = \
	ft_img.c \
	ft_sprite_change.c \
	ft_wall_change.c \
	ft_img_map_chk.c \
	ft_img_texture_info.c

R_LOOP_DIR = ./srcs/ray/ray_loop/
R_LOOP_NAME = \
	ft_loop_sprite.c \
	ft_loop_sprite_sort.c \
	ft_loop_wall.c \
	main_loop.c 

BASIC = \
		$(addprefix $(R_IMG_DIR), $(R_IMG_NAME)) \
		$(addprefix $(R_LOOP_DIR), $(R_LOOP_NAME)) \
		$(addprefix $(RAY_DIR), $(RAY_NAME)) \
		$(addprefix $(V_INFO_DIR), $(V_INFO_NAME)) \
		$(addprefix $(MAP_DIR), $(MAP_NAME)) \
		$(addprefix $(GNL_DIR), $(GNL_NAME)) \
		$(addprefix $(SCREEN_DIR), $(SCREEN_NAME)) \
		$(addprefix $(UTILS_DIR), $(UTILS_NAME)) \
		$(addprefix $(SRCS_DIR), $(SRCS_NAME)) 

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

# OBJS	= $(SRCS:.c=.o)
OBJS	= $(BASIC:.c=.o)

CC = gcc
FLAG = -Wall -Wextra -Werror -I

RM		= rm -f
MLX		= libmlx.dylib
LIBS	= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
# LXFLAGS = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(MLX) $(OBJS)
	$(CC) $(FLAG) -o $(NAME) $(OBJS) $(LIBS)
	
# norm :
# 	norminette $(BASIC) $(HEADERS)

# %.o : %.c
# 	$(CC) $(FLAG) -c $*.c -o $@

# clean :
# 	$(RM) $(UTILS_DIR)*.o
# 	$(RM) $(UTILS_DIR)*.o 
# 	$(RM) $(SRCS_DIR)*.o 
# 	$(RM) $(SRCS_DIR)*.o 
# 	$(RM) $(SCREEN_DIR)*.o 
# 	$(RM) $(GNL_DIR)*.o 
# 	$(RM) $(MAP_DIR)*.o 
# 	$(RM) $(V_INFO_DIR)*.o 
# 	$(RM) $(RAY_DIR)*.o 
# 	$(RM) $(RAY_DIR)*.o 
# 	$(RM) $(RAY_DIR)*.o

# fclean : clean
# 	$(RM) $(NAME)

# re : fclean $(NAME)
