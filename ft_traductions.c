/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traductions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:57:46 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/03 19:17:19 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	traduction(t_stack *stk, t_inst *inst, unsigned int pos_l, unsigned int pos_r)
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
}*/

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
	(void) inst;
	/*
	if (pos < pos2)
		traduction(stk, inst, pos, pos2);
	else
		traduction(stk, inst, pos2, pos);*/
}

void	swap_a(t_stack **stk, t_inst *inst)
{
	if (get_stack_size(*stk) < 2)
		return ;
	swap(stk);
	add_inst(inst, "sa", 1);
}

void	swap_b(t_stack **stk, t_inst *inst)
{
	if (get_stack_size(*stk) < 2)
		return ;
	swap(stk);
	add_inst(inst, "sb", 1);
}

void	push_a(t_stack **stk_a, t_stack **stk_b, t_inst *inst)
{
	if (stk_b == NULL || *stk_b == NULL)
		return ;
	push(stk_b, stk_a);
	add_inst(inst, "pa", 1);
}

void	push_b(t_stack **stk_a, t_stack **stk_b, t_inst *inst)
{
	if (stk_a == NULL || *stk_a == NULL)
		return ;
	push(stk_a, stk_b);
	add_inst(inst, "pb", 1);
}

void	rotate_a(t_stack **stk, t_inst *inst)
{
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return ;
	rotate(stk);
	add_inst(inst, "ra", 1);
}

void	rotate_b(t_stack **stk, t_inst *inst)
{
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return ;
	rotate(stk);
	add_inst(inst, "rb", 1);
}

void	reverse_rotate_a(t_stack **stk, t_inst *inst)
{
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return ;
	reverse_rotate(stk);
	add_inst(inst, "rra", 1);
}
void	reverse_rotate_b(t_stack **stk, t_inst *inst)
{
	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return ;
	reverse_rotate(stk);
	add_inst(inst, "rrb", 1);
}
