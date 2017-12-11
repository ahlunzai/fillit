/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 01:43:34 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/11 09:31:46 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"
#include "header.h"

int		diesepoint(char *str, int i, int k)
{
	while (str[i] && i < 20)
	{
		while (str[i] && (i + 1) % 5 != 0)
		{
			if (str[i] == '#' && ((str[i + 1] && str[i + 1] == '#') || (str[i +
5] && str[i + 5] == '#')))
				k++;
			if (str[i] == '.' || str[i] == '#')
				i++;
			else
				return (1);
		}
		if (str[i] != '\n')
			return (1);
		i++;
	}
	return ((k == 3 || k == 4) ? 0 : 1);
}

int		verification(char *str)
{
	while (*str)
	{
		if (diesepoint(str, 0, 0) == 0)
		{
			str = str + 19;
			if (str[0] == '\n' && str[1] == '\0')
				return (0);
			if (str[0] == '\n' && str[1] == '\n')
			{
				if (str[2] == '#' || str[2] == '.')
					str = str + 2;
				else
					return (1);
			}
			else
				return (1);
		}
		else
			return (1);
	}
	return (0);
}
