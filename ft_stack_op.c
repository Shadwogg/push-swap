/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:45 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/01 17:58:27 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the two first element from the stack
// Does nothing if the stack has less than two element.
void	swap(t_stack **stk)
{
	t_stack	*tmp;

	printf("A VERIF\n");
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

	tmp = *stk_2;
	tmp->next = *stk_1;
	*stk_2 = (*stk_2)->next;
	*stk_1 = tmp;
	printf("TO VERIFIER\n");
}

//Shift up all elements of the stack by 1 (the first element become the last)
void	rotate(t_stack *stk)
{
	t_stack	*tmp;

	tmp = pop_first(stk);
	get_last(stk)->next = tmp;
}

//Shift down all elements of the stack by 1 (the last element become the first)
void	reverse_rotate(t_stack *stk)
{
	t_stack	*tmp;

	tmp = pop_last(stk);
	insert_first(stk, tmp);
	return ()
}
