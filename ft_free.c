/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:28:25 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/29 12:51:00 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stk)
{
	t_stack	*next;

	if (stk == NULL)
		return ;
	while (stk->next != NULL)
	{
		next = stk->next;
		free(stk);
		stk = next;
	}
	free(stk);
	stk = NULL;
}

void	free_inst(t_inst *inst)
{
	t_inst	*next;

	if (inst == NULL)
		return ;
	while (inst->next != NULL)
	{
		next = inst->next;
		free(inst);
		inst = next;
	}
	free(inst);
}
