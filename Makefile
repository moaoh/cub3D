all:
		gcc -I mlx/minilibx_mms_20200219 mlx/libmlx.dylib \
		*.c get_next_line/*.c utils/*.c map_chk/*.c value_info/*.c raycasting/*.c cub2d/*.c
