#include "../srcs/cub3d.h"

void  my_mlx_pixel_put(t_img *img, int y, int x, int color)
{
	img->data[y * (img->size_l / 4) + x * (img->bpp / 32)] = color;
}

int	main(void)
{
	t_ray_info	info;
	t_img		img;
	t_img		img2;
	int			img_width;
    int			img_height;
	// int			img2_width;
    // int			img2_height;

	info.mlx = mlx_init();

	info.win = mlx_new_window(info.mlx, 1000, 800, "main");

	img2.img = mlx_new_image(info.mlx, 1000, 800);

	img.img = mlx_xpm_file_to_image(info.mlx, "../texture/wall_e.xpm", &img_width, &img_height);
	if (!img.img)
		return (0);
	// img.img = mlx_png_file_to_image(info.mlx, "../texture/minecraft.png", &img_width, &img_height);
	// printf("test = %d %d\n", img_width, img_height);
	
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_l, &img.endian);
	img2.data = (int *)mlx_get_data_addr(img2.img, &img2.bpp, &img2.size_l, &img2.endian);
	// printf("test\n");

	// printf("size_l = %d\n %d\n %d\n", img.size_l, img_width, img_height);
	for(int i = 0; i < img_height; i++)
	{
		for(int j = 0; j < img_width; j++)
		{
			// img.data[i * img.size_l + j * (img.bpp / 8)] = 0xFFFFFF;
			my_mlx_pixel_put(&img2, i, j, img.data[i * (img.size_l / 4) + j * (img.bpp / 32)]);
			// img2.data[i * img_width + j] = 0xFFFFFF;
			// img2.data[i * img_width + j]= img.data[i * img_width + j];
		}
	}

	mlx_put_image_to_window(info.mlx, info.win, img2.img, 0, 0);
	mlx_loop(info.mlx);
	
	return (0);
}