# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 19:14:05 by ggiboury          #+#    #+#              #
#    Updated: 2023/03/22 14:32:24 by ggiboury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c			\
		ft_free.c			\
		ft_op_stack.c		\
		ft_parse.c			\
		ft_stack_utils.c	\
		ft_split.c			\
		ft_utils.c			\
		ft_write.c			

SRC_BONUS = checker.c		\
			ft_atoi.c		\
			ft_read.c

FLAGS = -Wall -Werror -Wextra


all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -o $(NAME)

re: fclean $(NAME)
#PAS FINIS

clean:

fclean: clean
	@/bin/rm -f $(NAME)

test : fclean $(NAME)
#	./push_swap "-5 0 6 91 217"
	./push_swap "-2147483648 1 0 -1 2147483647"
	./push_swap
#	./push_swap -2147483648 1 0 2147483647
#	./push_swap "4 2 1 3"