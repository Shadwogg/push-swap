/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:36:54 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/01 23:16:07 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*deduce(char *str)
{
	if (str[0] == 'r' && (str[1] == 'a' || str[1] == 'b'))
		return ("rr");
	if (str[0] == 's' && (str[1] == 'a' || str[1] == 'b'))
		return ("ss");
	if (str[0] == 'r' && str[1] == 'r' && (str[2] == 'a' || str[2] == 'b'))
		return ("rrr");
	return (NULL);
}

void	optimize(t_inst *inst)
{
	t_inst	*tofree;

	while (inst != NULL && inst->next != NULL)
	{
		if (inst->str[0] != 'p' && inst->str[0] == inst->next->str[0])
		{
			if (inst->str[1] == 'r')
				;
			else if (inst->str[1] != inst->next->str[1])
			{
				tofree = inst->next;
				inst->next = inst->next->next;
				inst->str = deduce(inst->str);
				free(tofree);
			}
		}
		if (inst == NULL)
			break ;
		inst = inst->next;
	}
}
