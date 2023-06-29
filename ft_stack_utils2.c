/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:18:41 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/29 12:53:23 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_stack_size(t_stack *stk)
{
	unsigned int	size;

	size = 0;
	while (stk != NULL)
	{
		stk = stk->next;
		size++;
	}
	return (size);
}

t_stack	*get_last(t_stack *stk)
{
	if (stk == NULL)
		return (NULL);
	while (stk->next != NULL)
		stk = stk->next;
	return (stk);
}

/**
 * Return the numero element of the stack
*/
t_stack	*get_el(t_stack *stk, unsigned int numero)
{
	unsigned int	ct;

	ct = 0;
	while (stk != NULL && ct < numero)
	{
		ct++;
		stk = stk->next;
	}
	return (stk);
}

t_stack	*get_el_sorted(t_stack *stk, unsigned int numero)
{
	while (stk != NULL && stk->s_ind != numero)
		stk = stk->next;
	return (stk);
}

t_stack	*get_prev_el(t_stack *s, t_stack *el)
{
	unsigned int	searching;

	if (s == NULL || el == NULL)
		print_error("ERREOR", "");
	if (el->s_ind == 0)
		return (NULL);
	searching = el->s_ind - 1;
	return (get_el_sorted(s, searching));
}
