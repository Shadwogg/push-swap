/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:25:51 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/25 20:25:48 by ggiboury         ###   ########.fr       */
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
				print_error("", "MALLOC ERROR");
			init_inst(inst, str);
			cur = *inst;
			continue ;
		}
		cur->next = malloc(sizeof(t_inst));
		if (cur->next == NULL)
			print_error("", "MALLOC ERROR");
		init_inst(&(cur->next), str);
		cur = cur->next;
	}
}

//A TESTETRRERERERERERERERERRERERERERRERE
t_inst	*cp_inst(t_inst *inst)
{
	t_inst	*new;
	t_inst	*next;
	t_inst	*cur;

	if (inst == NULL)
		return (NULL);
	new = malloc(sizeof(t_inst));
	if (new == NULL)
		print_error("", "Malloc error");
	init_inst(&new, inst->str);
	inst = inst->next;
	cur = new;
	while (inst != NULL)
	{
		next = malloc(sizeof(t_inst));
		if (next == NULL)
			print_error("", "Malloc error");
		init_inst(&next, inst->str);
		cur->next = next;
		cur = cur->next;
		inst = inst->next;
	}
	return (new);
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
