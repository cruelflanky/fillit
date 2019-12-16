/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:08:29 by gaudry            #+#    #+#             */
/*   Updated: 2019/12/16 18:51:20 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		connection(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 16)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 16 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 4) < 16 && str[i + 4] == '#')
				block++;
			if ((i - 4) >= 0 && str[i - 4] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

int		checker(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
		i++;
	if (i != 16)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.')
			return (0);
		if (str[i] == '#' && ++count > 4)
			return (0);
		i++;
	}
	if (!connection(str))
		return (0);
	return (1);
}

int		ft_check(t_glist *begin_list)
{
	while (begin_list != NULL)
	{
		if (!(checker(begin_list->content)))
			return (0);
		begin_list = begin_list->next;
	}
	return (1);
}

void	ft_error(t_glist **begin)
{
	ft_putstr("error\n");
	ft_delete_figure(begin);
	exit(EXIT_FAILURE);
}
