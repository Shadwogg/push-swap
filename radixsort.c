/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:29:02 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/19 22:42:46 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_bit_sorted(t_stack *s, unsigned int bit, unsigned int val)
{
	unsigned int	mask;

	if (s == NULL)
		return (1);
	if (bit > 15)
		print_error("Unreachable bit", "");
	mask = 1 << (15 - bit);
	while (s != NULL)
	{
		if (val == 1)
			if (!(s->s_ind & mask))
				return (0);
		if (val == 0)
			if (s->s_ind & mask)
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

/*void	radix_sort(t_stack **s_a, t_stack **s_b, t_inst **inst, unsigned int ct)
{
	unsigned int	median;
	unsigned int	ct2;

	ct2 = 0;
	if (ct == 0)
	{
		median = get_pivot(*s_a);
		while (ct2 < median * 2)
		{
			if ((*s_a)->s_ind >= median)
				push_b(s_a, s_b, inst, 1);
			else
				rotate_a(s_a, inst, 1);
			ct2++;
		}
	}
	//printf("WOuAH\n");
	while (!is_bit_sorted(*s_a, ct, 0) && !is_bit_sorted(*s_b, ct, 1))
	{
		//printf("	MOTHER\n");
		//printf("	%u\n", (*s_a)->s_ind);
		if (!first_is_sorted((*s_a)->s_ind, ct, 0))
			push_b(s_a, s_b, inst, 1);
		else
			rotate_a(s_a, inst, 1);
		//printf("	%u\n", (*s_a)->s_ind);
		if (!first_is_sorted((*s_b)->s_ind, ct, 1))
			push_a(s_a, s_b, inst, 1);
		else
			rotate_b(s_b, inst, 1);
	}
	if (!is_sorted(*s_a, 0) && ct < 15)
		radix_sort(s_a, s_b, inst, ct + 1);
}*/

void	radix_sort(t_stack **s_a, t_stack **s_b, t_inst **inst, unsigned int ct)
{
	unsigned int	median;
	unsigned int	ct2;

	ct2 = 0;
	if (ct == 0)
	{
		median = get_pivot(*s_a);
		while (ct2 < median * 2)
		{
			if ((*s_a)->s_ind >= median)
				push_b(s_a, s_b, inst, 1);
			else
				rotate_a(s_a, inst, 1);
			ct2++;
		}
	}
	//printf("WOuAH\n");
	while (!is_bit_sorted(*s_a, ct, 0))
	{
		//printf("	MOTHER\n");
		//printf("	%u\n", (*s_a)->s_ind);
		if (!first_is_sorted((*s_a)->s_ind, ct, 0))
			push_b(s_a, s_b, inst, 1);
		else
			rotate_a(s_a, inst, 1);
	}
	while (!is_bit_sorted(*s_b, ct, 1))
	{
		if (!first_is_sorted((*s_b)->s_ind, ct, 1))
			push_a(s_a, s_b, inst, 1);
		else
			rotate_b(s_b, inst, 1);
	}
	if (!is_sorted(*s_a, 0) && ct < 12)
		radix_sort(s_a, s_b, inst, ct + 1);
}
