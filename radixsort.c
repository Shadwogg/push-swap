/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:29:02 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/03 21:30:03 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// /**
//  * The stack is sorted if it has no elements unsorted.
// */
// int	is_bit_sorted(t_stack *s, unsigned int bit, unsigned int val)
// {
// 	if (s == NULL)
// 		return (1);
// 	if (bit > 15)
// 		return (-1);
// 	while (s != NULL)
// 	{
// 		if (!(((s->s_ind >> bit) & 1) == val))
// 			return (0);
// 		s = s->next;
// 	}
// 	return (1);
// }

/**
 * The number is sorted if the wanted bit is equal to val.
*/
int	first_is_sorted(unsigned int nb, unsigned int bit, unsigned int val)
{
	if (bit > 15)
		return (-1);
	return ((((nb >> bit) & 1) == val));
}

/**
 * Radix sort (binary version)
 * push to stack b the head number if the ct bit is not sorted,
 * rotate if not.
 * Push everything into stack a after the stack is sorted for this bit.
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
		if (first_is_sorted((*a)->s_ind, ct, 1) == -1)
		{
			free_stack(*b);
			print_error(*inst, *a);
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
