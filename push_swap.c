/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:42:56 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/01 17:34:13 by ggiboury         ###   ########.fr       */
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
	unsigned int	size;

	cur = stk;
	save = stk;
	size = get_stack_size(stk);
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
		cur->size = size;
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
		if (cur->sorted_index > median)
			push_b(&stk_a, &stk_b, inst);
		rotate_a(&stk_a, inst);
		ct++;
	}
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
	print_stack(stk_a, "-> ");
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
