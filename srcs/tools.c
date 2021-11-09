#include "ft_ping.h"

int		ft_strlen(const char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

char		ft_strchr(const char *str, char to_find)
{
	for (int i = 0; i < ft_strlen(str); i++)
		if (str[i] == to_find)
			return (1);
	return (0);
}

void		ft_bzero(void *s, size_t n)
{
	char *str = s;
	for (int i = 0; i < n; i++)
		str[i] = 0;		
}

void		*ft_memcpy(void *s1, void *s2, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = s1;
	str2 = s2;
	for (int i = 0; i < n; i++)
		str1[i] = str2[i];
	return (s2);
}

void		StopTheCount(int wech)
{
	g_loop = false;
}
