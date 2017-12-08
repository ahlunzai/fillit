/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 23:53:11 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/07 13:04:30 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H
# include <stdio.h>

typedef struct			tetris_list
{
	int tab[4][2];

	int i;
	int shiftx;
	int shifty;
	struct tetris_list	*next;
	struct tetris_list	*previous;
}						pieces_list;

typedef struct			grille_list
{
	char **map;
	int x;
	int y;
	int lenline;
	int i;
}						g_list;

int						nbrederet(char *str);
void					sorttab(g_list *grille);
g_list					*creationtableau(int size);
g_list					*placepieces(g_list *grille, pieces_list *list, int x, int y);
void					affichagelist(pieces_list **list);
pieces_list				*ft_construction(char **tab);
char					**tableaupieces(char *str);
#endif
