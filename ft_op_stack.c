/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:45 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/31 15:18:33 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the two first element from the stack
// Does nothing if the stack has less than two element.
void	swap(t_array *arr)
{
	int	tmp;

	if (arr->size < 2)
		return ;
	tmp = arr->arr[0];
	arr->arr[0] = arr->arr[1];
	arr->arr[1] = tmp;
}

// Push the first element from the stack a to the stack b.
// Does nothing if the stack a is empty.
void	push(t_array *arr_a, t_array *arr_b)
{
	int	tmp;

	if (arr_a->size == 0)
		return ;
	tmp = pop_first(arr_a);
	arr_a->size--;
	add_first(arr_b, tmp);
	arr_b->size++;
}

//Shift up all elements of the stack by 1 (the first element become the last)
void	rotate(t_array *arr)
{
	int	tmp;

	if (arr == NULL || arr->size == 0 || arr->size == 1)
		return ;
	tmp = pop_first(arr);
	arr->arr[arr->size - 1] = tmp;
}

//Shift down all elements of the stack by 1 (the last element become the first)
void	reverse_rotate(t_array *arr)
{
	if (arr == NULL || arr->size == 0 || arr->size == 1)
		return ;
	add_first(arr, arr->arr[arr->size - 1]);
}
