/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traductions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:57:46 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/27 01:55:49 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	traduction(t_stack *stk, unsigned int pos_l, unsigned int pos_r)
{
	printf("left = %d, right = %d\n", pos_l, pos_r);
	if (stk->size - pos_r > pos_l)
	{
		while (pos_l > 0)
		{
			//rotate;
			printf("ra\n");
			pos_l--;
		}
	}
	else
	{
		while (pos_r < stk->size)
		{
			//reverse_rotate;
			printf("rra\n");
			pos_r++;
		}
	}
	printf("left = %d, right = %d\n", pos_l, pos_r);
	printf("Fin\n");
}

void	pre_traduction(t_stack *stk, t_stack *el, t_stack *el2)
{
	t_stack			*cur;
	long			pos;
	long			pos2;
	unsigned int	ct;

	cur = stk;
	ct = 0;
	pos = -1;
	pos2 = -1;
	while (cur != NULL && (pos == -1 || pos2 == -1))
	{
		if (cur == el)
			pos = ct;
		else if (cur == el2)
			pos2 = ct;
		ct++;
		cur = cur->next;
	}
	if (pos == -1 || pos2 == -1)
		printf("ERROR\n");
	if (pos < pos2)
		traduction(stk, pos, pos2);
	else
		traduction(stk, pos2, pos);	
}
