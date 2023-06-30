/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:42:56 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/30 18:13:16 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
3 numbers -> 2 or 3 moves
5 numbers ->   <12 moves
100 numbers:
    <700 moves = 5 pts
    <900 moves = 4 pts
    <1,100 moves = 3 pts
    <1,300 moves = 2 pts
    <1,500 moves = 1 pts
500 numbers:
    <5,500 moves = 5 pts
    <7,000 moves = 4 pts
    <8,500 moves = 3 pts
    <10,000 moves = 2 pts
    <11,500 moves = 1 pts
  * 
  *  
*/

void	sort_three(t_stack **a, t_inst **inst)
{
	if (is_sorted(*a, 0))
		return ;
	if ((*a)->s_ind == 0)
	{
		rotate_a(a, inst, 1);
		swap_a(a, inst, 1);
		reverse_rotate_a(a, inst, 1);
	}
	else if (((*a)->s_ind == 2 && (*a)->next->s_ind == 1))
	{
		rotate_a(a, inst, 1);
		swap_a(a, inst, 1);
	}
	else if ((*a)->s_ind == 2)
		rotate_a(a, inst, 1);
	else if ((*a)->s_ind == 1 && (*a)->next->s_ind == 2)
		reverse_rotate_a(a, inst, 1);
	else
		swap_a(a, inst, 1);
}

void	sort_five(t_stack **a, t_stack **b, t_inst **inst)
{
	while (!is_sorted(*a, 0) || get_stack_size(*a) < 5)
	{
		if ((*a)->next != NULL
			&& (int)(*a)->next->s_ind - (int)(*a)->s_ind == -1)
			swap_a(a, inst, 1);
		else if (is_sorted(*a, 0) && b != NULL && get_stack_size(*b) == 2)
		{
			push_a(a, b, inst, 2);
			if ((*a)->s_ind == 5)
				swap_a(a, inst, 1);
			rotate_a(a, inst, 2);
		}
		else if (get_stack_size((*a)) == 3)
			sort_three(a, inst);
		else if ((*a)->s_ind == 3 || (*a)->s_ind == 4)
			push_b(a, b, inst, 1);
		else
			rotate_a(a, inst, 1);
	}
}

/**
 * The core of the program, initialize the stack_a then free the stack after
 * it is sorted. Also free the chained list of instructions after printing it.
*/
void	push_swap(t_stack *a)
{
	t_stack	*b;
	t_inst	*inst;

	b = NULL;
	inst = NULL;
	if (get_stack_size(a) == 3)
		sort_three(&a, &inst);
	else if (get_stack_size(a) == 5)
		sort_five(&a, &b, &inst);
	else
		radix_sort(&a, &b, &inst, 0);
	optimize(inst);
	read_inst(inst);
	free_inst(inst);
}

int	main(int argc, char **argv)
{
	t_stack	*stk;

	stk = NULL;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	else
		parse_strs(argc - 1, argv + 1, &stk);
	if (is_sorted(stk, 0))
	{
		free_stack(stk);
		return (0);
	}
	update_indexes(stk);
	push_swap(stk);
	free(stk);
	return (0);
}
