/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:28:25 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/25 17:27:38 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab_str(char **arr, int n)
{
	while (n > 0)
	{
		free(arr[n]);
		n--;
	}
	free(arr[0]);
	free(arr);
}

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

void	free_state(t_state *s)
{
	t_state	*prev;

	if (s == NULL)
		return ;
	prev = s;
	while (s->next != NULL)
	{
		s = s->next;
		free_stack(prev->s_a);
		free_stack(prev->s_b);
		free_inst(prev->inst);
		free(prev);
		prev = s;
	}
	free_stack(prev->s_a);
	free_stack(prev->s_b);
	free_inst(prev->inst);
	free(prev);
}
