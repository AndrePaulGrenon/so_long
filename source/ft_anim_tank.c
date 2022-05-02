/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim_tank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:53:53 by agrenon           #+#    #+#             */
/*   Updated: 2022/04/28 16:39:55 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_assaults(t_assets *assets, int t)
{
	int		x;
	int		y;
	void	*win;
	void	*scre;

	win = assets->vars->window;
	scre = assets->vars->screen;
	x = assets->tank->xt[t];
	y = assets->tank->yt[t];
	if (assets->tank->is_right[t] && assets->pos[x + 1][y] < 6)
		assets->tank->xt[t] = x + 1;
	else if (!assets->tank->is_right[t] && assets->pos[x - 1][y] < 6)
		assets->tank->xt[t] = x - 1;
	else if (assets->tank->is_right[t])
		assets->tank->is_right[t] = false;
	else if (assets->tank->is_right[t] == false)
		assets->tank->is_right[t] = true;
	ft_clean_behind(assets, x * 64, y * 64);
	mlx_put_image_to_window(scre, win, assets->road, x * 64, y * 64);
	if (assets->pos[x][y] == CHAMPI)
		ft_delete_shrooms(assets, x, y);
	assets->pos[x][y] = ROAD;
	return ;
}

void	ft_tank_invasion(t_assets *assets)
{
	static int	invasion = 0;
	int			i;
	int			x;
	int			y;

	i = 0;
	invasion++;
	if (invasion > 255)
		invasion = 0;
	while (i < assets->n_tank)
	{
		if (invasion % assets->tank->speed[i] == 0)
			ft_assaults(assets, i);
		x = assets->tank->xt[i];
		y = assets->tank->yt[i];
		if (x == assets->player->x && y == assets->player->y)
		{
			assets->dead = true;
			ft_exit(assets);
		}
		i++;
	}
}

void	ft_trail_clean(t_assets *assets, int f, int i)
{
	int		x;
	int		y;
	void	*w;
	void	*s;

	x = assets->tank->xt[i] * 64;
	y = assets->tank->yt[i] * 64;
	w = assets->vars->window;
	s = assets->vars->screen;
	ft_clean_behind(assets, x, y);
	if (assets->tank->is_right[i])
		mlx_put_image_to_window(s, w, assets->tank->rig[f], x, y);
	else
		mlx_put_image_to_window(s, w, assets->tank->rig[f + 4], x, y);
	return ;
}

void	ft_anim_tank(t_assets *assets)
{
	int			i;
	static int	f = 0;
	int			xt;
	int			yt;

	i = 0;
	if (f > 3)
		f = 0;
	ft_tank_invasion(assets);
	while (i < assets->n_tank)
	{
		xt = assets->tank->xt[i] * 64;
		yt = assets->tank->yt[i] * 64;
		ft_trail_clean(assets, f, i);
		i++;
	}
	f++;
}
