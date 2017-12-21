/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sauverpieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:02:18 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/15 00:33:15 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

t_tetrislist		*initialisationlist(t_tetrislist *list)
{
	list->previous = NULL;
	list->next = NULL;
	return (list);
}

t_tetrislist		*passagenext(t_tetrislist *list, t_grillelist *var)
{
	t_tetrislist	*tmp;

	tmp = list;
	if (!(list->next = (t_tetrislist *)malloc(sizeof(t_tetrislist))))
		return (NULL);
	list = list->next;
	list->next = NULL;
	list->previous = tmp;
	var->i++;
	return (list);
}

void				savexy(char **tab, t_tetrislist *list, t_grillelist *var)
{
	if (tab[var->i][var->j] && tab[var->i][var->j] == '#')
	{
		if (var->k == 0)
		{
			list->shiftx = var->i;
			list->shifty = var->j;
		}
		list->tab[var->k][0] = var->i - list->shiftx;
		list->tab[var->k][1] = var->j - list->shifty;
		var->k++;
	}
}

t_tetrislist		*ft_construction(char **tab, t_grillelist *var)
{
	t_tetrislist	*list;
	t_tetrislist	*save;

	if(!(list = (t_tetrislist *)malloc(sizeof(t_tetrislist))))
		return (NULL);
	list = initialisationlist(list);
	save = list;
	var->i = 0;
	while (tab[var->i] != 0)
	{
		var->k = 0;
		while ((var->i + 1) % 5 != 0 && tab[var->i] != 0)
		{
			var->j = -1;
			while (++var->j < 4)
				savexy(tab, list, var);
			var->i++;
		}
		if (tab[var->i] != 0 && (var->i + 1) % 5 == 0)
			list = passagenext(list, var);
	}
	return (save);
}
