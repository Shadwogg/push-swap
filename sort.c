/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:07:21 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/03 16:09:59 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_min(int nb, t_stack *s)
{
	while (s != NULL)
	{
		if (nb > s->nb)
			return (0);
		s = s->next;
	}
	return (1);
}

int	is_max(int nb, t_stack *s)
{
	while (s != NULL)
	{
		if (nb < s->nb)
			return (0);
		s = s->next;
	}
	return (1);
}

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

void	insert_sort(t_stack **a, t_stack **b, t_inst **inst)
{
	if (b == NULL || *b == NULL)
		return ;
	if ((*b)->s_ind > (*b)->next->s_ind)
		swap_b(b, inst, 1);
	if ((*b)->s_ind == 3)
	{
		swap_b(b, inst, 1);
		push_a(a, b, inst, 2);
		rotate_a(a, inst, 2);
		return ;
	}
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
			rotate_a(a, inst, 1);
	}
}

void	sort_five(t_stack **a, t_stack **b, t_inst **inst)
{
	push_b(a, b, inst, 2);
	sort_three(a, inst);
	insert_sort(a, b, inst);
	if ((*a)->s_ind != 0 && (*a)->s_ind < 3)
		reverse_rotate_a(a, inst, (*a)->s_ind);
	else
		rotate_a(a, inst, (5 - (*a)->s_ind));
}
