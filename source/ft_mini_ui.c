/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:24:31 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/02 14:39:17 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_get_data_addr(t_data *img)
{
	int		*bit;
	int		*lln;

	lln = &img->line_length;
	bit = &img->bits_per_pixel;
	img->addr = mlx_get_data_addr(img->img, bit, lln, &img->endian);
	return ;
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
	mlx_string_put(screen, window, 40, 18, 0xFFFFFF, "MOVES: ");
	mlx_string_put(screen, window, 108, 18, 0x0F00F0FF, toa_moves);
	mlx_string_put(screen, window, 175, 18, 0x0FF00430, "CHAMPI: ");
	mlx_string_put(screen, window, 253, 18, 0x0330F000, toa_mush);
	free(toa_moves);
	free(toa_mush);
	return ;
}

void	ft_show_it(t_assets *assets, int x, int y, int pos)
{
	t_data	img;
	int		xi;
	int		yi;
	t_vars	*v;

	v = assets->vars;
	xi = 0;
	yi = 0;
	img.img = mlx_new_image(assets->vars->screen, x, y);
	ft_get_data_addr(&img);
	while (yi < y)
	{
		while (xi < x)
		{
			my_mlx_pixel_put(&img, xi, yi, 0x77880000);
			xi++;
		}
		xi = 0;
		yi++;
	}
	mlx_put_image_to_window(v->screen, v->window, img.img, pos, pos);
}

void	ft_mini_ui(t_assets *assets)
{
	t_data	img;
	int		xi;
	int		yi;
	t_vars	*v;

	v = assets->vars;
	xi = 0;
	yi = 0;
	img.img = mlx_new_image(assets->vars->screen, 132, 32);
	ft_get_data_addr(&img);
	while (yi < 32)
	{
		while (xi < 132)
		{
			my_mlx_pixel_put(&img, xi, yi, 0x33223355);
			xi++;
		}
		xi = 0;
		yi++;
	}
	mlx_put_image_to_window(v->screen, v->window, img.img, 162, 16);
	ft_show_it(assets, 132, 32, 16);
	ft_move_print(assets);
	return ;
}
