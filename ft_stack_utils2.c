/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:18:41 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/15 16:17:47 by ggiboury         ###   ########.fr       */
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

	ct = 0;
	while (ct < numero && stk != NULL)
	{
		stk = stk->next;
		ct++;
	}
	return (stk);
}

t_stack	*get_el_sorted(t_stack *stk, unsigned int numero)
{
	while (stk != NULL && stk->s_ind != numero)
		stk = stk->next;
	return (stk);
}

/**
 * Split the stack in two, at the piv position
 * Return the right half of the stack. 
*/
t_stack	*divide(t_stack *stk, unsigned int piv, t_inst *inst)
{
	unsigned int	ct;
	t_stack			*cur;

	(void) inst;
	ct = 0;
	while (ct < piv)
	{
		stk = stk->next;
		ct++;
	}
	cur = stk->next;
	stk->next = NULL;
	//update_index(cur);
	return (cur);
}

/*void	update_index(t_stack *stk)
{
	int	size;

	size = get_stack_size(stk);
	while (stk != NULL)
	{
		stk->sorted_index -= size + 1;
		stk = stk->next;
	}
}*/

t_stack	*get_prev_el(t_stack *s, t_stack *el)
{
	unsigned int	searching;

	if (el->s_ind == 0)
		return (NULL);
	searching = el->s_ind - 1;
	return (get_el_sorted(s, searching));
}
