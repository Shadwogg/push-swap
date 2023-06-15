/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:42:56 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/15 16:55:18 by ggiboury         ###   ########.fr       */
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

void	update_indexes(t_stack *stk)
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
		cur->s_ind = nb;
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


void	algo_rec(t_stack **stk_a, t_stack **stk_b, t_inst *inst)
{
	unsigned int	median[2];
	unsigned int	ct[2];

	median[0] = get_pivot(*stk_a);
	median[1] = get_pivot(*stk_b);
	ct[0] = get_stack_size(*stk_a) + 1;
	ct[1] = get_stack_size(*stk_b) + 1;
	while (--ct[0] > 0)
	{
		if ((*stk_a)->s_ind < median[0])
		{
			push_b(stk_a, stk_b, inst, 1);
			rotate_b(stk_b, inst, 1);
		}
		else
			rotate_a(stk_a, inst, 1);
	}
	while (--ct[1] > 0)
	{
		if ((*stk_b)->s_ind > median[1])
		{
			push_a(stk_a, stk_b, inst, 1);
			rotate_a(stk_a, inst, 1);
		}
		else
			rotate_b(stk_b, inst, 1);
	}
	update_indexes(*stk_a);
	update_indexes(*stk_b);
}

void	algo2_rec(t_stack **stk_a, t_stack **stk_b, t_inst *inst)
{
	t_stack			*cur;
	unsigned int	median;
	unsigned int	ct;

	while (!is_sorted(*stk_a, 1))
	{
		cur = *stk_a;
		ct = 0;
		median = get_pivot(*stk_a);
		//print_stack(*stk_a, "-> ");
		while (ct < median * 2)
		{
			if ((*stk_a)->s_ind < median)
				push_b(stk_a, stk_b, inst, 1);
			else
				rotate_a(stk_a, inst, 1);
			ct++;
		}
		update_indexes(*stk_a);
		update_indexes(*stk_b);
	}
	/*t_stack	*next;
	while (stk_b != NULL)
	{
		next = get_neighbour(,stk_b);
	}*/
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

void	push_next_a(t_stack **s_a, t_stack **s_b, t_inst *inst, int ignored)
{
	unsigned int	pos_max_min;
	unsigned int	size;

	size = get_stack_size(*s_a);
	//printf("A\n	ignored = %d\n", ignored);
	pos_max_min = get_distance(*s_a, get_prev_el(*s_a, get_el(*s_a, ignored))->nb);
	//printf("	pos = %d\n", pos_max_min);
	if (pos_max_min <= size / 2 + size % 2)
		rotate_a(s_a, inst, pos_max_min);
	else
		reverse_rotate_a(s_a, inst, size - pos_max_min);
	push_b(s_a, s_b, inst, 1);
}

void	push_next_b(t_stack **s_a, t_stack **s_b, t_inst *inst)
{
	unsigned int	pos_val_max;
	unsigned int	size;

	size = get_stack_size(*s_b);
	//printf("B\n	val = %d\n", get_el_sorted(*s_b, size - 1)->nb);
	pos_val_max = get_distance(*s_b, get_el_sorted(*s_b, size - 1)->nb);
	//printf("	pos = %d\n", pos_val_max);
	if (pos_val_max <= size / 2 + size % 2)
		rotate_b(s_b, inst, pos_val_max);
	else
		reverse_rotate_b(s_b, inst, size - pos_val_max);
	push_a(s_a, s_b, inst, 1);
}

void	rotating_a(t_stack **a, t_inst *inst)
{
	unsigned int	top;
	unsigned int	dist;

	if (get_stack_size(*a) == 0 || get_stack_size(*a) == 1)
		return ;
	top = get_el_sorted(*a, get_stack_size(*a) - 1)->nb;
	dist = get_distance(*a, top);
	printf("top = %d\ndist = %d\n", top, dist);
	//(void) inst;
	if (dist >= get_stack_size(*a) / 2 + get_stack_size(*a) % 2)
		reverse_rotate_a(a, inst, get_stack_size(*a) - dist);
		//printf("TEST\n");
	else
		rotate_a(a, inst, dist);
}

// Push the max from b to a, and the max from a to b
void	algo_insert(t_stack **s_a, t_stack **s_b, t_inst *inst)
{
	int	ct;
	int	ignored;

	ct = 0;
	ignored = get_el_sorted(*s_a, get_stack_size(*s_a) - 1)->nb;
	while (!is_sorted(*s_a, 0) && !is_sorted(*s_b, 1) && ct < 5)
	{
		push_next_b(s_a, s_b, inst);
		update_indexes(*s_a);
		update_indexes(*s_b);
		push_next_a(s_a, s_b, inst, ignored);
		update_indexes(*s_a);
		update_indexes(*s_b);
		rotating_a(s_a, inst);
		ct++;
	}
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
		if (stk_a->s_ind >= median)
			push_b(&stk_a, &stk_b, inst, 1);
		else
			rotate_a(&stk_a, inst, 1);
		ct++;
	}
	update_indexes(stk_a);
	update_indexes(stk_b);
	//printf("%d, %d\n", get_stack_size(stk_a), get_stack_size(stk_b));
	//algo_rec(&stk_a, &stk_b, inst);
	//algo2_rec(&stk_a, &stk_b, inst);
	algo_insert(&stk_a, &stk_b, inst);
}

void	push_swap(t_stack *stk_a)
{
	t_stack	*stk_b;
	t_inst	*instructions;
	t_inst	*tmp;

	instructions = malloc(sizeof(t_inst));
	if (instructions == NULL)
		print_error("", "MALLOC ERROR");
	instructions->next = NULL;
	instructions->str = "";
	stk_b = NULL;
	update_indexes(stk_a);
	//print_stack(stk_a, "-> ");
	//print_stack(stk_b, "-> ");
	/*pre_optimization(stk_a, stk_b);
	quicksort(stk_a, instructions);
	opti_inst(instructions);*/
	//print_stack(stk_a, "\n");
	mon_algo(stk_a, stk_b, instructions);
	tmp = instructions;
	instructions = instructions->next;
	free(tmp);
	//optimize(instructions);
	//read_inst(instructions);
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
	//system("leaks push_swap");
}
