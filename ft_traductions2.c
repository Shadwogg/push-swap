/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traductions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:14:59 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/04 15:44:11 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_stack **s, t_inst **inst, unsigned int time)
{
	if (s == NULL || *s == NULL || (*s)->next == NULL || time == 0)
		return ;
	add_inst(inst, "rb", time);
	while (time-- > 0)
		rotate(s);
}

void	reverse_rotate_a(t_stack **s, t_inst **inst, unsigned int time)
{
	if (s == NULL || *s == NULL || (*s)->next == NULL || time == 0)
		return ;
	add_inst(inst, "rra", time);
	while (time-- > 0)
		reverse_rotate(s);
}

void	reverse_rotate_b(t_stack **s, t_inst **inst, unsigned int time)
{
	if (s == NULL || *s == NULL || (*s)->next == NULL || time == 0)
		return ;
	add_inst(inst, "rrb", time);
	while (time-- > 0)
		reverse_rotate(s);
}

int	is_min(int nb, t_stack *s)
{
	while (s != NULL)
	{
		if (nb > s->nb)
			return (0);
		s = s->next;
	}
	return (1);
}

int	is_max(int nb, t_stack *s)
{
	while (s != NULL)
	{
		if (nb < s->nb)
			return (0);
		s = s->next;
	}
	return (1);
}
