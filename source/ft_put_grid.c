/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:58:21 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/14 18:54:31 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_set_data(t_assets *assets, int *i, int *j)
{
	if (*j < assets->len)
	{
		assets->x = *j;
		*j = *j + 1;
	}
	else if (*j == assets->len && assets->map[*i] != '\n')
		return (1);
	else if (*j == assets->len)
	{
		*j = 0;
		assets->y++;
		assets->n_road = 0;
	}
	return (0);
}

void	ft_tile_select(t_assets *assets, void *screen, void *window, int i)
{
	int	x;
	int	y;

	x = assets->x * 64;
	y = assets->y * 64;
	if (assets->map[i] == '0')
		ft_set_grass(assets, screen, window);
	else if (assets->map[i] == '1')
		ft_set_box(assets, screen, window);
	else if (assets->map[i] == 'R')
		ft_set_road(assets, screen, window);
	else if (assets->map[i] == 'C')
		ft_set_mush(assets, screen, window);
	else if (assets->map[i] == 'E')
		ft_set_exit(assets, screen, window);
	else if (assets->map[i] == 'P')
		ft_set_player(assets, screen, window);
	else if (assets->map[i] == 'T')
		ft_set_tank(assets, screen, window);
	return ;
}

void	ft_put_grid(void *screen, void *window, t_assets *assets)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	assets->x = 0;
	assets->y = 0;
	while (assets->map[i])
	{
		if (ft_set_data(assets, &i, &j))
			return ;
		ft_tile_select(assets, screen, window, i);
		i++;
	}
	return ;
}
