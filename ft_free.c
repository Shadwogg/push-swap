/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:28:25 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/23 15:14:20 by ggiboury         ###   ########.fr       */
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

	while (stk->next != NULL)
	{
		next = stk->next;
		free(stk);
		stk = next;
	}
	free(stk);
}

void	free_inst(t_inst *inst)
{
	(void) inst;

	printf("Same free_state\n");
}

void	free_state(t_state *s)
{
	t_state	*prev;

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
