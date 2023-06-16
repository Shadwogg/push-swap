/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:25:51 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/16 13:17:52 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_inst(t_inst	**inst, char *str, unsigned int time)
{
	t_inst	*cur;

	cur = *inst;
	time++;
	while (*inst != NULL && (*inst)->next != NULL)
		*inst = (*inst)->next;
	while (--time > 0)
	{
		if (*inst == NULL)
		{
			*inst = malloc(sizeof(t_inst));
			if (*inst == NULL)
				print_error("", "MALLOC ERROR");
			(*inst)->next = NULL;
			(*inst)->str = str;
			continue ;
		}
		printf("TESTTSTSTSTTSS\n");
		(*inst)->next = malloc(sizeof(t_inst));
		if ((*inst)->next == NULL)
			print_error("", "MALLOC ERROR");
		(*inst)->next->next = NULL;
		(*inst)->next->str = str;
		*inst = (*inst)->next;
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
