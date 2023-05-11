/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:18:41 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/11 17:09:59 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_stack_size(t_stack *stk)
{
	int	size;

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

t_stack	*get_el(t_stack *stk, unsigned int numero)
{
	unsigned int	ct;

	ct = -1;
	while (++ct < numero && stk != NULL)
		stk = stk->next;
	if (stk != NULL)
		return (stk);
	return (NULL);
}
