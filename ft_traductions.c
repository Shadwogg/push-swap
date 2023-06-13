/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traductions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:57:46 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/13 12:28:57 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **s, t_inst *inst, unsigned int time)
{
	if (get_stack_size(*s) < 2 || time == 0)
		return ;
	add_inst(inst, "sa", time);
	while (time-- > 0)
		swap(s);
}

void	swap_b(t_stack **s, t_inst *inst, unsigned int time)
{
	if (get_stack_size(*s) < 2 || time == 0)
		return ;
	add_inst(inst, "sb", time);
	while (time-- > 0)
		swap(s);
}

void	push_a(t_stack **s_a, t_stack **s_b, t_inst *inst, unsigned int time)
{
	if (s_b == NULL || *s_b == NULL || time == 0)
		return ;
	add_inst(inst, "pa", time);
	while (time-- > 0)
		push(s_b, s_a);
}

void	push_b(t_stack **s_a, t_stack **s_b, t_inst *inst, unsigned int time)
{
	if (s_a == NULL || *s_a == NULL || time == 0)
		return ;
	add_inst(inst, "pb", time);
	while (time-- > 0)
		push(s_a, s_b);
}

void	rotate_a(t_stack **s, t_inst *inst, unsigned int time)
{
	if (s == NULL || *s == NULL || (*s)->next == NULL || time == 0)
		return ;
	add_inst(inst, "ra", time);
	while (time-- > 0)
		rotate(s);
}

void	rotate_b(t_stack **s, t_inst *inst, unsigned int time)
{
	if (s == NULL || *s == NULL || (*s)->next == NULL || time == 0)
		return ;
	add_inst(inst, "rb", time);
	while (time-- > 0)
		rotate(s);
}

void	reverse_rotate_a(t_stack **s, t_inst *inst, unsigned int time)
{
	if (s == NULL || *s == NULL || (*s)->next == NULL || time == 0)
		return ;
	add_inst(inst, "rra", time);
	while (time-- > 0)
		reverse_rotate(s);
}
void	reverse_rotate_b(t_stack **s, t_inst *inst, unsigned int time)
{
	if (s == NULL || *s == NULL || (*s)->next == NULL || time == 0)
		return ;
	add_inst(inst, "rrb", time);
	while (time-- > 0)
		reverse_rotate(s);
}
