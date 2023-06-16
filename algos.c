/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:52:16 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/16 12:53:14 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_next_a(t_stack **s_a, t_stack **s_b, t_inst *inst, int ignored)
{
	unsigned int	pos_max_min;
	unsigned int	size;

	size = get_stack_size(*s_a);
	//printf("A\n	ignored = %d\n", ignored);
	pos_max_min = get_distance(*s_a, get_prev_el(*s_a, get_el(*s_a, ignored))->nb);
	//printf("	pos = %d\n", pos_max_min);
	if (pos_max_min <= size / 2 + size % 2)
	{
		rotate_a(s_a, inst, pos_max_min);
		push_b(s_a, s_b, inst, 1);
		reverse_rotate_a(s_a, inst, pos_max_min);
	}
	else
	{
		reverse_rotate_a(s_a, inst, size - pos_max_min);
		push_b(s_a, s_b, inst, 1);
		rotate_a(s_a, inst, size - pos_max_min);
	}
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

// Push the max from b to a, and the max from a to b
void	algo_insert(t_stack **s_a, t_stack **s_b, t_inst *inst)
{
	int	ct;
	int	ignored;

	ct = 0;
	ignored = get_el_sorted(*s_a, get_stack_size(*s_a) - 1)->nb;
	while (!is_sorted(*s_a, 0) && !is_sorted(*s_b, 1) && ct < 49)
	{
		push_next_b(s_a, s_b, inst);
		update_indexes(*s_a);
		update_indexes(*s_b);
		push_next_a(s_a, s_b, inst, ignored);
		update_indexes(*s_a);
		update_indexes(*s_b);
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
