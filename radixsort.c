/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:29:02 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/29 16:41:10 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * The stack is sorted if it has no elements unsorted.
*/
int	is_bit_sorted(t_stack *s, unsigned int bit, unsigned int val)
{
	if (s == NULL)
		return (1);
	if (bit > 15)
		print_error(NULL, "Unreachable bit");
	while (s != NULL)
	{
		if (!(((s->s_ind >> bit) & 1) == val))
			return (0);
		s = s->next;
	}
	return (1);
}

/**
 * The number is sorted if it has the wanted bit is equal to val.
*/
int	first_is_sorted(unsigned int nb, unsigned int bit, unsigned int val)
{
	if (bit > 15)
		print_error(NULL, "Unreachable bit");
	return ((((nb >> bit) & 1) == val));
}

// TEST 1
int	is_swappable(t_stack *s, int order)
{
	if (s == NULL || s->next == NULL)
		return (0);
	if (order == 0)
		if (s->s_ind > s->next->s_ind && s->s_ind - s->next->s_ind == 1)
			return (1);
	if (order == 1)
		if (s->s_ind < s->next->s_ind && s->next->s_ind - s->s_ind == 1)
			return (1);
	return (0);
}

/**
 * Radix sort (binary version)
 * push to stack b every number if the bit at pos ct is not sorted,
 * then push everything into stack a.
 * Repeat until sorted.
*/
void	radix_sort(t_stack **a, t_stack **b, t_inst **inst, unsigned int ct)
{
	unsigned int	i;

	i = 0;
	while (i < get_stack_size(*a) + get_stack_size(*b))
	{
		if (is_sorted(*a, 0) && is_sorted(*b, 1) && ct == 15)
		{
			push_a(a, b, inst, get_stack_size(*b));
			return ;
		}
		if (!first_is_sorted((*a)->s_ind, ct, 1))
			push_b(a, b, inst, 1);
		else
			rotate_a(a, inst, 1);
		i++;
	}
	push_a(a, b, inst, get_stack_size(*b));
	if (!is_sorted(*a, 0) && ct < 16)
		radix_sort(a, b, inst, ct + 1);
}
