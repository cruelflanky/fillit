/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:47:05 by gaudry            #+#    #+#             */
/*   Updated: 2019/12/09 19:14:09 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_square(t_glist *begin)
{
	int		i;
	int		sqrt;

	i = 0;
	sqrt = 1;
	while (begin != NULL)
	{
		i++;
		begin = begin->next;
	}
	i *= 4;
	while (sqrt * sqrt < i)
		++sqrt;
	i = sqrt * sqrt;
	return (sqrt);
}

void	ft_delmap(char **map, int i)
{
	int x;

	x = 0;
	while (x < i)
		free(map[x++]);
	free(map);
	map = NULL;
}

char	**create_map(char **map, int i)
{
	char	**str;
	int		x;

	x = 0;
	map = (char **)malloc(sizeof(char *) * i);
	str = map;
	while (x < i)
	{
		map[x] = ft_strnew(i);
		ft_memset(map[x], '.', i);
		x++;
	}
	return (str);
}

void	ft_putstr_everyway(char **str, int i)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < i)
	{
		while (x < i)
		{
			write(1, &str[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
}
