/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:28:25 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/27 18:28:56 by ggiboury         ###   ########.fr       */
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

	// ft_putstr_fd("	FREES_TACKSKSKSKSKSKSKSKS\n", 1);
	if (stk == NULL)
		return ;
	// ft_putstr_fd("	FREES_TACKSKSKSKSKSKSKSKS\n", 1);
	while (stk->next != NULL)
	{
		// ft_putstr_fd("		PREFREE1\n", 1);
		next = stk->next;
		free(stk);
		// ft_putstr_fd("		POSTFREE2\n", 1);
		stk = next;
	}
	// ft_putstr_fd("				PRETFREE\n", 1);
	free(stk);
	// ft_putstr_fd("				POSTFREE\n", 1);
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

	// ft_putstr_fd("	BONSUS\n", 1);
	// ft_printf("	%p\n", s);
	if (s == NULL)
		return ;
	// ft_putstr_fd("	MAUVAISUS\n", 1);
	prev = s;
	while (s->next != NULL)
	{
		s = s->next;
		// ft_putstr_fd("1\n", 1);
		free_stack(prev->s_a);
		// ft_putstr_fd("2\n", 1);
		free_stack(prev->s_b);
		// ft_putstr_fd("3\n", 1);
		free_inst(prev->inst);
		// ft_putstr_fd("e\n", 1);
		free(prev);
		// ft_putstr_fd("solein\n", 1);
		prev = s;
	}
	// ft_putstr_fd("	MOYENSUS\n", 1);
	// print_stack(prev->s_a, "UN ");
	free_stack(prev->s_a);
	// ft_putstr_fd("	CODER\n", 1);
	free_stack(prev->s_b);
	// ft_putstr_fd("	PASBONSUSSUS\n", 1);
	free_inst(prev->inst);
	free(prev);
}
