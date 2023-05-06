# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 19:14:05 by ggiboury          #+#    #+#              #
#    Updated: 2023/05/06 20:29:43 by ggiboury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c			\
		ft_free.c			\
		ft_stack_op.c		\
		ft_parse.c			\
		ft_stack_utils.c	\
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

test : fclean $(NAME)
#	./push_swap "-5 0 6 91 217"
	./push_swap "-2147483648 1 0 -1 2147483647"
	./push_swap 1 2 3 4 0
#	./push_swap -2147483648 1 0 2147483647
#	./push_swap "4 2 1 3"