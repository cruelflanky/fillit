/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:50:01 by gaudry            #+#    #+#             */
/*   Updated: 2019/12/16 19:25:24 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_glist
{
	char			*content;
	int				y[4];
	int				x[4];
	char			letter;
	struct s_glist	*next;
}					t_glist;

t_glist				*ft_create_elem(void *data);
int					ft_list_push_left(t_glist **begin_list, void *data);
int					min_square(t_glist *begin);
void				ft_extramain(t_glist *fig, t_glist *begin, int fd, int x);
char				**create_map(char **map, int i);
void				ft_delete_figure(t_glist **begin);
void				ft_finish_figure(t_glist **begin_list, int *coor, int j);
void				ft_upgrade(t_glist *list, int *coor);
void				ft_miniupgrade(t_glist **list, int *coor);
int					ft_check(t_glist *begin_list);
void				ft_putstr_everyway(char **str, int i);
int					ft_search(char **map, t_glist *list, int *coor, int i);
int					ft_place_tetra(char **map, t_glist *list, int *coor);
void				ft_place_dots(char **map, t_glist *list, int *coor);
int					ft_solution(t_glist *begin_list, int i, char **map);
int					ft_solver(t_glist *begin_list);
void				ft_delmap(char **map, int i);
void				ft_error(t_glist **begin);

#endif
