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
	int	tmp;

	if (stk == NULL)
		return (1);
	tmp = stk->nb;
	while (stk->next != NULL)
	{
		stk = stk->next;
		if (order == 0)
		{
			if (stk->nb < tmp)
				return (0);
		}
		else
			if (stk->nb > tmp)
				return (0);
		tmp = stk->nb;
	}
	return (1);
}
