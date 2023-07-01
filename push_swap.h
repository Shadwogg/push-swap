/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:41:45 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/01 15:46:35 by ggiboury         ###   ########.fr       */
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

// A chained list storing the instructions.
typedef struct s_inst
{
	char			*str;
	struct s_inst	*next;
}	t_inst;

typedef struct s_move
{
	char			*str;
	unsigned int	time;
}	t_move;

/************************************ALGO**************************************/

void	radix_sort(t_stack **a, t_stack **b, t_inst **inst, unsigned int ct);
void	push_swap(t_stack *a);

/********************************INSTRUCTIONS**********************************/

void	optimize(t_inst *inst);
void	read_inst(t_inst *inst);
void	add_inst(t_inst	**inst, char *str, unsigned int time);

/************************************PRINT*************************************/
void	print_stack(t_stack *stk, char *str);
int		print_error(char *nb, char *str);

void	stderr_print(char *s);

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

size_t	get_stack_size(t_stack *stk);
t_stack	*get_last(t_stack *stk);
t_stack	*get_el(t_stack *stk, unsigned int numero);
t_stack	*get_el_sorted(t_stack *stk, unsigned int numero);
// t_stack	*get_prev_el(t_stack *s, t_stack *el);
void	update_indexes(t_stack *stk);

void	free_stack(t_stack *stk);
void	free_inst(t_inst *s);
// void	free_tab_str(char **arr, int size);

// void	init_inst(t_inst **inst, char *str);
// t_inst	*cp_inst(t_inst *inst);
// void	init_stack(t_stack *s, int nb, unsigned int s_ind);
// t_stack	*cp_stack(t_stack *s);

/************************************PARSE*************************************/
void	parse_strs(int size, char **argv, t_stack **stk);
t_stack	*ft_parse(int size, char **input);

void	check_input(char **argv);
void	check_double(t_stack *stk);
int		is_not_number(char *nb);
int		is_not_int(char *nb);

// void			pre_optimization(t_stack *s_a, t_stack *s_b);
// void			pre_traduction(t_stack *stk, t_inst *inst,
					// t_stack *el, t_stack *el2);

#endif