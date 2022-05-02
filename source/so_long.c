/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:44:46 by agrenon           #+#    #+#             */
/*   Updated: 2022/05/02 12:39:11 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_mlx_functions(t_assets *assets, t_vars *vars)
{
	ft_init_tank_speed(assets);
	mlx_hook(vars->window, 2, 1L << 0, ft_close, vars);
	mlx_hook(vars->window, 17, 1L << 17, ft_terminate, vars);
	mlx_key_hook(vars->window, ft_key_hook, assets);
	mlx_loop_hook(vars->screen, ft_render_next, assets);
	mlx_loop(vars->screen);
	ft_free_to_destroy(vars->screen, assets);
	return ;
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_assets	*assets;
	int			fd;
	int			len;

	vars.screen = mlx_init();
	assets = ft_init_xpm(vars.screen);
	assets->vars = &vars;
	fd = ft_open_map(argv, assets);
	if (fd == -1 || argc != 2 || ft_screen_size(assets))
	{
		write(2, "Map Error\n", 10);
		exit(0);
	}
	len = assets->len * 64;
	fd = assets->y * 64;
	vars.window = mlx_new_window(vars.screen, len, fd, TITLE);
	ft_put_grid(vars.screen, vars.window, assets);
	ft_mlx_functions(assets, &vars);
	exit(0);
	return (0);
}
