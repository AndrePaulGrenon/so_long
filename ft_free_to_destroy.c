#include "so_long.h"

void	ft_free_to_destroy(void *screen, t_assets *assets)
{
		mlx_destroy_image(screen, assets->grass[0]);
		mlx_destroy_image(screen, assets->grass[1]);
		mlx_destroy_image(screen, assets->grass[2]);
		mlx_destroy_image(screen, assets->rock_left);
		mlx_destroy_image(screen, assets->rock_right);
		mlx_destroy_image(screen, assets->rock_line);
		mlx_destroy_image(screen, assets->rock_column);
		mlx_destroy_image(screen, assets->tree);
		mlx_destroy_image(screen, assets->tent);
		mlx_destroy_image(screen, assets->supplies);
		mlx_destroy_image(screen, assets->road_left);
		mlx_destroy_image(screen, assets->road_right);
		mlx_destroy_image(screen, assets->road_main);
		if (assets)
			free(assets);
	return ;
}
