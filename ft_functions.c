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
