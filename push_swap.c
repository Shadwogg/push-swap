/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:42:56 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/03 17:52:59 by ggiboury         ###   ########.fr       */
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

void	init_stack(t_stack *stk)
{
	t_stack			*cur;
	t_stack			*save;
	unsigned int	nb;

	cur = stk;
	save = stk;
	while (cur != NULL)
	{
		nb = 0;
		stk = save;
		while (stk != NULL)
		{
			if (cur->nb > stk->nb)
				nb++;
			stk = stk->next;
		}
		cur->sorted_index = nb;
		cur = cur->next;
	}
}

void	read_inst(t_inst *inst)
{
	while (inst != NULL)
	{
		ft_printf("%s\n", inst->str);
		inst = inst->next;
	}
}

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
	//t_inst			*tmp;
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

t_inst	*get_inst(t_inst *inst, unsigned int nb)
{
	while (inst != NULL && --nb > 0)
		inst = inst->next;
	return (inst);
}

void	algo_rec(t_stack *stk_a, t_stack *stk_b, t_inst *inst, int time)
{
	unsigned int	median[2];
	unsigned int	ct[2];

	median[0] = get_pivot(stk_a);
	median[1] = get_pivot(stk_b);
	ct[0] = 0;
	ct[1] = 0;
	while (ct[0] <= median[0] && ct[1] <= median[1])
	{
		if (stk_a->sorted_index > median[0])
		{
			push_b(&stk_a, &stk_b, inst);
			rotate_b(&stk_b, inst);
		}
		else
			rotate_a(&stk_a, inst);
		if (stk_b->sorted_index > median[1])
		{
			push_a(&stk_a, &stk_b, inst);
			rotate_a(&stk_b, inst);
		}
		else
			rotate_b(&stk_a, inst);
		ct[0]++;
		ct[1]++;
	}
	if (time < 1)
		algo_rec(stk_a, stk_b, inst, time + 1);
}

void	mon_algo(t_stack *stk_a, t_stack *stk_b, t_inst *inst)
{
	t_stack			*cur;
	unsigned int	median;
	unsigned int	ct;

	cur = stk_a;
	ct = 0;
	median = get_pivot(stk_a);
	while (ct < median * 2)
	{
		if (stk_a->sorted_index > median)
			push_b(&stk_a, &stk_b, inst);
		else
			rotate_a(&stk_a, inst);
		ct++;
	}
	algo_rec(stk_a, stk_b, inst, 1);
}

void	push_swap(t_stack *stk_a)
{
	t_stack	*stk_b;
	t_inst	*instructions;

	instructions = malloc(sizeof(t_inst));
	if (instructions == NULL)
		print_error("", "MALLOC ERROR");
	instructions->next = NULL;
	instructions->str = "";
	stk_b = NULL;
	init_stack(stk_a);
	//print_stack(stk_a, "-> ");
	//print_stack(stk_b, "-> ");
	/*pre_optimization(stk_a, stk_b);
	quicksort(stk_a, instructions);
	opti_inst(instructions);*/
	//print_stack(stk_a, "\n");
	mon_algo(stk_a, stk_b, instructions);
	read_inst(instructions);
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
	if (is_sorted(stk))
		return (0);
	push_swap(stk);
	//system("leaks push_swap");
}
