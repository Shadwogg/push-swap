# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 19:14:05 by ggiboury          #+#    #+#              #
#    Updated: 2023/07/03 17:15:49 by ggiboury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

FLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRCS = ft_free.c			\
		ft_instructions.c	\
		ft_optimizations.c	\
		ft_parse.c			\
		ft_stack_op.c		\
		ft_stack_utils.c	\
		ft_stack_utils2.c	\
		ft_traductions.c	\
		ft_traductions2.c	\
		ft_write.c			\
		sort.c				\
		radixsort.c			

S_MAIN = push_swap.c

SRC_BONUS = checker.c		\
			ft_atoi.c		\
			ft_read.c

OBJS_COMMON = $(SRCS:.c=.o)

OBJ_MAIN = $(S_MAIN:.c=.o)



LIBFT_DIR = libft
LIBFT = ./libft.a

LIB = $(LIBFT)


NC=\033[0m
GREEN=\033[0;32m
RED=\033[0;31m

BOLD=\033[1m


all : $(NAME)

$(LIBFT) :
	@echo "Loading $(BOLD)libft$(NC)"
	@make -C $(LIBFT_DIR)
	@mv $(LIBFT_DIR)/libft.a $(LIBFT)
	@if [ ! -f $(LIBFT) ]; then \
		echo "$(RED)Echec while loading libft.$(NC)";\
	else \
		echo "$(GREEN)$(LIBFT) loaded.$(NC)";\
	fi

lib : $(LIBFT)
	@echo "$(GREEN)All libs present.$(NC)";\

$(OBJS_COMMON) : $(SRCS)
	@gcc $(FLAGS) $? -c

$(OBJ_MAIN) : $(S_MAIN)
	@gcc $(FLAGS) $? -c

$(NAME) : $(OBJS_COMMON) $(OBJ_MAIN) lib
	@gcc $(FLAGS) $(OBJS_COMMON) $(OBJ_MAIN) -o $(NAME) $(LIB)
	@echo "$(GREEN)push_swap ready to be executed.$(NC)"

re : fclean $(NAME)

clean :
	@make -C $(LIBFT_DIR) clean
	@/bin/rm -rf $(OBJS_COMMON)
	@/bin/rm -rf $(OBJ_MAIN)
	@echo ".o files removed."

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LIBFT)
	@echo "$(GREEN)All compiled files removed.$(NC)"

debug : $(OBJS_COMMON) $(OBJ_MAIN) lib
	@gcc $(FLAGS) -fsanitize=address $(OBJS_COMMON) $(OBJ_MAIN) -o $(NAME) $(LIB)
	
test : re
#	./push_swap "-2147483648 1 0 -1 2147483647"
#	./push_swap 1 2 3 4 0 
#	./push_swap -2147483648 1 0 2147483647
#	./push_swap -2147483648 1 -4 8 -70 70 42 0 2147483647
	./push_swap 0 1 2 6 5 3 4
