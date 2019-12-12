# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 16:16:07 by gmeda             #+#    #+#              #
#    Updated: 2019/12/09 20:47:56 by gaudry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

MAIN = main.c

SRC = solver.c checker.c map.c figures.c

LIB = ./libft/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	@$(MAKE) -C $(LIB)
	gcc $(FLAGS) -o $(NAME) $(MAIN) $(SRC) ./libft/libft.a -I $(LIB)

clean:
	@$(MAKE) -C $(LIB) clean

fclean: clean
	@$(MAKE) -C $(LIB) fclean
	rm -f $(NAME)

re: fclean all