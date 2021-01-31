all:
		gcc -I mlx/minilibx_mms_20200219 libmlx.dylib \
		srcs/*.c srcs/get_next_line/*.c utils/*.c srcs/map_chk/*.c \
		srcs/value_info/*.c srcs/ray/*.c srcs/save_screen/*.c
