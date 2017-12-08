/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sauverpieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:02:18 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/07 10:59:55 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

int		nbrederet(char *str)
{
	int		i;

	i = 1;
	while (*str)
	{
		if (*str == '\n')
			i++;
		str++;
	}
	return i;
}

char **tableaupieces(char *str)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	if(!(tab = (char **)malloc(sizeof(char *) * (nbrederet(str) + 1))))
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

pieces_list		*ft_construction(char **tab)
{
	int i;
	int j;
	int k;
	pieces_list *list;
	pieces_list *save;
	pieces_list *tmp;
	
	if(!(list = (pieces_list *)malloc(sizeof(pieces_list))))
		return (NULL);
	list->previous = NULL;
	list->next = NULL;
	save = list;
	i = 0;
	while (tab[i] != 0)
	{
		k = 0;
		while ((i + 1) % 5 != 0 && tab[i] != 0)
		{
			j = -1;
			while (++j < 4)
			{
				if (tab[i][j] && tab[i][j] == '#')
				{
					if (k == 0)
					{
						list->shiftx = i;
						list->shifty = j;
					}
					list->tab[k][0] = i - list->shiftx;
					list->tab[k][1] = j - list->shifty;
					k++;
				}
			}
			i++;
		}
		if (tab[i] != 0 && (i + 1) % 5 == 0)
		{
			i++;
			tmp = list;
			if(!(list->next = (pieces_list *)malloc(sizeof(pieces_list))))
				return (NULL);
			list = list->next;
			list->next = NULL;
			list->previous = tmp;
		}
	}
	return (save);
}
