/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:04:25 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/10 15:46:03 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	in_stack(int *arr, int size, int nb)
{
	int	ct;

	ct = 0;
	while (ct < size)
	{
		if (arr[ct] == nb)
			return (1);
		ct++;
	}
	return (0);
}*/

/*int	get_len_arr(char *s)
{
	int	size;
	int	ct;

	size = 1;
	ct = 0;
	while (s[ct])
	{
		if (s[ct] == ' ')
			size++;
		ct++;
	}
	return (size);
}*/

t_stack	*pop_first(t_stack *stk)
{
	t_stack	*tmp;

	tmp = stk;
	*stk = *stk->next;
	tmp->next = NULL;
	return (tmp);
}

t_stack	*pop_last(t_stack *stk)
{
	t_stack	*tmp;

	if (stk == NULL)
		return (NULL);
	while (stk->next != NULL || stk->next->next != NULL)
		stk = stk->next;
	tmp = stk->next;
	stk->next = NULL;
	return (tmp);
}

void	insert_first(t_stack *stk, t_stack *el)
{
	if (stk == NULL)
	{
		*stk = *el;
		return ;
	}
	while (stk->next != NULL)
		stk = stk->next;
	stk->next = el;
}

int	is_sorted(t_stack *stk)
{
	int	tmp;

	if (stk == NULL)
		return (1);
	tmp = stk->nb;
	while (stk->next != NULL)
	{
		stk = stk->next;
		if (stk->nb < tmp)
			return (0);
		tmp = stk->nb;
	}
	return (1);
}

int	get_stack_size(t_stack *stk)
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
