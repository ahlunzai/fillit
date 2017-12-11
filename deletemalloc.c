/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletemalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 08:27:54 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/11 08:35:31 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

void	free_liste(t_tetrislist *list)
{
	t_tetrislist *tmp;

	while (list->previous != NULL)
	{
		tmp = list->previous;
		free(list);
		list = tmp;
	}
}
