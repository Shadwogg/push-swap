/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:42:56 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/29 17:43:20 by ggiboury         ###   ########.fr       */
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

/**
 * The core of the program, initialize the stack_a then free the stack after
 * it is sorted. Also free the chained list of instructions after printing it.
*/
void	push_swap(t_stack *a)
{
	t_stack	*b;
	t_inst	*instructions;

	instructions = NULL;
	b = NULL;
	radix_sort(&a, &b, &instructions, 0);
	free_stack(a);
	optimize(instructions);
	read_inst(instructions);
	free_inst(instructions);
}

void	sort_three(t_stack *a)
{
	t_stack	*b;
	t_inst	*instructions;

	b = NULL;
	instructions = NULL;
	if (a->s_ind == 0)
		ft_printf("ra\nsa\nrra\n");
	else if ((a->s_ind == 2 && a->next->s_ind == 1))
		ft_printf("ra\nsa\n");
	else if (a->s_ind == 2)
		ft_printf("ra\n");
	else
		ft_printf("sa\n");
	free_stack(a);
}

void	sort_five(t_stack *a)
{
	t_stack	*b;
	t_inst	*instructions;

	b = NULL;
	instructions = NULL;
	push_b(&a, &b, &instructions, 2);
	if ()
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
	if (get_stack_size(stk) != 5 && get_stack_size(stk) != 3)
		push_swap(stk);
	else if (get_stack_size(stk) == 3)
	{
		sort_three(stk);
		free(stk);
		return (0);
	}
	sort_five(stk);
	free(stk);
	return (0);
}
