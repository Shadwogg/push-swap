/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:42:56 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/03 21:19:00 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Parse the input.
*/
void	parse_strs(int size, char **argv, t_stack **stk)
{
	check_input(argv);
	*stk = ft_parse(size, argv);
	check_double(*stk);
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
	optimize(&inst);
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
	free_stack(stk);
	return (0);
}
