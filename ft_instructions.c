/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:25:51 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/03 21:29:43 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_inst(t_inst **inst, char *str, t_inst *prev)
{
	(*inst)->str = str;
	(*inst)->prev = prev;
	(*inst)->next = NULL;
}

void	add_inst(t_inst	**inst, char *str, unsigned int time)
{
	t_inst	*cur;

	cur = *inst;
	time++;
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	while (--time > 0)
	{
		if (*inst == NULL)
		{
			*inst = malloc(sizeof(t_inst));
			if (*inst == NULL)
				print_error(*inst, NULL);
			init_inst(inst, str, NULL);
			cur = *inst;
			continue ;
		}
		cur->next = malloc(sizeof(t_inst));
		if (cur->next == NULL)
			print_error(*inst, NULL);
		init_inst(&(cur->next), str, cur);
		cur = cur->next;
	}
}

void	read_inst(t_inst *inst)
{
	while (inst != NULL)
	{
		ft_printf("%s\n", inst->str);
		inst = inst->next;
	}
}
