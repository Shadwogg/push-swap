/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:07:21 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/04 15:45:13 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_inst **inst)
{
	if (is_sorted(*a, 0))
		return ;
	if (is_min((*a)->nb, *a))
	{
		rotate_a(a, inst, 1);
		swap_a(a, inst, 1);
		reverse_rotate_a(a, inst, 1);
	}
	else if (is_max((*a)->nb, *a)
		&& !is_min((*a)->next->nb, *a) && !is_max((*a)->next->nb, *a))
	{
		rotate_a(a, inst, 1);
		swap_a(a, inst, 1);
	}
	else if (is_max((*a)->nb, *a))
		rotate_a(a, inst, 1);
	else if (!is_max((*a)->nb, *a) && !is_min((*a)->nb, *a)
		&& is_max((*a)->next->nb, *a))
		reverse_rotate_a(a, inst, 1);
	else
		swap_a(a, inst, 1);
}

unsigned int	get_dist_rot(t_stack *a, unsigned int pos_sorted)
{
	unsigned int	d;

	d = 0;
	while (a != NULL && a->s_ind < pos_sorted)
	{
		if (a->next != NULL && a->next->s_ind < a->s_ind
			&& pos_sorted > get_stack_size(a))
			return (d);
		d++;
		a = a->next;
	}
	return (d);
}

unsigned int	get_dist_rev(t_stack *a, unsigned int pos_sorted)
{
	return (get_stack_size(a) - get_dist_rot(a, pos_sorted));
}

void	insert_sort(t_stack **a, t_stack **b, t_inst **inst)
{
	unsigned int	rot;
	unsigned int	rev;

	rot = -1;
	while (*b != NULL)
	{
		if ((*b)->s_ind < (*a)->s_ind)
			push_a(a, b, inst, 1);
		else if ((*a)->s_ind == 3 && (*b)->s_ind == 4)
		{
			rotate_a(a, inst, 1);
			push_a(a, b, inst, 1);
		}
		else
		{
			rot = get_dist_rot(*a, (*b)->s_ind);
			rev = get_dist_rev(*a, (*b)->s_ind);
			if (rot < rev)
				rotate_a(a, inst, rot);
			else
				reverse_rotate_a(a, inst, rev + 1);
		}
	}
}

void	sort_five(t_stack **a, t_stack **b, t_inst **inst)
{
	if (is_permutation(*a))
	{
		rotate_a(a, inst, 5 - (*a)->s_ind);
		return ;
	}
	push_b(a, b, inst, 2);
	sort_three(a, inst);
	if ((*b)->s_ind > (*b)->next->s_ind)
		swap_b(b, inst, 1);
	if ((*b)->s_ind == 3)
	{
		swap_b(b, inst, 1);
		push_a(a, b, inst, 2);
		rotate_a(a, inst, 2);
		return ;
	}
	insert_sort(a, b, inst);
	if ((*a)->s_ind != 0 && (*a)->s_ind < 3)
		reverse_rotate_a(a, inst, (*a)->s_ind);
	else if ((*a)->s_ind != 0)
		rotate_a(a, inst, (5 - (*a)->s_ind));
}
