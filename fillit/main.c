/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 01:41:55 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/07 14:05:13 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"
#include "header.h"

int		diesepoint(char *str)
{
	int j;
	int k;
	int i;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] && i < 20)
	{
		while (str[i] && (i + 1) % 5 != 0)
		{
			if (str[i] == '#' && ((str[i + 1] && str[i + 1] == '#') ||
				(str[i + 5] && str[i + 5] == '#') || 
				(str[i - 1] && str[i - 1] == '#') ||
				(str[i - 5] && str[i - 5] == '#')))
				k++;
			if (str[i] == '#' || str[i] == '.')
				i++;
			else
				return (1);
		}
		if (str[i] == '\n')
			j++;
		i++;
	}
	return ((j == 4 && k == 4) ? 0 : 1);
}

int		verification(char *str)
{
	int n;

	n = 1;
	while (*str)
	{
		if (diesepoint(str) == 0)
		{
			str = str + 19;
			if (str[0] == '\0')
				return (0);
			if (str[0] == '\n' && str[1] == '\n')
			{
				if (str[2] != '#' && str[2] != '.')
					return (1);
				str = str + 2;
			}
			else
				str = str + 1;
		}
		else
			return (1);
	}
	return (0);
}

void		sorttab(g_list *grille)
{
	int i;
	int j;

	i = -1;
	while (++i < grille->lenline)
	{
		j = -1;
		while (++j < grille->lenline)
			ft_putchar(grille->map[i][j]);
		ft_putchar('\n');
	}
}

int			taillemini(char *buf)
{
	int i;
	int j;

	j = 1;
	i = ((nbrederet(buf) + 1) / 5) * 4;
	while (j * j < i)
		j++;
	return (j);
}

int		main(int ac, char **av)
{
	int		fd;
	char	buf[4096];
	int		size;
	char	*buf2;
	pieces_list		*list;

	if (ac != 2)
		return (write(1, "usage: fillit source_file", 26));
	fd = open(av[1], 2);
	if (fd == -1)
	{
		ft_putstr("error");
		return (1);
	}
	size = read(fd, buf, 4095);
	buf[size] = 0;
	if (verification(buf) == 1)
	{
		ft_putstr("error\n");
		return (1);
	}
	sorttab(placepieces(creationtableau(taillemini(buf)), ft_construction(tableaupieces(buf)), 0, 0));
	close (fd);
	return (0);
};
