#include "so_long.h"

void	ft_set_player(t_assets *assets, void *screen, void *window)
{
	int	x;
	int	y;

   	x = assets->x * 64;
   	y = assets->y * 64;
	mlx_put_image_to_window(screen, window, assets->grass[0], x, y);
    mlx_put_image_to_window(screen, window, assets->player->left, x, y);
	assets->pos[assets->x][assets->y] = 4;
	assets->player->x = assets->x;
	assets->player->y = assets->y;
}

void    ft_set_box(t_assets *assets, void *screen, void *window)
{
    int x;
    int y;

    x = assets->x * 64;
    y = assets->y * 64;

    if ((y == 0 || assets->y == assets->heigth) && assets->x == assets->len -1)
        mlx_put_image_to_window(screen, window, assets->rock_right, x, y);
    else if ((y == 0 || assets->y == assets->heigth) && x == 0)
        mlx_put_image_to_window(screen, window, assets->rock_left, x, y);
    else if (y == 0 || assets->y == assets->heigth)
        mlx_put_image_to_window(screen, window, assets->rock_line, x, y);
    else if (x == 0 || assets->x == assets->len - 1)
        mlx_put_image_to_window(screen, window, assets->rock_column, x, y);
	else
		mlx_put_image_to_window(screen, window, assets->tree, x, y);
	assets->pos[assets->x][assets->y] = 2;

	return ;
}

void    ft_set_grass(t_assets *assets, void *screen, void *window)
{
    int x;
    int y;

    x = assets->x * 64;
    y = assets->y * 64;
	mlx_put_image_to_window(screen, window, assets->grass[assets->x % 2], x, y);
	if (assets->x % 2)
		assets->pos[assets->x][assets->y] = 1;
	else
		assets->pos[assets->x][assets->y] = 0;
}

void    ft_set_mush(t_assets *assets, void *screen, void *window)
{
    int x;
    int y;

    x = assets->x * 64;
    y = assets->y * 64;
    mlx_put_image_to_window(screen, window, assets->mush->img[0], x, y);
    assets->mush->x[assets->n_mush] = assets->x;
    assets->mush->y[assets->n_mush] = assets->y;
    assets->pos[assets->x][assets->y] = 3;
    assets->n_mush++;
    return ;
}