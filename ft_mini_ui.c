#include <so_long.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_move_print(t_assets *assets)
{
	void	*window;
	void	*screen;
	char	*toa_moves;
	char	*toa_mush;

	screen = assets->vars->screen;
	window = assets->vars->window;
	toa_moves = ft_itoa(assets->player->moves);
	toa_mush = ft_itoa(assets->collected);
 	mlx_string_put(screen, window, 40, 18, 0x0F00F0FF, "MOVES: ");
 	mlx_string_put(screen, window, 108, 18, 0x0F00F0FF, toa_moves);
 	//mlx_string_put(screen, window, 128, 18, 0x0F00F0FF, toa_mush);
	free(toa_moves);
	free(toa_mush);
	return ;
}

void	ft_mini_ui(t_assets *assets)
{
	t_data img;
	int		xi;
	int		yi;

	xi = 0;
	yi = 0;
	img.img = mlx_new_image(assets->vars->screen, 108, 32);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);	
	while (yi < 32)
	{
		while (xi < 108)
		{
			my_mlx_pixel_put(&img, xi, yi, 0x33223355);
			xi++;
		}
		xi = 0;
		yi++;
	}
	mlx_put_image_to_window(assets->vars->screen, assets->vars->window, img.img, 32, 16);
	ft_move_print(assets);
	return; 
}
