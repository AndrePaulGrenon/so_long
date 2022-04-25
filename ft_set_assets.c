#include <so_long.h>

void	ft_set_road(t_assets *assets, void *screen, void *window)
{
	int x;
	int y;
	int k;

	x = assets->x * 64;
	y = assets->y * 64;
	k = (assets->len * assets->y) + assets->x +assets->y;
	if (!assets->n_road)
		mlx_put_image_to_window(screen, window, assets->l_road, x, y);
	else if (assets->map[k + 1] != 'R')
		mlx_put_image_to_window(screen, window, assets->r_road, x, y);
	else
		mlx_put_image_to_window(screen, window, assets->road, x, y);
	if (!assets->n_road)
		assets->pos[x / 64][y / 64] = L_ROAD;
	else if (assets->map[k + 1] != 'R')
		assets->pos[x / 64][y / 64] = R_ROAD;
	else
		assets->pos[x / 64][y / 64] = ROAD;
	assets->n_road++;
}
