/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:36:54 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/04 15:45:23 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_pushes(t_inst **inst)
{
	t_inst	*tofree;
	t_inst	*cur;

	cur = *inst;
	while (cur != NULL && cur->next != NULL)
	{
		if (cur->str[0] == 'p' && cur->next->str[0] == 'p'
			&& ((cur->str[1] == 'a' && cur->next->str[1] == 'b')
				|| (cur->str[1] == 'b' && cur->next->str[1] == 'a')))
		{
			tofree = cur;
			if (cur == *inst)
				*inst = (*inst)->next->next;
			if (cur->prev != NULL)
				cur->prev->next = cur->next->next;
			if (cur->next->next != NULL)
				cur->next->next->prev = cur->prev;
			cur = cur->next->next;
			tofree->next->next = NULL;
			free_inst(tofree);
			continue ;
		}
		cur = cur->next;
	}
}

void	remove_swaps(t_inst **inst)
{
	t_inst	*tofree;
	t_inst	*cur;

	cur = *inst;
	while (cur != NULL && cur->next != NULL)
	{
		if (cur->str[0] == 's' && cur->next->str[0] == 's'
			&& ((cur->str[1] == 'a' && cur->next->str[1] == 'a')
				|| (cur->str[1] == 'b' && cur->next->str[1] == 'b')))
		{
			tofree = cur;
			if (cur == *inst)
				*inst = (*inst)->next->next;
			if (cur->prev != NULL)
				cur->prev->next = cur->next->next;
			if (cur->next->next != NULL)
				cur->next->next->prev = cur->prev;
			cur = cur->next->next;
			tofree->next->next = NULL;
			free_inst(tofree);
			continue ;
		}
		cur = cur->next;
	}
}

void	remove_rotates(t_inst **inst)
{
	t_inst	*tofree;
	t_inst	*cur;

	cur = *inst;
	while (cur != NULL && cur->next != NULL)
	{
		if (cur->str[0] == 'r' && cur->str[0] == cur->next->str[0]
			&& (cur->str[1] == 'r' ^ cur->next->str[1] == 'r')
			&& (cur->str[2] == cur->next->str[1]
				|| cur->str[1] == cur->next->str[2]))
		{
			tofree = cur;
			if (cur == *inst)
				*inst = (*inst)->next->next;
			if (cur->prev != NULL)
				cur->prev->next = cur->next->next;
			if (cur->next->next != NULL)
				cur->next->next->prev = cur->prev;
			cur = cur->next->next;
			tofree->next->next = NULL;
			free_inst(tofree);
			continue ;
		}
		cur = cur->next;
	}
}

void	mutualize_swaps(t_inst **inst)
{
	t_inst	*cur;
	t_inst	*el2;

	cur = *inst;
	el2 = NULL;
	while (cur != NULL)
	{
		if (cur->str[0] == 's' && cur->str[1] == 'a')
			el2 = get_next_el(cur->next, "sb");
		else if (cur->str[0] == 's' && cur->str[0] == 'b')
			el2 = get_next_el(cur, "sa");
		if (el2 != NULL)
		{
			cur->str = "ss";
			remove_inst(el2);
			el2 = NULL;
		}
		cur = cur->next;
	}
}

void	optimize(t_inst **inst)
{
	remove_pushes(inst);
	remove_swaps(inst);
	while (rotate_is_removable(inst))
		remove_rotates(inst);
	mutualize_swaps(inst);
}
