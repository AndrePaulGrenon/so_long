/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:06:26 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/02 14:10:27 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_terrain(t_assets *assets, void *screen)
{
	assets->grass[2] = ft_prep_assets(screen, P_TERRAIN, "grass0");
	assets->grass[1] = ft_prep_assets(screen, P_TERRAIN, "grass1");
	assets->grass[0] = ft_prep_assets(screen, P_TERRAIN, "plain");
	assets->rock_left = ft_prep_assets(screen, P_TERRAIN, "rock_left");
	assets->rock_right = ft_prep_assets(screen, P_TERRAIN, "rock_right");
	assets->rock_line = ft_prep_assets(screen, P_TERRAIN, "rock_line");
	assets->rock_column = ft_prep_assets(screen, P_TERRAIN, "rock_column");
	assets->tree = ft_prep_assets(screen, P_TERRAIN, "tree");
	assets->tent = ft_prep_assets(screen, P_TERRAIN, "tent");
	assets->supplies = ft_prep_assets(screen, P_TERRAIN, "supplies");
	assets->l_road = ft_prep_assets(screen, P_TERRAIN, "road_left");
	assets->r_road = ft_prep_assets(screen, P_TERRAIN, "road_right");
	assets->road = ft_prep_assets(screen, P_TERRAIN, "road_main");
	assets->tank->rig[0] = ft_prep_assets(screen, P_TANK, "tank0");
	assets->tank->rig[1] = ft_prep_assets(screen, P_TANK, "tank1");
	assets->tank->rig[2] = ft_prep_assets(screen, P_TANK, "tank2");
	assets->tank->rig[3] = ft_prep_assets(screen, P_TANK, "tank3");
	assets->tank->rig[4] = ft_prep_assets(screen, P_TANK, "rev0");
	assets->tank->rig[5] = ft_prep_assets(screen, P_TANK, "rev1");
	assets->tank->rig[6] = ft_prep_assets(screen, P_TANK, "rev2");
	assets->tank->rig[7] = ft_prep_assets(screen, P_TANK, "rev3");
	return ;
}
