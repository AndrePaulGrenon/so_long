/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:19:42 by agrenon           #+#    #+#             */
/*   Updated: 2022/04/28 15:58:36 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_square_is_wall(t_assets *assets, int i, int j)
{
	if (assets->y == 0 && assets->map[i] != '1')
		return (1);
	if (j == 1 && assets->map[i] != '1')
		return (1);
	if (i > (ft_strlen(assets->map) - assets->len) && assets->map[i] != '1')
		return (1);
	if (j == assets->len && assets->map[i] != '1')
		return (1);
	return (0);
}

int	ft_check_it(t_assets *assets, int i, int j)
{
	char		c;
	static int	c_count = 0;	
	static int	p_count = 0;	
	static int	t_count = 0;	
	static int	e_count = 0;

	if (assets->map[i] == 'P')
		p_count++;
	if (assets->map[i] == 'E')
		e_count++;
	if (assets->map[i] == 'T')
		t_count++;
	if (assets->map[i] == 'C')
		c_count++;
	if (assets->map[i + 1] == '\0' && (p_count != 1 || !c_count))
		return (1);
	if (assets->map[i + 1] == '\0' && (e_count != 1))
		return (1);
	if (assets->map[i + 1] == '\0' && (t_count > 10 || c_count > 99))
		return (1);
	c = assets->map[i];
	if (ft_square_is_wall(assets, i, j))
		return (1);
	return (0);
}

int	ft_set_da(t_assets *assets, int *i, int *j)
{
	if (assets->map[*i] == '\n' && assets->len && assets->len != *j)
		return (1);
	if (assets->map[*i + 1] == '\0' && assets->len && assets->len != *j + 1)
		return (1);
	if (assets->map[*i] == '\n' && assets->len == 0)
	{
		assets->y++;
		assets->len = *i;
	}
	else if (assets->len == 0)
		assets->x = *i;
	else if (*j < assets->len)
	{
		assets->x = *j;
		*j = *j + 1;
	}
	else if (*j == assets->len)
	{
		*j = 0;
		assets->y++;
	}
	return (0);
}

int	ft_check_char(t_assets *assets, int i)
{
	if (assets->map[i] == '0')
		return (0);
	else if (assets->map[i] == '1')
		return (0);
	else if (assets->map[i] == 'R')
		return (0);
	else if (assets->map[i] == 'C')
		return (0);
	else if (assets->map[i] == 'E')
		return (0);
	else if (assets->map[i] == 'P')
		return (0);
	else if (assets->map[i] == '\n')
		return (0);
	else if (assets->map[i] == 'T')
		return (0);
	else
		return (1);
}

int	ft_screen_size(t_assets *assets)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!assets->map)
		return (-1);
	while (assets->map[i])
	{
		if (ft_set_da(assets, &i, &j) || ft_check_it(assets, i, j))
			return (1);
		if (j > 41 || ft_check_char(assets, i))
			return (1);
		i++;
	}
	assets->y++;
	assets->heigth = assets->y - 1;
	if (assets->heigth > 22)
		return (1);
	return (0);
}
