#include "so_long.h"

int	ft_check_it(t_assets *assets, int *i, int *j)
{
    
	if (*j == assets->len && assets->map[*i] != '\n')
        return (0);
	if (assets->map[*i] == '\n' && assets->len != 0 && *j != assets->len - 1)
		return (0);
	return (0);
}

void	ft_set_da(t_assets *assets, int *i ,int *j)
{
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
    return ;
}

int	ft_screen_size(t_assets *assets)
{
    int i;
    int j;

    j = 0;
    i = 0;
    if (!assets->map)
        return (-1);
    while (assets->map[i])
    {
        ft_set_da(assets, &i, &j);
        if (ft_check_it(assets, &i, &j))
			return (1);
		i++;
    }
	assets->y++;
    assets->heigth = assets->y - 1;
    return (0);
}
