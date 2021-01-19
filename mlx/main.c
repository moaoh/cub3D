#include "../srcs/cub3d.h"

int	main(void)
{
	t_ray_info	info;
	t_img		img;
	int			img_width = 5;
    int			img_height = 5;

	info.mlx = mlx_init();

	info.win = mlx_new_window(info.mlx, 1000, 800, "main");
	img.img = mlx_new_image(info.mlx, 1000, 800);
	img.img = mlx_png_file_to_image(info.mlx, "../texture/minecraft.xpm", &img_width, &img_height);
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_l, &img.endian);

	printf("size_l = %d\n %d\n %d\n", img.size_l, img_width, img_height);
	for(int i = 0; i < img_height / 2; i++)
	{
		for(int j = 0; j < img_width; j++)
			img.data[i * img_width + j] = 0xFFFFFF;
	}

	mlx_put_image_to_window(info.mlx, info.win, img.img, 0, 0);
	mlx_loop(info.mlx);

	return (0);
}