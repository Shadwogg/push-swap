/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:25:51 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/03 16:01:46 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_inst(t_inst **inst, char *str)
{
	(*inst)->str = str;
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
				print_error();
			init_inst(inst, str);
			cur = *inst;
			continue ;
		}
		cur->next = malloc(sizeof(t_inst));
		if (cur->next == NULL)
			print_error();
		init_inst(&(cur->next), str);
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

t_inst	*get_inst(t_inst *inst, unsigned int nb)
{
	while (inst != NULL && --nb > 0)
		inst = inst->next;
	return (inst);
}
