#include "so_long.h"

int		ft_open_map(char **argv, t_assets *assets)
{
	int		fd;

	fd = 0;
	fd = open(argv[1], O_RDONLY | O_NOFOLLOW);
	if (fd == -1)
		return (-1);
	assets->map = ft_get_map(fd);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	void		*screen;
	void		*window;
	t_assets	*assets;
	int			fd;

	(void) argc;
	screen =  mlx_init();
	window = mlx_new_window(screen, 1920, 1080, "Les Pixels se touchent");	
	
	assets = ft_init_xpm(screen);	
	fd = ft_open_map(argv, assets);
	
//	printf("map address: %p\nassets adress: %p\n\n", assets->map, assets);
	
	if (fd == -1)
	{
		ft_free_to_destroy(screen, assets);	
		write(2, "Map Error\n", 10);
		return (-1);
	}
	printf("MAP :\n%s\n", assets->map);

	ft_put_grid(screen, window, assets);
	mlx_loop(screen);
	ft_free_to_destroy(screen, assets);	
	return (0);
}
