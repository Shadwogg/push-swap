/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:42:56 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/22 18:55:47 by ggiboury         ###   ########.fr       */
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

unsigned int	get_distance(t_stack *s, int nb)
{
	int	ct;

	ct = 0;
	while (s != NULL && (s->nb != nb))
	{
		s = s->next;
		ct++;
	}
	return (ct);
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

unsigned int	get_start(t_stack *s)
{
	unsigned int	size;
	unsigned int	res;

	size = get_stack_size(s);
	res = 0;
	while (size > 0)
	{
		res++;
		size = size >> 1;
	}
	//printf("res %d\n", res);
	return (res);
}

void	push_swap(t_stack *stk_a)
{
	t_state	*init;
	t_state	*soluce;
	t_inst	*inst;

	inst = NULL;
	update_indexes(stk_a);
	//print_stack(stk_a, "-> ");
	//print_stack(stk_b, "-> ");
	init = malloc(sizeof(t_state) * 1);
	if (init == NULL)
		print_error("", "MALLOC ERROR");
	init->cost = -1;
	init->inst = inst;
	init->s_a = stk_a;
	init->s_b = NULL;
	soluce = mon_algo(init);
	if (soluce == NULL)
		print_error("", "No solution founded");
	// optimize(soluce->inst);
	// read_inst(*(soluce->inst));
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
