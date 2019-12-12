/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:45:18 by gaudry            #+#    #+#             */
/*   Updated: 2019/12/09 18:54:12 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_search(char **map, t_glist *list, int *coor, int i)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		if (list->x[j] + coor[0] < i &&
			list->y[j] + coor[1] < i &&
			map[list->y[j] + coor[1]][list->x[j] + coor[0]] == '.')
			j++;
		else
			return (0);
	}
	return (1);
}

int		ft_place_tetra(char **map, t_glist *list, int *coor)
{
	int		j;
	char	letter;

	j = 0;
	letter = list->letter;
	while (j < 4)
	{
		map[coor[1] + list->y[j]][coor[0] + list->x[j]] = letter;
		j++;
	}
	return (1);
}

void	ft_place_dots(char **map, t_glist *list, int *coor)
{
	int		j;
	char	letter;

	j = 0;
	letter = list->letter;
	while (j < 4)
	{
		map[coor[1] + list->y[j]][coor[0] + list->x[j]] = '.';
		j++;
	}
}

int		ft_solution(t_glist *begin_list, int i, char **map)
{
	int		coor[2];
	t_glist	*list;

	list = begin_list;
	coor[1] = 0;
	while (coor[1] < i && list != NULL)
	{
		coor[0] = 0;
		while (coor[0] < i)
		{
			if (ft_search(map, list, coor, i))
			{
				ft_place_tetra(map, list, coor);
				if (!(ft_solution(list->next, i, map)))
					ft_place_dots(map, list, coor);
				else
					return (1);
			}
			coor[0]++;
		}
		coor[1]++;
	}
	if (list != NULL)
		return (0);
	return (1);
}

int		ft_solver(t_glist *begin_list)
{
	int		i;
	t_glist	*list;
	char	letter;
	char	**map;

	letter = 'A';
	map = NULL;
	list = begin_list;
	while (list)
	{
		list->letter = letter++;
		list = list->next;
	}
	i = min_square(begin_list);
	map = create_map(map, i);
	while (!(ft_solution(begin_list, i, map)))
	{
		(map != NULL) ? ft_delmap(map, i) : 0;
		map = create_map(map, ++i);
	}
	ft_putstr_everyway(map, i);
	(map != NULL) ? ft_delmap(map, i) : 0;
	return (1);
}
