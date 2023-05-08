/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:41:45 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/08 20:23:45 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}	t_stack;

//int		arrstr_len(char **tab);
//char	**free_tab_str(char **tab, size_t size);
//int		get_len_arr(char *s);
//int		get_pivot(t_stack *arr);
//int		single_input_is_invalid(char *argv);
//int		in_stack(int *arr, int size, int nb);
//t_stack	*parse(char *argv);

/************************************PRINT*************************************/
void	print_stack(t_stack *stk, char format);
int		print_error(char *nb, char *str);

void	stderr_print(char *s);

/************************************UTILS*************************************/
void	push(t_stack *stk_a, t_stack *stk_b);
void	reverse_rotate(t_stack *stk);
void	rotate(t_stack *stk);
void	swap(t_stack *stk);

void	insert_first(t_stack *stk, t_stack *el);
t_stack	*pop_first(t_stack *stk);
t_stack	*pop_last(t_stack *stk);

int		is_sorted(t_stack *stk);

int		get_stack_size(t_stack *stk);
t_stack	*get_last(t_stack *stk);

void	free_stack(t_stack *arr);

/************************************PARSE*************************************/
void	parse_str(char *arg, t_stack **stk);
void	parse_strs(int size, char **argv, t_stack **stk);
t_stack	*ft_parse(int size, char **input);

void	check_input(char **argv);
int		is_not_number(char *nb);
int		is_not_int(char *nb);

#endif