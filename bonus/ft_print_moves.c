/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:57:58 by agrenon           #+#    #+#             */
/*   Updated: 2022/04/27 17:58:12 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_print_moves(t_assets *assets)
{
	write(1, "Moves: ", 6);
	ft_putnbr_fd(assets->player->moves, 1);
	write(1, "\n", 1);
}
