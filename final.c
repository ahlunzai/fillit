/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:32:52 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/11 06:26:21 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

t_grillelist				*creationtableau(int size)
{
	t_grillelist		*grille;
	int					i;
	int					j;

	if (!(grille = (t_grillelist *)malloc(sizeof(t_grillelist))))
		return (NULL);
	grille->x = 0;
	grille->y = 0;
	grille->lenline = size;
	grille->i = -1;
	if (!(grille->map = (char **)malloc(sizeof(char *) * grille->lenline)))
		return (NULL);
	i = -1;
	while (++i < grille->lenline)
	{
		if (!(grille->map[i] = (char *)malloc(sizeof(char) * grille->lenline)))
			return (NULL);
		j = -1;
		while (++j < grille->lenline)
			grille->map[i][j] = '.';
	}
	return (grille);
}

int							libre(t_grillelist *grille
		, t_tetrislist *tetris, int x, int y)
{
	int		k;

	grille->x = x;
	grille->y = y;
	while (grille->x < grille->lenline)
	{
		while (grille->y < grille->lenline)
		{
			k = 0;
			while (k < 4 && grille->x + tetris->tab[k][0] != grille->lenline &&
					grille->y + tetris->tab[k][1] != grille->lenline &&
					grille->x + tetris->tab[k][0] > -1
					&& grille->y + tetris->tab[k][1] > -1 &&
					grille->map[(grille->x + tetris->tab[k][0])]
					[(grille->y + tetris->tab[k][1])] == '.')
				k++;
			if (k == 4)
				return (1);
			(grille->y)++;
		}
		(grille->x)++;
		grille->y = 0;
	}
	return (0);
}

void						place_piece(t_grillelist *grille,
		t_tetrislist *tetris, int i)
{
	int			k;

	k = -1;
	tetris->shiftx = grille->x;
	tetris->shifty = grille->y;
	while (++k < 4)
		grille->map[grille->x + tetris->tab[k][0]]
			[grille->y + tetris->tab[k][1]] = 'A' + i;
	(grille->y)++;
	if (grille->y == grille->lenline)
	{
		grille->x = grille->x + 1;
		grille->y = 0;
	}
}

void						supprime_piece(t_grillelist *grille,
		t_tetrislist *tetris)
{
	int			k;

	grille->x = tetris->shiftx;
	grille->y = tetris->shifty;
	k = -1;
	while (++k < 4)
		grille->map[(grille->x + tetris->tab[k][0])]
			[(grille->y + tetris->tab[k][1])] = '.';
	(grille->i)--;
	(grille->y)++;
	if ((grille->y) == grille->lenline)
	{
		(grille->x)++;
		(grille->y) = 0;
	}
}

t_grillelist				*placepieces(t_grillelist *grille,
		t_tetrislist *tetris, int x, int y)
{
	t_tetrislist *pointer;

	if (tetris != NULL)
	{
		if (libre(grille, tetris, x, y) == 1)
		{
			place_piece(grille, tetris, ++(grille->i));
			if (tetris->next == NULL)
				return (grille);
			return (placepieces(grille, tetris->next, 0, 0));
		}
		if (tetris->previous != NULL)
			supprime_piece(grille, tetris->previous);
		if (tetris->previous != NULL && grille->x != grille->lenline)
		{
			return (placepieces(
						grille, tetris->previous, grille->x, grille->y));
		}
		while (tetris->previous != NULL)
			tetris = tetris->previous;
		free(grille->map);
		return (placepieces(creationtableau(grille->lenline + 1),
					tetris, 0, 0));
	}
	while (tetris->previous != NULL)
	{
		pointer = tetris->previous;
		free(tetris);
		tetris = pointer;
	}
	return (grille);
}
