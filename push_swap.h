/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:41:45 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/06 20:24:12 by ggiboury         ###   ########.fr       */
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
//void	inputs_is_invalid(char **argv);
//int		in_stack(int *arr, int size, int nb);
//int		is_not_int(char *nb);
//t_stack	*parse(char *argv);



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

void	print_stack(t_stack *tab, char format);
int		print_error(char *str);

void	free_stack(t_stack *arr);

/************************************PARSE*************************************/
void	parse_str(char *arg, t_stack *arr);
void	parse_strs(int size, char **argv, t_stack *arr);


#endif