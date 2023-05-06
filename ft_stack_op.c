/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:45 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/06 20:20:53 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the two first element from the stack
// Does nothing if the stack has less than two element.
void	swap(t_stack *stk)
{
	int	tmp;

	if (get_stack_size(stk) < 2)
		return ;
	tmp = stk->next->nb;
	stk->next->nb = stk->nb;
	stk->nb = tmp;
}

// Push the first element from the stack a to the stack b.
// Does nothing if the stack a is empty.
void	push(t_stack *stk_a, t_stack *stk_b)
{
	t_stack	*tmp;

	if (stk_a == NULL)
		return ;
	tmp = pop_first(stk_a);
	insert_first(stk_b, tmp);
}

//Shift up all elements of the stack by 1 (the first element become the last)
void	rotate(t_stack *stk)
{
	t_stack	*tmp;

	if (stk == NULL || stk->next == NULL)
		return ;
	tmp = pop_first(stk);
	get_last(stk)->next = tmp;
}

//Shift down all elements of the stack by 1 (the last element become the first)
void	reverse_rotate(t_stack *stk)
{
	t_stack	*tmp;

	if (stk == NULL || stk->next == NULL)
		return ;
	tmp = pop_last(stk);
	insert_first(stk, tmp);
}
