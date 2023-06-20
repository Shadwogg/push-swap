/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:29:02 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/20 15:08:28 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_bit_sorted(t_stack *s, unsigned int bit, unsigned int val)
{
	if (s == NULL)
		return (1);
	if (bit > 15)
		print_error("Unreachable bit", "");
	while (s != NULL)
	{
		if (((s->s_ind >> (15 - bit)) & 1) == val)
			return (0);
		s = s->next;
	}
	return (1);
}

int	first_is_sorted(unsigned int nb, unsigned int bit, unsigned int val)
{
	unsigned int	mask;

	if (bit > 15)
		print_error("Unreachable bit", "");
	mask = 1 << (15 - bit);
	if (val == 1)
		return (nb & mask);
	return (!(nb & mask));
}

// TEST 1
int	is_swappable(t_stack *s, int order)
{
	if (s == NULL || s->next == NULL)
		return (0);
	if (order == 0)
		if (s->s_ind > s->next->s_ind)
			return (1);
	if (order == 1)
		if (s->s_ind < s->next->s_ind)
			return (1);
	return (0);
}

void	radix_sort(t_stack **s_a, t_stack **s_b, t_inst **inst, unsigned int ct)
{
	while (!is_bit_sorted(*s_a, ct, 0))
	{
		if (!first_is_sorted((*s_a)->s_ind, ct, 0))
			push_b(s_a, s_b, inst, 1);
		else
			rotate_a(s_a, inst, 1);
	}
	while (!is_bit_sorted(*s_b, ct, 0))
	{
		if (!first_is_sorted((*s_b)->s_ind, ct, 0))
			push_a(s_a, s_b, inst, 1);
		else
			rotate_b(s_b, inst, 1);
	}
	push_a(s_a, s_b, inst, get_stack_size(*s_b));
	if (!is_sorted(*s_b, 0) && ct < 15)
		radix_sort(s_a, s_b, inst, ct + 1);
}

void	basic_radix_sort(t_stack **s_a, t_stack **s_b, t_inst **inst, unsigned int ct)
{
	printf("is %d\n", first_is_sorted((*s_a)->s_ind, ct, 0));
	printf("is %d\n", is_bit_sorted(*s_a, ct, 1));
	while (!is_bit_sorted(*s_a, ct, 0))
	{
		if (!first_is_sorted((*s_a)->s_ind, ct, 0))
			push_b(s_a, s_b, inst, 1);
		else
			rotate_a(s_a, inst, 1);
		return ;
	}
	/*while (!is_bit_sorted(*s_b, ct, 0))
	{
		if (!first_is_sorted((*s_b)->s_ind, ct, 0))
			push_a(s_a, s_b, inst, 1);
		else
			rotate_b(s_b, inst, 1);
	}*/
	printf("ct %d\n", ct);
	push_a(s_a, s_b, inst, get_stack_size(*s_b));
	return ;
	if (!is_sorted(*s_a, 0) && ct < 15)
		radix_sort(s_a, s_b, inst, ct + 1);
}
