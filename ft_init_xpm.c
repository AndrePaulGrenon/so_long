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

void	ft_set_collect(t_play *player, void *screen)
{
	player->right_collect[0] = ft_prep_assets(screen, P_COLLECT, "collect0");
	player->right_collect[1] = ft_prep_assets(screen, P_COLLECT, "collect1");
	player->right_collect[2] = ft_prep_assets(screen, P_COLLECT, "collect2");
	player->right_collect[3] = ft_prep_assets(screen, P_COLLECT, "collect3");
	player->right_collect[4] = ft_prep_assets(screen, P_COLLECT, "collect4");
	player->right_collect[5] = ft_prep_assets(screen, P_COLLECT, "collect5");
	player->right_collect[6] = ft_prep_assets(screen, P_COLLECT, "collect6");
	player->right_collect[7] = ft_prep_assets(screen, P_COLLECT, "collect7");
	player->right_collect[8] = ft_prep_assets(screen, P_COLLECT, "collect8");
	player->right_collect[9] = ft_prep_assets(screen, P_COLLECT, "collect9");
	player->right_collect[10] = ft_prep_assets(screen, P_COLLECT, "collect10");
}
void	ft_player(t_play *player, void *screen)
{
	player->left = ft_prep_assets(screen, P_MOVE, "rev_idle0");
	player->right = ft_prep_assets(screen, P_MOVE, "idle0");
	player->left_move[0] = ft_prep_assets(screen, P_MOVE, "move_left0");
	player->left_move[1] = ft_prep_assets(screen, P_MOVE, "move_left1");
	player->left_move[2] = ft_prep_assets(screen, P_MOVE, "move_left2");
	player->right_move[0] = ft_prep_assets(screen, P_MOVE, "move_right0");
	player->right_move[1] = ft_prep_assets(screen, P_MOVE, "move_right1");
	player->right_move[2] = ft_prep_assets(screen, P_MOVE, "move_right2");
	player->left_collect[0] = ft_prep_assets(screen, P_COLLECT, "rev_collect0");
	player->left_collect[1] = ft_prep_assets(screen, P_COLLECT, "rev_collect1");
	player->left_collect[2] = ft_prep_assets(screen, P_COLLECT, "rev_collect2");
	player->left_collect[3] = ft_prep_assets(screen, P_COLLECT, "rev_collect3");
	player->left_collect[4] = ft_prep_assets(screen, P_COLLECT, "rev_collect4");
	player->left_collect[5] = ft_prep_assets(screen, P_COLLECT, "rev_collect5");
	player->left_collect[6] = ft_prep_assets(screen, P_COLLECT, "rev_collect6");
	player->left_collect[7] = ft_prep_assets(screen, P_COLLECT, "rev_collect7");
	player->left_collect[8] = ft_prep_assets(screen, P_COLLECT, "rev_collect8");
	player->left_collect[9] = ft_prep_assets(screen, P_COLLECT, "rev_collect9");
	player->left_collect[10] = ft_prep_assets(screen, P_COLLECT, "rev_collect10");
	ft_set_collect(player, screen);
	return ;
}
void	ft_mush(t_mush *mush, void *screen)
{
	mush->img[0] = ft_prep_assets(screen, P_MUSH, "mush00");
	mush->img[1] = ft_prep_assets(screen, P_MUSH, "mush01");
	mush->img[2] = ft_prep_assets(screen, P_MUSH, "mush02");
	mush->img[3] = ft_prep_assets(screen, P_MUSH, "mush03");
	mush->img[4] = ft_prep_assets(screen, P_MUSH, "mush04");
	mush->img[5] = ft_prep_assets(screen, P_MUSH, "mush05");
	mush->img[6] = ft_prep_assets(screen, P_MUSH, "mush06");
	mush->img[7] = ft_prep_assets(screen, P_MUSH, "mush07");
	mush->img[8] = ft_prep_assets(screen, P_MUSH, "mush08");
	mush->img[9] = ft_prep_assets(screen, P_MUSH, "mush00");
	mush->img[10] = ft_prep_assets(screen, P_MUSH, "mush00");
	mush->img[11] = ft_prep_assets(screen, P_MUSH, "mush00");
	mush->img[12] = ft_prep_assets(screen, P_MUSH, "mush00");
	mush->img[13] = ft_prep_assets(screen, P_MUSH, "mush00");
	mush->img[14] = ft_prep_assets(screen, P_MUSH, "mush00");
	mush->img[15] = ft_prep_assets(screen, P_MUSH, "mush00");
	mush->img[16] = NULL;
	return ;	
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
	assets->tree = ft_prep_assets(screen, P_TERRAIN, "tree"); 
	assets->tent = ft_prep_assets(screen, P_TERRAIN, "tent"); 
	assets->supplies = ft_prep_assets(screen, P_TERRAIN, "supplies"); 
	assets->l_road = ft_prep_assets(screen, P_TERRAIN, "road_left"); 
	assets->r_road = ft_prep_assets(screen, P_TERRAIN, "road_right"); 
	assets->road = ft_prep_assets(screen, P_TERRAIN, "road_main");
	return ;
}

t_assets	*ft_init_xpm(void *screen)
{
	t_assets	*assets;

	assets = malloc(sizeof(t_assets));
	assets->mush = malloc(sizeof(t_mush));
	assets->player = malloc(sizeof(t_play));
	assets->mush->x = malloc(sizeof(int) * 100);
	assets->mush->y = malloc(sizeof(int) * 100);	
	ft_terrain(assets, screen);
	ft_mush(assets->mush, screen);
	ft_player(assets->player, screen);
	assets->player->moves = 0;
	assets->n_road = 0;
	assets->collected = 0;
	assets->x = 0;
	assets->y = 0;
	assets->len = 0;
	assets->map = NULL;
	return (assets); 
}
