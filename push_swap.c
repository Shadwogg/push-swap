/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:42:56 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/25 21:39:05 by ggiboury         ###   ########.fr       */
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

void	push_swap(t_stack *stk_a)
{
	t_state	*init;
	t_state	*soluce;

	update_indexes(stk_a);
	//print_stack(stk_a, "-> ");
	//print_stack(stk_b, "-> ");
	init = malloc(sizeof(t_state));
	if (init == NULL)
		print_error("", "MALLOC ERROR");
	init->cost = (unsigned long) -1;
	init->inst = NULL;
	init->s_a = stk_a;
	init->s_b = NULL;
	init->next = NULL;
	soluce = mon_algo(init, 0);
	if (soluce == NULL)
		print_error("", "No solution founded");
	// optimize(soluce->inst);
	read_inst(soluce->inst);
	// free(init);
	// free_stack(stk_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stk;
	char	val;

	stk = NULL;
	val = 2;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
		parse_str(argv[1], &stk);
	else
		parse_strs(argc - 1, argv + 1, &stk);
	if (is_sorted(stk, 0))
		return (0);
	push_swap(stk);
	//unsigned int test = 1 << 8;
	//printf("val = %u\n", test & 2505);
	//system("leaks push_swap");
}
