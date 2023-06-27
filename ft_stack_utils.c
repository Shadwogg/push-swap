/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:04:25 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/10 15:46:03 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s, int nb, unsigned int s_ind)
{
	s->nb = nb;
	s->s_ind = s_ind;
	s->next = NULL;
}

t_stack	*cp_stack(t_stack *s)
{
	t_stack	*new;
	t_stack	*next;
	t_stack	*cur;

	// ft_putstr_fd("-----TUTU\n", 1);
	if (s == NULL)
		return (NULL);
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		print_error("", "Malloc error");
	init_stack(new, s->nb, s->s_ind);
	s = s->next;
	cur = new;
	while (s != NULL)
	{
		next = malloc(sizeof(t_stack));
		if (next == NULL)
			print_error("", "Malloc error");
		init_stack(next, s->nb, s->s_ind);
		cur->next = next;
		cur = cur->next;
		s = s->next;
	}
	// ft_putstr_fd("-----SORTIE\n", 1);
	return (new);
}

int	in_stack(int nb, t_stack *stk)
{
	while (stk != NULL)
	{
		if (stk->nb == nb)
			return (1);
		stk = stk->next;
	}
	return (0);
}

int	is_sorted(t_stack *stk, char order)
{
	int	prev;

	if (stk == NULL)
		return (1);
	prev = stk->nb;
	if (order == 0)
	{
		while (stk->next != NULL)
		{
			stk = stk->next;
			if (prev > stk->nb)
				return (0);
			prev = stk->nb;
		}
		return (1);
	}
	while (stk->next != NULL)
	{
		stk = stk->next;
		if (prev < stk->nb)
			return (0);
		prev = stk->nb;
	}
	return (1);
}

void	update_indexes(t_stack *stk)
{
	t_stack			*cur;
	t_stack			*save;
	unsigned int	nb;

	cur = stk;
	save = stk;
	while (cur != NULL)
	{
		nb = 0;
		stk = save;
		while (stk != NULL)
		{
			if (cur->nb > stk->nb)
				nb++;
			stk = stk->next;
		}
		cur->s_ind = nb;
		cur = cur->next;
	}
}
