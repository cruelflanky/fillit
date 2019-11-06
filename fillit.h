/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:50:01 by gaudry            #+#    #+#             */
/*   Updated: 2019/11/04 13:54:20 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef struct		s_glist
{
	char			*content;
	int				x[4];
	int				y[4];
	struct s_glist	*next;
}					t_glist;

typedef struct		s_node
{
	int				id;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_new
{
	char				*symbol;
	int					*id;
	struct s_newglist	*next;
	struct s_newglist	*prev;
	struct s_node		*up;
	struct s_node		*down;
}					t_new;

t_glist	*ft_create_elem(void *data);
int		ft_list_push_left(t_glist **begin_list, void *data);
int		min_square(t_glist *begin);
void	ft_finish_figure(t_glist **begin_list, int x, int y);
void	ft_upgrade(t_glist **begin_list);

#endif
