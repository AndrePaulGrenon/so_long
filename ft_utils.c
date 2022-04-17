#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
	printf("str1:%s\nstr2:%s\nlen:%d\nXXXXXXXXXX str1: %p\nXXXXXXXXXXX str2:%p\n\n", str1,str2, len, str1, str2);
	temp = malloc(sizeof(char) * len);
	temp[len - 1] = '\0';
	while (str1[i])
		temp[j++] = str1[i++];
	i = 0;
	while (str2[i] == '\n' || str2[i] > 30)
		temp[j++] = str2[i++];
	//if (str1)
		free(str1);
	//if (str2)
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
	//printf("\nXXXXXXXXXX newPTR: %p\n\n", ptr);	
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
