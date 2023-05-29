# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 19:14:05 by ggiboury          #+#    #+#              #
#    Updated: 2023/05/29 17:54:29 by ggiboury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c			\
		ft_free.c			\
		ft_instructions.c	\
		ft_optimizations.c	\
		ft_parse.c			\
		ft_parse_utils.c	\
		ft_quicksort.c		\
		ft_stack_op.c		\
		ft_stack_utils.c	\
		ft_stack_utils2.c	\
		ft_traductions.c	\
		ft_utils.c			\
		ft_write.c			

SRC_BONUS = checker.c		\
			ft_atoi.c		\
			ft_read.c

FLAGS = -Wall -Werror -Wextra
LIB = -L. -lft

LIBFT_DIR = libft
LIBFT_FILE = ./libft.a

NC=\033[0m
GREEN=\033[0;32m
RED=\033[0;31m

BOLD=\033[1m


all : $(NAME)

lib :
	@if [ ! -f $(LIBFT_FILE) ]; then \
		echo "Loading libft";\
		make -C $(LIBFT_DIR);\
		mv $(LIBFT_DIR)/libft.a $(LIBFT_FILE);\
		echo "$(GREEN)All libs loaded.$(NC)";\
	else \
		echo "$(GREEN)Lib $(BOLD)libft$(GREEN) already there.$(NC)";\
	fi

$(NAME) : lib
	@gcc $(FLAGS) $(SRC) -o $(NAME) $(LIB)
	@echo "$(GREEN)push_swap ready to be executed.$(NC)"

re : fclean $(NAME)

clean :
	@make -C $(LIBFT_DIR) clean
	@echo "$(GREEN)All unnecessary files removed.$(NC)"

fclean : clean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(LIBFT_FILE)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)All compiled files removed.$(NC)"

test : re
#	./push_swap "-2147483648 1 0 -1 2147483647"
#	./push_swap 1 2 3 4 0 
#	./push_swap -2147483648 1 0 2147483647
#	./push_swap -2147483648 1 -4 8 -70 70 42 0 2147483647
	./push_swap 0 1 2 6 5 3 4
