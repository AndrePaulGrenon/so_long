/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:42:10 by agrenon           #+#    #+#             */
/*   Updated: 2022/04/28 16:20:41 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect(t_assets *assets, int nx, int ny)
{
	void	*win;
	void	*scre;
	void	*img_l;
	void	*img_r;
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
	void	*win;
	void	*scre;
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

void	ft_clean_behind(t_assets *assets, int dx, int dy)
{
	void	*win;
	void	*scre;

	scre = assets->vars->screen;
	win = assets->vars->window;
	if (assets->pos[dx / 64][dy / 64] == PLAIN2)
		mlx_put_image_to_window(scre, win, assets->grass[1], dx, dy);
	else if (assets->pos[dx / 64][dy / 64] == PLAIN)
		mlx_put_image_to_window(scre, win, assets->grass[0], dx, dy);
	else if (assets->pos[dx / 64][dy / 64] == ROAD)
		mlx_put_image_to_window(scre, win, assets->road, dx, dy);
	else if (assets->pos[dx / 64][dy / 64] == L_ROAD)
		mlx_put_image_to_window(scre, win, assets->l_road, dx, dy);
	else if (assets->pos[dx / 64][dy / 64] == R_ROAD)
		mlx_put_image_to_window(scre, win, assets->r_road, dx, dy);
	else
		mlx_put_image_to_window(scre, win, assets->grass[0], dx, dy);
}

bool	ft_check_tank(t_assets *assets, int x, int y)
{
	int	i;

	i = 0;
	while (i < assets->n_tank)
	{
		if (assets->tank->xt[i] == x && assets->tank->yt[i] == y)
			return (true);
		i++;
	}
	return (false);
}

void	ft_move(t_assets *assets, int dx, int dy)
{
	int		x;
	int		y;
	bool	tank;

	x = assets->player->x;
	y = assets->player->y;
	tank = ft_check_tank(assets, x + dx, y + dy);
	if (assets->pos[x + dx][y + dy] < 7 && !tank)
	{
		if (assets->pos[x + dx][y + dy] != CHAMPI)
			ft_walk(assets, 64 * (x + dx), 64 * (y + dy));
		else
			ft_collect(assets, 64 * (x + dx), 64 * (y + dy));
		ft_clean_behind(assets, 64 * x, 64 * y);
		assets->player->x = x + dx;
		assets->player->y = y + dy;
		assets->player->moves++;
		assets->cant_move = true;
		ft_print_moves(assets);
	}
	if (assets->pos[x + dx][y + dy] == EX)
		ft_exit(assets);
	return ;
}
