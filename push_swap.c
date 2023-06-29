/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:42:56 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/29 11:28:56 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
  *
  *
  *
  * 
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

unsigned int	count_same_inst(t_inst *inst)
{
	unsigned int	ct;

	ct = 0;
	while (inst != NULL && inst->next != NULL && inst->str == inst->next->str)
		inst = inst->next;
	return (ct);
}

void	opti_inst(t_inst *instructions)
{
	t_inst			*inst;
	unsigned int	ct;

	inst = instructions;
	while (inst != NULL)
	{
		ct = count_same_inst(inst);
		//if (inst->str == "ra" || inst->str == "rra")
		inst = inst->next;
	}
}

void	push_all(t_stack *s_a, t_stack *s_b, t_inst **inst)
{
	while (get_stack_size(s_a) > 2)
	{
		if (s_a->s_ind > 0 && s_a->s_ind < get_stack_size(s_a) - 1)
			push_b(&s_a, &s_b, inst, 1);
		else
			rotate_a(&s_a, inst, 1);
	}
}

unsigned int	get_start(size_t size)
{
	unsigned int	res;

	res = 0;
	while (size > 0)
	{
		res++;
		size = size >> 1;
	}
	return (res);
}

/**
 * The core of the program, initialize the stack_a then free the stack after
 * it is sorted. Also free the chained list of instructions after printing it.
*/
void	push_swap(t_stack *stk_a)
{
	t_stack	*stk_b;
	t_inst	*instructions;

	instructions = NULL;
	stk_b = NULL;
	update_indexes(stk_a);
	radix_sort(&stk_a, &stk_b, &instructions, 0);
	free_stack(stk_a);
	// optimize(instructions);
	read_inst(instructions);
	free_inst(instructions);
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
		return (0);
	push_swap(stk);
	//system("leaks push_swap");
}
