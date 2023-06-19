/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:29:02 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/19 17:09:37 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_bit_sorted(t_stack *s, unsigned int bit, unsigned int val)
{
	unsigned int	nb;
	unsigned int	ct;

	if (s == NULL)
		return (0);
	while (s != NULL)
	{
		ct = 0;
		nb = s->s_ind;
		while (ct < bit)
		{
			nb = nb / 2;
			ct++;
		}
		if (nb % 2 != val)
			return (0);
		s = s->next;
	}
	return (1);
}

int	first_is_sorted(unsigned int nb, unsigned int bit, unsigned int val)
{
	unsigned int	ct;

	ct = 0;
	while (ct < bit)
	{
		nb = nb / 2;
		ct++;
	}
	return (nb % 2 != val);
}

void	radix_sort(t_stack **s_a, t_stack **s_b, t_inst **inst, unsigned int ct)
{
	while (!is_bit_sorted(*s_a, ct, 1) && !is_bit_sorted(*s_b, ct, 0))
	{
		printf("TEST\n");
		if (!first_is_sorted((*s_a)->s_ind, ct, 1))
			push_b(s_a, s_b, inst, 1);
		else
			rotate_a(s_a, inst, 1);
		if (!first_is_sorted((*s_b)->s_ind, ct, 0))
			push_a(s_a, s_b, inst, 1);
		else
			rotate_b(s_b, inst, 1);
	}
	/*if (!is_sorted(*s_a, 0))
		radix_sort(s_a, s_b, inst, ct + 1);*/
}
