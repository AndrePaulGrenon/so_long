/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_to_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:27:05 by agrenon           #+#    #+#             */
/*   Updated: 2022/04/27 16:27:21 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_to_destroy(void *screen, t_assets *assets)
{
	mlx_destroy_image(screen, assets->grass[0]);
	mlx_destroy_image(screen, assets->grass[1]);
	mlx_destroy_image(screen, assets->grass[2]);
	mlx_destroy_image(screen, assets->rock_left);
	mlx_destroy_image(screen, assets->rock_right);
	mlx_destroy_image(screen, assets->rock_line);
	mlx_destroy_image(screen, assets->rock_column);
	mlx_destroy_image(screen, assets->tree);
	mlx_destroy_image(screen, assets->tent);
	mlx_destroy_image(screen, assets->supplies);
	mlx_destroy_image(screen, assets->l_road);
	mlx_destroy_image(screen, assets->r_road);
	mlx_destroy_image(screen, assets->road);
	if (assets)
		free(assets);
	return ;
}
