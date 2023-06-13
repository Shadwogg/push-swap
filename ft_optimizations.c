/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:36:54 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/13 14:54:27 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_optimization(t_stack *stk_a, t_stack *stk_b)
{
	(void) stk_a;
	(void) stk_b;
}

void	optimize(t_inst *inst)
{
	t_inst	*tofree;

	while (inst != NULL && inst->next != NULL)
	{
		if (ft_strncmp(inst->str, inst->next->str, 1) == 0)
		{
			if (inst->str[1] != inst->next->str[1])
			{
				tofree = inst->next;
				inst->next = inst->next->next;
				inst->str[1] = inst->str[0];
				free(tofree);
			}
		}
		inst = inst->next;
		if (inst == NULL)
			break ;
	}
}
