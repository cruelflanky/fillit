/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:01:14 by gaudry            #+#    #+#             */
/*   Updated: 2019/12/09 20:48:50 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_delete_figure(t_glist **begin)
{
	t_glist *list;

	while (*begin)
	{
		list = *begin;
		*begin = (*begin)->next;
		free(list->content);
		free(list);
	}
}

void	ft_finish_figure(t_glist **begin_list, int *coor, int j)
{
	t_glist	*list;
	int		i;

	i = 0;
	list = *begin_list;
	while ((list->content)[j])
	{
		if ((list->content)[j] == '#')
		{
			list->x[i] = coor[3] - coor[1];
			list->y[i] = coor[2] - coor[0];
			i++;
		}
		coor[3]++;
		j++;
		if (j % 4 == 0)
		{
			coor[3] = 0;
			coor[2]++;
		}
	}
	i = 0;
	while (i < 6)
		coor[i++] = 0;
}

void	ft_miniupgrade(t_glist **list, int *coor)
{
	while (((*list)->content)[coor[1]])
		if (((*list)->content)[coor[1]++] == '#')
			break ;
	coor[0] = coor[1] % 4;
	if (coor[0] == 0)
		coor[0] = (coor[1] / 4) - 1;
	else
		coor[0] = (coor[1] / 4);
	coor[1] = 0;
}

void	ft_upgrade(t_glist *list, int *coor)
{
	while (list != NULL)
	{
		ft_miniupgrade(&list, coor);
		while ((list->content)[coor[4]])
		{
			coor[4] = coor[1] + 4 * coor[5];
			if ((list->content)[coor[4]] == '#')
				break ;
			if (coor[5]++ == 3)
			{
				coor[1]++;
				coor[5] = 0;
			}
		}
		ft_finish_figure(&list, coor, 0);
		coor[5] = 0;
		coor[1] = 0;
		list = list->next;
	}
}
