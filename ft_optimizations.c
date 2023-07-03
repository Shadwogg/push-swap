/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:36:54 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/03 21:32:26 by ggiboury         ###   ########.fr       */
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

void	remove_pushes(t_inst **inst)
{
	t_inst	*tofree;
	t_inst	*cur;

	if (*inst == NULL)
		return ;
	cur = *inst;
	while (cur != NULL && cur->next != NULL)
	{
		if (cur->str[0] == 'p' && cur->next->str[0] == 'p')
		{
			if ((cur->str[1] == 'a' && cur->next->str[1] == 'b')
				|| (cur->str[1] == 'b' && cur->next->str[1] == 'a'))
			{
				tofree = cur;
				cur->prev->next = cur->next->next;
				if (cur == *inst)
					*inst = (*inst)->next->next;
				cur = cur->next->next;
				tofree->next->next = NULL;
				free_inst(tofree);
				continue ;
			}
		}
		cur = cur->next;
	}
}

void	remove_swaps(t_inst **inst)
{
	t_inst	*tofree;
	t_inst	*cur;

	if (*inst == NULL)
		return ;
	cur = *inst;
	while (cur != NULL && cur->next != NULL)
	{
		if (cur->str[0] == 's' && cur->next->str[0] == 's')
		{
			if ((cur->str[1] == 'a' && cur->next->str[1] == 'a')
				|| (cur->str[1] == 'b' && cur->next->str[1] == 'b'))
			{
				tofree = cur;
				cur->prev->next = cur->next->next;
				if (cur == *inst)
					*inst = (*inst)->next->next;
				cur = cur->next->next;
				tofree->next->next = NULL;
				free_inst(tofree);
				continue ;
			}
		}
		cur = cur->next;
	}
}

void	optimize(t_inst **inst)
{
	remove_pushes(inst);
	remove_swaps(inst);
}
