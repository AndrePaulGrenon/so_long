/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:23:15 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/02 14:42:07 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_set_tank(t_assets *assets, void *scre, void *win)
{
	int	x;
	int	y;

	x = assets->x;
	y = assets->y;
	mlx_put_image_to_window(scre, win, assets->l_road, x * 64, y * 64);
	assets->pos[x][y] = ROAD;
	mlx_put_image_to_window(scre, win, assets->tank->rig[3], x * 64, y * 64);
	if (assets->n_tank % 2)
		assets->tank->is_right[assets->n_tank] = true;
	else
		assets->tank->is_right[assets->n_tank] = false;
	assets->tank->xt[assets->n_tank] = x;
	assets->tank->yt[assets->n_tank] = y;
	assets->n_tank++;
}

void	ft_set_road(t_assets *assets, void *screen, void *window)
{
	int	x;
	int	y;
	int	k;

	x = assets->x * 64;
	y = assets->y * 64;
	k = (assets->len * assets->y) + assets->x + assets->y;
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

void	ft_set_exit(t_assets *assets, void *screen, void *window)
{
	int	x;
	int	y;

	x = assets->x * 64;
	y = assets->y * 64;
	mlx_put_image_to_window(screen, window, assets->tent, x, y);
	assets->pos[assets->x][assets->y] = EX;
	assets->exit->x = x;
	assets->exit->y = y;
	return ;
}
