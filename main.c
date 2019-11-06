/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:48:59 by gaudry            #+#    #+#             */
/*   Updated: 2019/11/04 18:01:49 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "fillit.h"

t_glist	*ft_create_elem(void *data)
{
	t_glist *element;

	if (!(element = malloc(sizeof(t_glist))))
		return (NULL);
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

int		min_square(t_glist *begin)
{
	int		i;
	int		sqrt;

	i = 1;
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

char **create_map(int i)
{
	char **map;
	char **str;
	int x;

	x = 0;
	map = (char **)malloc(sizeof(char *) * i);
	str = map;
	while (x < i)
	{
		*map = (char *)malloc(sizeof(char) * i);
		ft_bzero(*map, i);
		x++;
		map++;
	}
	return (str);
}

void	ft_matrix(char **map, int i)
{
	static t_glist	*matrix;
	char			*str;
	int				x;
	int				y;

	y = 0;
	x = 0;
	str = *map;
	while (y < i)
	{
		while(x++ < i)
			str++;
		str = ft_strjoin(str, map[++y]);
		x = 0;
	}
	ft_list_push_left(&matrix, str);
	matrix = matrix->next;
}

void	ft_fill_map(int i, t_glist *begin_list)
{
	int new_x;
	int new_y;
	int j;
	char **map;
	t_glist *list;

	list = begin_list;
	map = create_map(i);
	new_x = 0;
	new_y = 0;
	j = 0;
	while (new_y < i)
	{
		while (new_x < i)
		{
			while (j < 4)
			{
				if(new_y + list->y[j] > i || new_x + list->x[j] > i)
				{
					j = 0;
					break;
				}
				map[new_y + list->y[j]][new_x + list->x[j]] = '1';
			}
			j == 3 ? ft_matrix(map, i) : 0;
			ft_strdel(map);
			j = 0;
			map = create_map(i);
			new_x++;
		}
		new_x = 0;
		new_y++;
	}
}

void	ft_list_push_back(t_new **begin_list, t_new **last, t_new **prelast)
{
	*last = malloc(sizeof(t_new));
	if(!(*begin_list) && !begin_list)
	{
		*begin_list = malloc(sizeof(t_new));
		*prelast = *begin_list;
		(*begin_list)->next = *last;
		(*last)->prev = *begin_list;
	}
	else
	{
		(*prelast)->next = *last;
		(*last)->prev = *prelast;
	}
	(*last)->next = *begin_list;
	(*begin_list)->prev = *last;
}

//   prelast
//   head-><-last-><-head;
void	ft_fill_list(int i, t_glist *begin_list)
{
	t_new *head;
	t_new *prelast;
	t_new *last;
	char letter;
	int x;
	int y;

	y = i * i;
	x = 0;
	letter = 'A';
	while (y--)
	{
		ft_list_push_back(head, prelast, last);
		last->symbol = letter++;
		last->id = x++;
		prelast = last;
		free(last);
	}
	while (begin_list != NULL)
	{
		ft_fill_map(i, begin_list);
		begin_list = begin_list->next;
	}
}

void	ft_finish_figure(t_glist **begin_list, int x, int y)
{
	t_glist	*list;
	int		new_x;
	int		new_y;
	int		i;
	int		j;

	j = 0;
	i = 0;
	new_x = 0;
	new_y = 0;
	list = *begin_list;
	while ((list->content)[j])
	{
		if ((list->content)[j] == '#')
		{
			list->x[i] = new_x - x;
			list->y[i] = new_y - y;
			i++;
		}
		new_x++;
		j++;
		if (j % 4 == 0)
		{
			new_x = 0;
			new_y++;
		}
	}
}

void	ft_upgrade(t_glist **begin_list)
{
	t_glist	*list;
	int		x;
	int		y;
	int		i;
	int		j;

	x = 0;
	i = 0;
	j = 0;
	list = *begin_list;
	while (list != NULL)
	{
		//find first # and get his index
		while ((list->content)[x])
			if ((list->content)[x++] == '#')
				break;
		y = x % 4;
		if (y == 0)
			y = (x / 4) - 1;
		else
			y = (x / 4);
		x = 0;
		//find the last corner of tetrimo
		while ((list->content)[j])
		{
			j = x + 4 * i;
			if ((list->content)[j] == '#')
				break;
			if (i++ == 3)
			{
				x++;
				i = 0;
			}
		}
		ft_finish_figure(&list, x, y);
		i = 0;
		x = 0;
		list = list->next;
	}

}
//  0	1	2	3
//  4	5	6	#
//  8	#	#	#
//  12	13	14	15

int		main(void)
{
	t_glist *figures;
	int a;
	int fd;
	char *str;
	char **map;
	char *tmp;
	int i = 0;
	t_glist *begin;

	str = ft_strnew(1);
	figures = NULL;
	fd = open ("samples/sujet_2", O_RDONLY);
	while ((a = get_next_line (fd, &tmp)))
	{
		if (!*tmp)
		{
			(!ft_list_push_left(&figures, str) ? figures = figures->next : 0);
			(!begin) ? begin = figures : 0;
			str = tmp;
			continue;
		}
		str = ft_strjoin(str, tmp);
	}
	ft_list_push_left(&figures, str);
	ft_upgrade(&begin);
	ft_fill_map(min_square(begin), begin);
	while (begin != NULL)
	{
		printf ("%s\n", begin->content);
		printf ("x = ");
		while (i != 4)
			printf("%d", (begin->x)[i++]);
		i = 0;
		printf ("\ny = ");
		while (i != 4)
			printf("%d", (begin->y)[i++]);
		printf("\n");
		i = 0;
		begin = begin->next;
	}
	return (0);
}
