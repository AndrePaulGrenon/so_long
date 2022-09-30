/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:55:35 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/30 18:06:50 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ber(char **argv)
{
	int	i;

	i = ft_strlen(argv[1]);
	if (argv[1][i - 4] != '.' || argv[1][i - 3] != 'b')
		return (1);
	if (argv[1][i - 2] != 'e' || argv[1][i - 1] != 'r')
		return (1);
	return (0);
}

int	ft_open_map(char **argv, t_assets *assets)
{
	int	fd;

	if (argv[1] && ft_check_ber(argv))
		return (-1);
	fd = open(argv[1], O_RDWR | O_NOFOLLOW);
	if (fd == -1)
		return (-1);
	assets->map = ft_get_map(fd);
	(void) assets;
	close(fd);
	return (0);
}
