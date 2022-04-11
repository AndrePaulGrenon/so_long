#include "so_long.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*screen;
	void	*window;
	t_image	img;
	int 	i;
	int		j;

	i = 0;
	j = 0;

	screen =  mlx_init();
	window = mlx_new_window(screen, 1920, 1080, "Les Pixels se touchent");	
	img.img = mlx_new_image(screen, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	while (i < 80)
	{
		while(j < 125)
			my_mlx_pixel_put(&img, i, j++, 0x00FF0000);
		j = 0;
		i++;
	}
	mlx_put_image_to_window(screen, window, img.img, 500, 500);
	mlx_loop(screen);

	return (0);
}
