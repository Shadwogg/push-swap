/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traductions2.C                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:14:59 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/03 17:16:25 by ggiboury         ###   ########.fr       */
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
