/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 23:53:11 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/15 00:33:11 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H
# include <stdio.h>

typedef struct			s_list3
{
	int					tab[4][2];
	int					i;
	int					j;
	int					k;
	int					shiftx;
	int					shifty;
	struct s_list3		*next;
	struct s_list3		*previous;
}						t_tetrislist;

typedef struct			s_list2
{
	char		**map;
	int			x;
	int			y;
	int			lenline;
	int			i;
	int			j;
	int			k;
}						t_grillelist;

int						ft_puterror(void);
void					free_liste(t_tetrislist *list);
int						diesepoint(char *str, int i, int k, int l);
int						verification(char *str);
int						taillemini(char *buf);
int						nbrederet(char *str);
void					sorttab(t_grillelist *grille);
t_grillelist			*creationtableau(int size);
t_grillelist			*placepieces(t_grillelist *grille, t_tetrislist *list,
									int x, int y);
void					affichagelist(t_tetrislist **list);
t_tetrislist			*ft_construction(char **tab, t_grillelist *var);
char					**tableaupieces(char *str);
#endif
