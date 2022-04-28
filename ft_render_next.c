/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:40:05 by agrenon           #+#    #+#             */
/*   Updated: 2022/04/27 18:18:53 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_anim_walk(t_assets *assets, void *scre)
{
	static int	fr = 0;
	void		*win;
	int			x;
	int			y;
	void		**tab;

	x = assets->player->x * 64;
	y = assets->player->y * 64;
	tab = assets->player->right_move;
	if (fr == 99)
		fr = 0;
	win = assets->vars->window;
	ft_clean_behind(assets, x, y);
	if (assets->player->is_right)
		mlx_put_image_to_window(scre, win, tab[fr % 3], x, y);
	else
	{
		tab = assets->player->left_move;
		mlx_put_image_to_window(scre, win, tab[fr % 3], x, y);
	}
	fr++;
}

void	ft_anim_mush(t_assets *assets, void *s, void *w)
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
			mlx_put_image_to_window(s, w, assets->mush->img[img], x, y);
		}
		i++;
	}
	img++;
	return ;
}

void	ft_anim_collect(t_assets *assets, t_play *p, void *scre)
{
	static int	frame = 0;
	void		*win;
	int			x;
	int			y;

	x = assets->player->x * 64;
	y = assets->player->y * 64;
	if (frame == 10)
	{
		assets->collects = false;
		frame = 0;
		assets->pos[x / 64][y / 64] = 0;
	}
	win = assets->vars->window;
	if (frame > 5)
		mlx_put_image_to_window(scre, win, assets->grass[0], x, y);
	else
		mlx_put_image_to_window(scre, win, assets->mush->img[0], x, y);
	if (frame == 7)
		assets->collected++;
	if (assets->player->is_right)
		mlx_put_image_to_window(scre, win, p->right_collect[frame], x, y);
	else
		mlx_put_image_to_window(scre, win, p->left_collect[frame], x, y);
	frame++;
}

void	ft_select_anim(t_assets *data)
{
	static int	t = 0;

	if (t > 900)
	{
		if (!data->show_it)
		{
			ft_anim_mush(data, data->vars->screen, data->vars->window);
			if (data->collects)
				ft_anim_collect(data, data->player, data->vars->screen);
			else
				ft_anim_walk(data, data->vars->screen);
			ft_anim_tank(data);
		}
		if (data->show_it)
			ft_clean_message(data);
		ft_mini_ui(data);
		t = 0;
	}
	t++;
}

int	ft_render_next(void *assets)
{
	static int	move = 0;
	t_assets	*data;

	data = (t_assets *) assets;
	if (data->dead)
		data->cant_move = true;
	ft_select_anim(data);
	if (data->cant_move)
	{
		move++;
		if (move > 800 && data->collects == false)
		{
			move = 0;
			data->cant_move = false;
		}
		if (move > 3200 && data->collects == false)
		{
			move = 0;
			data->cant_move = false;
		}
	}
	return (0);
}
