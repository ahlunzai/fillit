/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 00:24:06 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/03 01:19:17 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"


g_list		*creationtableau(int size)
{
	g_list		*grille;
	int			i;
	int			j;

	if(!(grille = (g_list *)malloc(sizeof(g_list))))
		return (NULL);
	grille->x = 0;
	grille->y = 0;
	grille->lenline = size;
	grille->sizemap = size * size;
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

int			possible_pieces(g_list *grille, pieces_list **list)
{
	int		k;

	while (grille->x < grille->lenline)
	{
		while (grille->y < grille->lenline)
		{
			k = 0;
			while (grille->map[grille->x + (*list)->tab[k][0]]
					[grille->y + (*list)->tab[k][1]] == '.')
				k++;
			if (k == 4)
				return (1);
			else
				(grille->y)++;
		}
		(grille->x)++;
	}
	return (0);
}

g_list		*place_piece(g_list *grille, pieces_list **list, int i)
{
	g_list		*new;
	int			k;

	k = -1;

	if(!(new = (g_list *)malloc(sizeof(g_list))))
		return (NULL);
	new = grille;
	while (++k < 4)
		new->map[new->x + (*list)->tab[k][0]][new->y + (*list)->tab[k][1]]
			= 'A' + i;
	return (new);
}

int		backtracking(g_list *grille, pieces_list **list, int i)
{
	g_list *new;

	if (*list == NULL)
		return (1);
	if (possible_pieces(grille, list) == 1)
	{
		*list = (*list)->next;
		if (possible_pieces(grille, list) == 0)
		{
			*list = (*list)->previous;
			grille->y += 1;
	}

	return (0);
}
