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

	temp = malloc(sizeof(char) * (BUFF + 1));
	temp[BUFF] = '\0';
	i = read(fd, temp, BUFF);
	if (i < BUFF)
		temp = ft_trim(temp, i);
	if (!i)
	{	
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
