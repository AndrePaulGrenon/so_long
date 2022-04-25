#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar_fd(n + 48, fd);
	return ;
}


char    *ft_join(char *str1, char *str2)
{
	char	*temp;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	temp = malloc(sizeof(char) * len);
	temp[len - 1] = '\0';
	while (str1[i])
		temp[j++] = str1[i++];
	i = 0;
	while (str2[i] == '\n' || str2[i] > 30)
		temp[j++] = str2[i++];
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (temp);
}

char	*nw_pth(char *PATH, char *xpm)
{
	int		i;
	int		j;
	int		len;
	char	*ptr;
	
	len = ft_strlen(PATH) + ft_strlen(xpm) + 5;
	i = 0;
	j = 0;
	ptr = malloc(sizeof(char) * len);
	ptr[len - 1] = '\0';
	while (PATH[i])
		ptr[j++] = PATH[i++];
	i = 0;
	while (xpm[i])
		ptr[j++] = xpm[i++];
	i = 0;
	while (XPM[i])
		ptr[j++] = XPM[i++];
	return (ptr);
}
