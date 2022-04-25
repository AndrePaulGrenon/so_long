#include <so_long.h>

void	ft_print_moves(t_assets *assets)
{
	write(1, "Moves: ", 6);
	ft_putnbr_fd(assets->player->moves, 1);
	write(1, "\n", 1);
}
