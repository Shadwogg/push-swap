/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:29:02 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/27 22:30:23 by ggiboury         ###   ########.fr       */
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
		print_error("Unreachable bit", "");
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
		print_error("Unreachable bit", "");
	/*printf("nb = %d\n%d\n", nb, (nb >> bit) & 1);
	if (((nb >> bit) & 1) == val)
		printf("	1st sorted\n");
	else
		printf("	1st not sorted\n");*/
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

void	radix_sort(t_stack **s_a, t_stack **s_b, t_inst **inst, unsigned int ct)
{
	//printf("Ct = %d\n", ct);
	unsigned int	i;

	i = 0;
	while (i < get_stack_size(*s_a) + get_stack_size(*s_b))
	{
		//print_stack(*s_a, "- ");
		if (is_swappable(*s_a, 0))
			swap_a(s_a, inst, 0);
		if (!first_is_sorted((*s_a)->s_ind, ct, 1))
			push_b(s_a, s_b, inst, 1);
		else
			rotate_a(s_a, inst, 1);
		i++;
	}
	// while (!is_bit_sorted(*s_b, ct + 1, 1))
	// {
	// 	if (is_swappable(*s_b, 1))
	// 		swap_b(s_b, inst, 1);
	// 	if (!first_is_sorted((*s_b)->s_ind, ct + 1, 1))
	// 		push_a(s_a, s_b, inst, 1);
	// 	else
	// 		rotate_b(s_b, inst, 1);
	// }
	// printf("PuSH\n");
	push_a(s_a, s_b, inst, get_stack_size(*s_b));
	if (!is_sorted(*s_a, 0) && ct < 10)
		radix_sort(s_a, s_b, inst, ct + 1);
}
