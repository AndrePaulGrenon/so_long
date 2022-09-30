/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:56:47 by agrenon           #+#    #+#             */
/*   Updated: 2022/09/30 18:04:02 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_trim(char *str, int size)
{
	int		i;
	char	*temp;

	temp = malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < size - 1)
	{
		temp[i] = str[i];
		i++;
	}
	free(str);
	temp[i] = '\0';
	return (temp);
}

char	*ft_read_map(int fd)
{
	char	*temp;
	int		i;
	static	int	antibug = 0;

	temp = malloc(sizeof(char) * (BUFF + 1));
	temp[BUFF] = '\0';
	i = read(fd, temp, BUFF);
	antibug++;
	if (i < BUFF)
		temp = ft_trim(temp, i);
	if (!i || antibug > 100)
	{
		if (antibug > 100)
			printf("STOP PUTTING DIRECTORIES! IDIOT! \n");
		free(temp);
		return (0);
	}
	return (temp);
}

char	*ft_get_map(int fd)
{
	char	*read;
	char	*map;

	read = ft_read_map(fd);
	map = read;
	if (!read)
		return (NULL);
	while (read)
	{
		read = ft_read_map(fd);
		if (!read)
			break ;
		map = ft_join(map, read);
	}
	free(read);
	return (map);
}
