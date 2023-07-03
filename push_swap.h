/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:41:45 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/03 21:30:20 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

// A chained list storing the stack.
typedef struct s_stack
{
	int				nb;
	unsigned int	s_ind;
	struct s_stack	*next;
}	t_stack;

// A doubled chained list storing the instructions.
typedef struct s_inst
{
	char			*str;
	struct s_inst	*next;
	struct s_inst	*prev;
}	t_inst;

/************************************ALGO**************************************/

void	insert_sort(t_stack **a, t_stack **b, t_inst **inst);
void	sort_three(t_stack **a, t_inst **inst);
void	sort_five(t_stack **a, t_stack **b, t_inst **inst);
int		is_bit_sorted(t_stack *s, unsigned int bit, unsigned int val);
int		first_is_sorted(unsigned int nb, unsigned int bit, unsigned int val);
void	radix_sort(t_stack **a, t_stack **b, t_inst **inst, unsigned int ct);
void	push_swap(t_stack *a);

/********************************INSTRUCTIONS**********************************/

void	optimize(t_inst **inst);
void	read_inst(t_inst *inst);
void	add_inst(t_inst	**inst, char *str, unsigned int time);

/************************************UTILS*************************************/

// STACK OPERATOR
void	push(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b, t_inst **inst, unsigned int time);
void	push_b(t_stack **a, t_stack **b, t_inst **inst, unsigned int time);
void	swap(t_stack **stk);
void	swap_a(t_stack **stk, t_inst **inst, unsigned int time);
void	swap_b(t_stack **stk, t_inst **inst, unsigned int time);
void	rotate(t_stack **stk);
void	rotate_a(t_stack **stk, t_inst **inst, unsigned int time);
void	rotate_b(t_stack **stk, t_inst **inst, unsigned int time);
void	reverse_rotate(t_stack **stk);
void	reverse_rotate_a(t_stack **stk, t_inst **inst, unsigned int time);
void	reverse_rotate_b(t_stack **stk, t_inst **inst, unsigned int time);

int		is_sorted(t_stack *stk, char order);
int		in_stack(int nb, t_stack *stk);

int		is_min(int nb, t_stack *s);
int		is_max(int nb, t_stack *s);

size_t	get_stack_size(t_stack *stk);
t_stack	*get_last(t_stack *stk);
void	update_indexes(t_stack *stk);

void	free_stack(t_stack *stk);
void	free_inst(t_inst *s);

int		print_error(t_inst *inst, t_stack *s);

/************************************PARSE*************************************/
void	parse_strs(int size, char **argv, t_stack **stk);
t_stack	*ft_parse(int size, char **input);

void	check_input(char **argv);
void	check_double(t_stack *stk);
int		is_not_number(char *nb);
int		is_not_int(char *nb);

#endif