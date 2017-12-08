/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:32:52 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/07 14:18:32 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

g_list	*creationtableau(int size)
{
	g_list		*grille;
	int			i;
	int			j;

	if(!(grille = (g_list *)malloc(sizeof(g_list))))
		return (NULL);
	grille->x = 0;
	grille->y = 0;
	grille->lenline = size;
	grille->i = -1;
	if(!(grille->map = (char **)malloc(sizeof(char *) * grille->lenline)))
		return (NULL);
	i = -1;
	while (++i < grille->lenline)
	{
		if(!(grille->map[i] = (char *)malloc(sizeof(char) * grille->lenline)))
			return (NULL);
		j = -1;
		while (++j < grille->lenline)
			grille->map[i][j] = '.';
	}
	return (grille);
}

int		libre(g_list *grille, pieces_list *list, int x, int y)
{
	int		k;

	grille->x = x;
	grille->y = y;
	while (grille->x < grille->lenline)
	{
		while (grille->y < grille->lenline)
		{
			k = 0;
			while (k < 4 && grille->x + list->tab[k][0] != grille->lenline &&
					grille->y + list->tab[k][1] != grille->lenline
					&& grille->x + list->tab[k][0] > -1 
					&& grille->y + list->tab[k][1] > -1 &&
					grille->map[(grille->x + list->tab[k][0])][(grille->y + list->tab[k][1])] == '.')
				k++;
			if (k == 4)
			{
				return (1);
			}
			(grille->y)++;
		}
		(grille->x)++;
		grille->y = 0;
	}
	return (0);
}

void		place_piece(g_list *grille, pieces_list *list, int i)
{
	int			k;

	k = -1;
	list->shiftx = grille->x;
	list->shifty = grille->y;
	while (++k < 4)
		grille->map[grille->x + list->tab[k][0]][grille->y + list->tab[k][1]]
			= 'A' + i;
	(grille->y)++;
	if (grille->y == grille->lenline)
	{
		grille->x = grille->x + 1;
		grille->y = 0;
	}
}

void		supprime_piece(g_list *grille, pieces_list *list)
{
	int			k;

	grille->x = list->shiftx;
	grille->y = list->shifty;
	k = -1;
	while (++k < 4)
	{
		grille->map[(grille->x + list->tab[k][0])][(grille->y + list->tab[k][1])] = '.';
	}
			(grille->i)--;
			(grille->y)++;
			if ((grille->y) == grille->lenline)
			{
				(grille->x)++;
				(grille->y) = 0;
			}
}

g_list		*placepieces(g_list *grille, pieces_list *list, int x, int y)
{
	if (list != NULL)
	{
		if (libre(grille, list, x, y) == 1)
		{
			place_piece(grille, list, ++(grille->i));
			sorttab(grille);
			ft_putchar('\n');
			if (list->next == NULL)
				return (grille);
			return (placepieces(grille, list->next, 0, 0));
		}
		if (list->previous != NULL)
			supprime_piece(grille, list->previous);
		if (list->previous != NULL && grille->x != grille->lenline)
			return (placepieces(grille, list->previous, grille->x, grille->y));
		while (list->previous != NULL)
			list = list->previous;
		return (placepieces(creationtableau(grille->lenline + 1), list, 0, 0));
	}
	return (grille);
	}
