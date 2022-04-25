#include "so_long.h"

void	ft_collect(t_assets *assets, int nx, int ny)
{
	void    *win;
    void    *scre;
    void    *img_l;
    void    *img_r;
	int		i;

	img_l = assets->player->left;
    img_r = assets->player->right;
    win = assets->vars->window;
	scre = assets->vars->screen;
	i = 0;
	if (assets->player->is_right == false)
		mlx_put_image_to_window(scre, win, img_l, nx, ny);
	else
		mlx_put_image_to_window(scre, win, img_r, nx, ny);
	assets->collects = true;
	while (assets->mush->x[i])
	{
		if (assets->mush->x[i] == nx / 64 && assets->mush->y[i] == ny / 64)
			assets->mush->x[i] = -1;
		i++;
	}
	return ;
}

void	ft_walk(t_assets *assets, int nx, int ny)
{
	void    *win;
	void    *scre;
	void	*img_l;
	void	*img_r;

	img_l = assets->player->left;
	img_r = assets->player->right;
	scre = assets->vars->screen;
	win = assets->vars->window;

	if (assets->player->is_right == false)
		mlx_put_image_to_window(scre, win, img_l, nx, ny);
	else
		mlx_put_image_to_window(scre, win, img_r, nx, ny);
	return ;
}

void    ft_move(t_assets *assets, int dx, int dy)
{
    int		x;
    int		y;
    void    *win;
    void    *scre;

    scre = assets->vars->screen;
    win = assets->vars->window;
    x = assets->player->x;
    y = assets->player->y;
//	printf("playerx : %d playery: %d dx:%d dy; %d\n", x, y , dx , dy);
	if (assets->pos[x + dx][y + dy] != 2)
	{
		if (assets->pos[x + dx][y + dy] != 3)
			ft_walk(assets, 64 * (x + dx),  64 * (y + dy));
		else
			ft_collect(assets, 64 * (x + dx), 64 * (y + dy));
		if (assets->pos[x][y] == 1)
			mlx_put_image_to_window(scre, win, assets->grass[1], 64 * x, 64 * y);
		else
			mlx_put_image_to_window(scre, win, assets->grass[0], 64 * x, 64 * y);	
    	assets->player->x = x + dx;
    	assets->player->y = y + dy;
		assets->player->moves++;
        assets->cant_move = true;
		ft_print_moves(assets);
	}
	return ;
}

int ft_key_hook(int keycode, t_assets *assets)
{
	if (keycode == UP && !assets->cant_move)
		ft_move(assets, 0, -1);
	if (keycode == DOWN && !assets->cant_move)
		ft_move(assets, 0, 1);
	if (keycode == RIGHT && !assets->cant_move)
	{
		assets->player->is_right = true;
		ft_move(assets, 1, 0);
	}
	if (keycode == LEFT && !assets->cant_move)
	{
		assets->player->is_right = false;
		ft_move(assets, -1, 0);
	}
	return (0);
}
