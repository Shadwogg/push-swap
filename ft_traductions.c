/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traductions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:57:46 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/29 17:54:12 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	traduction(t_stack *stk, t_inst *inst, unsigned int pos_l, unsigned int pos_r)
{
	if (pos_l < stk->size - pos_r)
	{
		add_inst(inst, "ra", pos_l);
		add_inst(inst, "pb", 1);
		add_inst(inst, "ra", pos_r - pos_l - 1);
		add_inst(inst, "pb", 1);
		add_inst(inst, "sb", 1);
		add_inst(inst, "pa", 1);
		add_inst(inst, "rra", pos_r - pos_l - 1);
		add_inst(inst, "pa", 1);
		add_inst(inst, "rra", pos_l);
	}
	else
	{
		add_inst(inst, "rra", stk->size - pos_r);
		add_inst(inst, "pb", 1);
		add_inst(inst, "rra", pos_r - pos_l);
		add_inst(inst, "pb", 1);
		add_inst(inst, "sb", 1);
		add_inst(inst, "pa", 1);
		add_inst(inst, "ra", pos_r - pos_l);
		add_inst(inst, "pa", 1);
		add_inst(inst, "ra", stk->size - pos_r);
	}
}

void	pre_traduction(t_stack *stk, t_inst *inst, t_stack *el, t_stack *el2)
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
		traduction(stk, inst, pos, pos2);
	else
		traduction(stk, inst, pos2, pos);
}
