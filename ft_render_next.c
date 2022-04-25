#include "so_long.h"

void	ft_anim_walk(t_assets *assets)
{
	static int	frame = 0;
	void		*win;
	void		*scre;
	int 		x;
	int 		y;
	
	x = assets->player->x * 64;
	y = assets->player->y * 64;
	if (frame == 99)
		frame = 0;
	win = assets->vars->window;
    scre = assets->vars->screen;
	ft_clean_behind(assets, x, y);
/*	if (assets->pos[x / 64][y / 64] == 1)
		mlx_put_image_to_window(scre, win, assets->grass[1], x, y);
	else
		mlx_put_image_to_window(scre, win, assets->grass[0], x, y);*/
	if (assets->player->is_right)
		mlx_put_image_to_window(scre, win, assets->player->right_move[frame % 3], x, y);
	else
		mlx_put_image_to_window(scre, win, assets->player->left_move[frame % 3], x, y);
	frame++;
}

void	ft_anim_mush(t_assets *assets)
{
	int			i;
	int			x;
	int			y;
	static int	img = 0;

	i = 0;
	if (img == 15)
		img = 0;
	while (assets->mush->x[i])
	{
		if (assets->mush->x[i] != -1)
		{
			x = assets->mush->x[i] * 64;
			y = assets->mush->y[i] * 64;
			mlx_put_image_to_window(assets->vars->screen, assets->vars->window, assets->mush->img[img], x, y);
		}
		i++;
	}
	img++;
	return ;
}

void	ft_anim_collect(t_assets *assets)
{
	static int  frame = 0;
    void        *win;
    void        *scre;
    int         x;
    int         y;

    x = assets->player->x * 64;
    y = assets->player->y * 64;
    if (frame == 10)
	{
		assets->collects = false;
        frame = 0;
		assets->pos[x / 64][y / 64] = 0;
	}
    win = assets->vars->window;
    scre = assets->vars->screen;
	if (frame > 5)
		mlx_put_image_to_window(scre, win, assets->grass[0], x, y);
    else
        mlx_put_image_to_window(scre, win, assets->mush->img[0], x, y);
	if (frame == 7)
		assets->collected++;
	if (assets->player->is_right)
        mlx_put_image_to_window(scre, win, assets->player->right_collect[frame], x, y);
    else
    	mlx_put_image_to_window(scre, win, assets->player->left_collect[frame], x, y);
	
	frame++;
}

int	ft_render_next(void *assets)
{
	static int	t = 0;
	static int	move = 0;
	t_assets	*data;

	data = (t_assets *) assets;
	t++;
	if (t > 800)
	{
		ft_anim_mush(data);
		if (data->collects)
			ft_anim_collect(data);
		else
			ft_anim_walk(data);
		ft_mini_ui(data);
		t = 0;
	}
	if (data->cant_move)
	{
		move++;
		if (move > 1200 && data->collects == false)
		{
			move = 0;
			data->cant_move = false;
		}
		if (move > 5400 && data->collects == false)
		{
			move = 0;
			data->cant_move = false;
		}
	}
	return (0);
}
