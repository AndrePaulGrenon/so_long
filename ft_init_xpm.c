#include "so_long.h"

void	*ft_prep_assets(void *scrn, char *PTH, char *fl)
{
	void	*img;
	char	*pth;
	int		size;

	size = 64;
	pth = nw_pth(PTH, fl);
	img = mlx_xpm_file_to_image(scrn, pth, &size, &size);
	free(pth);
	return (img);
}

void	ft_terrain(t_assets *assets, void *screen)
{
	assets->grass[2] = ft_prep_assets(screen, P_TERRAIN, "grass0");
	assets->grass[1] = ft_prep_assets(screen, P_TERRAIN, "grass1"); 
	assets->grass[0] = ft_prep_assets(screen, P_TERRAIN, "plain"); 
	assets->rock_left = ft_prep_assets(screen, P_TERRAIN, "rock_left"); 
	assets->rock_right = ft_prep_assets(screen, P_TERRAIN, "rock_right"); 
	assets->rock_line = ft_prep_assets(screen, P_TERRAIN, "rock_line"); 
	assets->rock_column = ft_prep_assets(screen, P_TERRAIN, "rock_column"); 
	assets->rock_column = ft_prep_assets(screen, P_TERRAIN, "rock_column"); 
	assets->tree = ft_prep_assets(screen, P_TERRAIN, "tree"); 
	assets->tent = ft_prep_assets(screen, P_TERRAIN, "tent"); 
	assets->supplies = ft_prep_assets(screen, P_TERRAIN, "supplies"); 
	assets->road_left = ft_prep_assets(screen, P_TERRAIN, "road_left"); 
	assets->road_right = ft_prep_assets(screen, P_TERRAIN, "road_right"); 
	assets->road_main = ft_prep_assets(screen, P_TERRAIN, "road_main");
	return ;
}

t_assets	*ft_init_xpm(void *screen)
{
	t_assets	*assets;

	assets = malloc(sizeof(t_assets));
	ft_terrain(assets, screen);
	assets->x = 0;
	assets->y = 0;
	assets->map = NULL;
	return (assets); 
}
