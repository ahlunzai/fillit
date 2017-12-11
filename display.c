/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 01:46:14 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/09 02:10:02 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

void			sorttab(t_grillelist *grille)
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

int				taillemini(char *buf)
{
	int i;
	int j;

	j = 1;
	i = ((nbrederet(buf) + 1) / 5) * 4;
	while (j * j < i)
		j++;
	return (j);
}
