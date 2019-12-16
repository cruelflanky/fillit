/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:48:59 by gaudry            #+#    #+#             */
/*   Updated: 2019/12/16 19:24:10 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_glist	*ft_create_elem(void *data)
{
	t_glist *element;

	if (!(element = malloc(sizeof(t_glist))))
		return (NULL);
	if (!data)
		element->content = NULL;
	else
		element->content = data;
	element->next = NULL;
	return (element);
}

int		ft_list_push_left(t_glist **begin_list, void *data)
{
	t_glist	*tmp;

	if (begin_list && *begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(data);
		return (0);
	}
	else
		*begin_list = ft_create_elem(data);
	return (1);
}

void	ft_finish(t_glist **begin)
{
	int		coor[6];
	int		a;
	t_glist *list;

	list = *begin;
	a = 0;
	while (a < 6)
		coor[a++] = 0;
	if (ft_check(*begin))
	{
		ft_upgrade(list, coor);
		ft_solver(*begin);
		ft_delete_figure(begin);
	}
	else
		ft_error(begin);
}

void	ft_extramain(t_glist *fig, t_glist *begin, int fd, int x)
{
	char	*str[2];
	char	*tmp;

	str[0] = ft_strnew(1);
	tmp = NULL;
	while (get_next_line(fd, &tmp))
	{
		(!tmp && !x) ? ft_error(&begin) : 0;
		str[1] = str[0];
		if (!*tmp)
		{
			(!ft_list_push_left(&fig, str[0]) ? fig = fig->next : 0);
			(!begin) ? begin = fig : 0;
			str[0] = tmp;
			continue;
		}
		str[0] = ft_strjoin(str[0], tmp);
		(*str[1] || *str[1] == '\0') ? ft_strdel(&str[1]) : 0;
		ft_strdel(&tmp);
		x++;
	}
	(x < 4) ? ft_error(&begin) : 0;
	ft_list_push_left(&fig, str[0]);
	(!begin) ? begin = fig : 0;
	ft_finish(&begin);
}

int		main(int argc, char **argv)
{
	t_glist	*fig;
	int		fd;
	t_glist	*begin;
	int		x;

	x = 0;
	if (argc == 2)
	{
		fig = NULL;
		begin = NULL;
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
			ft_extramain(fig, begin, fd, x);
		else
			ft_error(&begin);
	}
	return (0);
}
