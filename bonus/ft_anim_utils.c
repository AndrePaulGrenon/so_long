/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:22:52 by agrenon           #+#    #+#             */
/*   Updated: 2022/04/28 18:15:30 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_init_tank_speed(t_assets *assets)
{
	int	i;

	printf("ALLO\n");
	i = 0;
	while (i < assets->n_tank)
	{
		assets->tank->speed[i] = 2 + rand() % 5;
		i++;
	}
	return ;
}

void	ft_delete_shrooms(t_assets *assets, int x, int y)
{
	int	i;

	i = 0;
	while (assets->mush->x[i])
	{
		if (assets->mush->x[i] == x && assets->mush->y[i] == y)
			assets->mush->x[i] = -1;
		i++;
	}
	assets->no_mush++;
	return ;
}
