#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_assets	*assets;
	int			fd;

	vars.screen =  mlx_init();
	assets = ft_init_xpm(vars.screen);
	assets->vars = &vars;
	fd = ft_open_map(argv, assets);
	if (ft_screen_size(assets))
		fd = -1;
	if (fd == -1 || argc != 2)
	{
		write(2, "Map Error\n", 10);
		exit(0);
	}
	vars.window = mlx_new_window(vars.screen, assets->len * 64, assets->y * 64, "Les Pixels se touchent");	
	printf("MAP :\n%s\n", assets->map);
	ft_put_grid(vars.screen, vars.window, assets);
	printf("AfterGrid\n");
	printf("Mush x: %d Mush y: %d\n", assets->mush->x[0], assets->mush->y[0]);
	printf("Mush x: %d Mush y: %d\n", assets->mush->x[1], assets->mush->y[1]);
	printf("Mush x: %d Mush y: %d\n", assets->mush->x[2], assets->mush->y[2]);
	printf("Mush x: %d Mush y: %d\n", assets->mush->x[3], assets->mush->y[3]);
	printf("ENUM : %d, %d, %d\n", PLAIN, CHAMPI, P_PLAYER);
	mlx_hook(vars.window, 2, 1L<<0, ft_close, &vars);
	mlx_hook(vars.window, 17, 1L<<17, ft_terminate, &vars);
	mlx_key_hook(vars.window, ft_key_hook, assets);
	mlx_loop_hook(vars.screen, ft_render_next, assets);
	mlx_loop(vars.screen);
	ft_free_to_destroy(vars.screen, assets);	
	exit(0);
	return (0);
}
