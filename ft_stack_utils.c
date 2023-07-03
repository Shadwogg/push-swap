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

int	in_stack(int nb, t_stack *stk)
{
	while (stk != NULL)
	{
		if (stk->nb == nb)
			return (1);
		stk = stk->next;
	}
	return (0);
}

int	is_sorted(t_stack *stk, char order)
{
	int	prev;

	if (stk == NULL)
		return (1);
	prev = stk->nb;
	if (order == 0)
	{
		while (stk->next != NULL)
		{
			stk = stk->next;
			if (prev > stk->nb)
				return (0);
			prev = stk->nb;
		}
		return (1);
	}
	while (stk->next != NULL)
	{
		stk = stk->next;
		if (prev < stk->nb)
			return (0);
		prev = stk->nb;
	}
	return (1);
}

void	update_indexes(t_stack *stk)
{
	t_stack			*cur;
	t_stack			*save;
	unsigned int	nb;

	cur = stk;
	save = stk;
	while (cur != NULL)
	{
		nb = 0;
		stk = save;
		while (stk != NULL)
		{
			if (cur->nb > stk->nb)
				nb++;
			stk = stk->next;
		}
		cur->s_ind = nb;
		cur = cur->next;
	}
}

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
