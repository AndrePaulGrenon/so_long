#include "so_long.h"

void	ft_print_exemple(t_assets *assets, void *screen, void *window)
{
	int x;
	int y;

	x = assets->x;
	y = assets->y;
	
	if (y / 64 == 7 && x / 64 > 3 && x / 64 < 10)
		mlx_put_image_to_window(screen, window, assets->road_main, x, y);
	else if (y / 64 == 7 && x / 64 == 3)
		mlx_put_image_to_window(screen, window, assets->road_left, x, y);
	else if (y / 64 == 7 && x / 64 == 10)
		mlx_put_image_to_window(screen, window, assets->road_right, x, y);
	else if ((y == 0 || y > 1000) && x > 1850)
		mlx_put_image_to_window(screen, window, assets->rock_right, x, y);
	else if ((y == 0 || y > 1000) && x == 0)
		mlx_put_image_to_window(screen, window, assets->rock_left, x, y);
	else if (y == 0 || y > 1000)
		mlx_put_image_to_window(screen, window, assets->rock_line, x, y);
	else if (x == 0 || x > 1850)
		mlx_put_image_to_window(screen, window, assets->rock_column, x, y);
	else if (x % 6 == 0)
		mlx_put_image_to_window(screen, window, assets->grass[1], x, y);
	else
		mlx_put_image_to_window(screen, window, assets->grass[0], x, y);
	return ;
}


int	ft_set_data(t_assets *assets, int *i ,int *j)
{
	if (assets->map[*i] == '\n' && assets->len == 0)
		assets->len = *i;
	else if (assets->len == 0)
		assets->x = *i;
	else if (*j < assets->len)
	{
		assets->x = *j;
		*j = *j + 1;
	}
	else if (*j == assets->len && assets->map[*i] != '\n')
		return (1);
	else if (*j == assets->len)
	{
		*j = 0;
		assets->y++;
	}
	return (0);
}

void	ft_tile_select(t_assets *assets, void *screen, void *window, int i)
{
	int x;
	int y;

	x = assets->x * 64;
	y = assets->y * 64;
	if (assets->map[i] == 'X')
		mlx_put_image_to_window(screen, window, assets->rock_line, x, y);
	else if (assets->map[i] == 'B')
		mlx_put_image_to_window(screen, window, assets->road_main, x, y);
	else if (assets->map[i] == 'G')
		mlx_put_image_to_window(screen, window, assets->grass[1], x, y);
	return ;
}

void	ft_put_grid(void *screen, void *window, t_assets *assets)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (assets->map[i])
	{
		if (ft_set_data(assets, &i, &j))
			return ;
		
		ft_tile_select(assets, screen, window, i);
		i++;
	}
	return ;
}
