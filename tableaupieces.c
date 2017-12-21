#include "libft.h"
#include "header.h"

int					nbrederet(char *str)
{
	int		i;

	i = 1;
	while (*str)
	{
		if (*str == '\n')
			i++;
		str++;
	}
	return (i);
}

char				**tableaupieces(char *str)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (nbrederet(str) + 1))))
		return (NULL);
	while (*str)
	{
		j = 0;
		if ((i + 1) % 5 == 0)
			tab[i] = (char *)malloc(sizeof(char) * 1);
		else
			tab[i] = (char *)malloc(sizeof(char) * 5);
		while (*str != '\n')
			tab[i][j++] = *str++;
		str++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
