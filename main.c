/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 01:41:55 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/15 00:33:12 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"
#include "header.h"

int		main(int ac, char **av)
{
	int				fd;
	char			buf[2048];
	int				size;
	t_tetrislist	*list;
	t_grillelist	*var;

	if (!(var = (t_grillelist *)malloc(sizeof(t_grillelist))))
		return (-1);
	list = (t_tetrislist *)malloc(sizeof(t_tetrislist));
	if (ac != 2)
		return (write(1, "usage: fillit source_file", 26));
	fd = open(av[1], 2);
	if (fd == -1)
		ft_puterror();
	size = read(fd, buf, 2047);
	buf[size] = 0;
	if (*buf == 0 || verification(buf) == 1)
		ft_puterror();
	sorttab(placepieces(creationtableau(taillemini(buf)),
				ft_construction(tableaupieces(buf), var), 0, 0));
	close(fd);
	return (0);
}
