/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:39:13 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/04 15:46:00 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_inst(t_inst *inst)
{
	if (inst->prev != NULL)
		inst->prev->next = inst->next;
	if (inst->next != NULL)
		inst->next->prev = inst->prev;
	inst->next = NULL;
	free_inst(inst);
}

t_inst	*get_next_el(t_inst *inst, char *str)
{
	while (inst != NULL)
	{
		if (inst->str[0] == 'p'
			|| (inst->str[0] == 'r' && inst->str[1] == str[1])
			|| (inst->str[1] == 'r' && inst->str[2] == str[1]))
			return (NULL);
		if (ft_strncmp(inst->str, str, 2) == 0)
			return (inst);
		inst = inst->next;
	}
	return (NULL);
}

int	rotate_is_removable(t_inst **inst)
{
	t_inst	*cur;

	if (inst == NULL || *inst == NULL)
		return (0);
	cur = *inst;
	while (cur != NULL && cur->next != NULL)
	{
		if (cur->str[0] == 'r' && cur->str[0] == cur->next->str[0]
			&& (cur->str[1] == 'r' ^ cur->next->str[1] == 'r')
			&& (cur->str[1] == cur->next->str[2]
				|| cur->str[2] == cur->next->str[1]))
			return (1);
		cur = cur->next;
	}
	return (0);
}

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

int	is_permutation(t_stack *s)
{
	unsigned int	ct;
	unsigned int	diff;
	size_t			size;

	ct = 0;
	diff = 0;
	size = get_stack_size(s);
	while (s != NULL && s->next != NULL && ct < 2)
	{
		if (s->s_ind < s->next->s_ind && s->next->s_ind - s->s_ind > 1)
			return (0);
		if (s->s_ind > s->next->s_ind)
		{
			diff = s->s_ind - s->next->s_ind;
			ct++;
		}
		s = s->next;
	}
	if (ct >= 2 || s->next != NULL)
		return (0);
	return (diff == (unsigned int) size - 1);
}
