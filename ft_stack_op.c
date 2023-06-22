/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:45 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/22 15:36:14 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the two first element from the stack
// Does nothing if the stack has less than two element.
void	swap(t_stack **stk)
{
	t_stack	*tmp;

	tmp = (*stk)->next;
	(*stk)->next = tmp->next;
	tmp->next = *stk;
	*stk = tmp;
}

// Push the first element from the stack 1 to the stack 2.
// Does nothing if the stack 1 is empty.
void	push(t_stack **stk_1, t_stack **stk_2)
{
	t_stack	*tmp;

	tmp = *stk_1;
	*stk_1 = (*stk_1)->next;
	if (stk_2 == NULL)
	{
		stk_2 = &tmp;
		(*stk_2)->next = NULL;
		return ;
	}
	tmp->next = *stk_2;
	*stk_2 = tmp;
}

//Shift up all elements of the stack by 1 (the first element become the last)
void	rotate(t_stack **stk)
{
	t_stack	*tmp;

	tmp = *stk;
	*stk = (*stk)->next;
	get_last(*stk)->next = tmp;
	tmp->next = NULL;
}

//Shift down all elements of the stack by 1 (the last element become the first)
void	reverse_rotate(t_stack **stk)
{
	t_stack	*tmp;
	t_stack	*cur;

	cur = *stk;
	while (cur->next != NULL && cur->next->next != NULL)
		cur = cur->next;
	tmp = cur->next;
	cur->next = NULL;
	tmp->next = *stk;
	*stk = tmp;
}
