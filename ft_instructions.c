/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:25:51 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/10 18:37:31 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_inst(t_inst	*inst, char *str, unsigned int time)
{
	while (inst != NULL && inst->next != NULL)
		inst = inst->next;
	while (time > 0)
	{
		inst->next = malloc(sizeof(t_inst));
		if (inst->next == NULL)
			print_error("", "MALLOC ERROR");
		inst->next->next = NULL;
		inst->next->str = str;
		inst = inst->next;
		time--;
	}
}
