/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:11:51 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/02 14:05:31 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_player(t_assets *assets, void *screen, void *window)
{
	int	x;
	int	y;

	x = assets->x * 64;
	y = assets->y * 64;
	mlx_put_image_to_window(screen, window, assets->grass[0], x, y);
	mlx_put_image_to_window(screen, window, assets->player->left, x, y);
	assets->pos[assets->x][assets->y] = P_PLAYER;
	assets->player->x = assets->x;
	assets->player->y = assets->y;
}

void	ft_set_box(t_assets *assets, void *screen, void *window)
{
	int	x;
	int	y;

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
	assets->pos[assets->x][assets->y] = WALL;
	return ;
}

void	ft_set_grass(t_assets *assets, void *screen, void *window)
{
	int	x;
	int	y;

	x = assets->x * 64;
	y = assets->y * 64;
	mlx_put_image_to_window(screen, window, assets->grass[assets->x % 2], x, y);
	if (assets->x % 2)
		assets->pos[assets->x][assets->y] = PLAIN2;
	else
		assets->pos[assets->x][assets->y] = PLAIN;
}

void	ft_set_mush(t_assets *assets, void *screen, void *window)
{
	int	x;
	int	y;

	x = assets->x * 64;
	y = assets->y * 64;
	mlx_put_image_to_window(screen, window, assets->mush->img[0], x, y);
	assets->mush->x[assets->n_mush] = assets->x;
	assets->mush->y[assets->n_mush] = assets->y;
	assets->pos[assets->x][assets->y] = CHAMPI;
	assets->n_mush++;
	return ;
}
