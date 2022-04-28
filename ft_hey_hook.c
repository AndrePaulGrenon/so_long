/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hey_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:49:21 by agrenon           #+#    #+#             */
/*   Updated: 2022/04/28 16:29:02 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	ft_key_hook(int keycode, t_assets *assets)
{
	if (keycode == UP && !assets->cant_move)
		ft_move(assets, 0, -1);
	if (keycode == DOWN && !assets->cant_move)
		ft_move(assets, 0, 1);
	if (keycode == RIGHT && !assets->cant_move)
	{
		assets->player->is_right = true;
		ft_move(assets, 1, 0);
	}
	if (keycode == LEFT && !assets->cant_move)
	{
		assets->player->is_right = false;
		ft_move(assets, -1, 0);
	}
	return (0);
}
