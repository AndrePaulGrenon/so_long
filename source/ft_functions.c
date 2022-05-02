/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:27:45 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/02 14:42:40 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->screen, vars->window);
		exit (0);
	}
	return (0);
}

int	ft_terminate(int keycode, t_vars *vars)
{
	(void) keycode;
	(void) vars;
	exit(0);
	return (0);
}

void	ft_clean_object(t_assets *assets)
{
	int		j;
	void	*win;
	void	*scre;
	void	**t;

	win = assets->vars->window;
	scre = assets->vars->screen;
	t = assets->grass;
	j = 0;
	while (j < 6)
	{
		if (assets->pos[j][2] < 2)
			mlx_put_image_to_window(scre, win, t[j % 2], j * 64, 128);
		else if (assets->pos[j][2] == WALL && j)
			mlx_put_image_to_window(scre, win, assets->tree, j * 64, 128);
		j++;
	}
	return ;
}

void	ft_clean_message(t_assets *assets)
{
	static int	i = 0;
	void		*win;
	void		*scre;
	int			j;

	j = 0;
	win = assets->vars->window;
	scre = assets->vars->screen;
	i++;
	if (i > 18)
	{
		if (assets->victory || assets->dead)
			exit(0);
		ft_clean_object(assets);
		assets->show_it = false;
		i = 0;
	}
}

void	ft_exit(t_assets *assets)
{
	void	*win;
	void	*scre;

	scre = assets->vars->screen;
	win = assets->vars->window;
	assets->victory = false;
	if (assets->collected < (assets->n_mush - assets->no_mush) && !assets->dead)
	{
		ft_show_it(assets, 192, 28, 132);
		mlx_string_put(scre, win, 138, 138, 0xFF22FA, "NEED MORE SHROOMS!");
	}
	else if (assets->dead)
	{
		ft_show_it(assets, 208, 28, 132);
		mlx_string_put(scre, win, 138, 138, 0xFF0000, "!!YOU GOT SQUASHED!!");
		assets->victory = true;
	}
	else if (assets->collected == (assets->n_mush - assets->no_mush))
	{
		ft_show_it(assets, 208, 28, 132);
		mlx_string_put(scre, win, 138, 138, 0x0330F000, "YOU SAVED REFUGEES!");
		assets->victory = true;
	}
	assets->show_it = true;
}
