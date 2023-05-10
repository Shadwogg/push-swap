/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:28:25 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/10 14:19:30 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab_str(char **arr, int n)
{
	while (n > 0)
	{
		free(arr[n]);
		n--;
	}
	free(arr[0]);
	free(arr);
}

void	free_stack(t_stack *stk)
{
	t_stack	*next;

	while (stk->next != NULL)
	{
		next = stk->next;
		free(stk);
		stk = next;
	}
	free(stk);
}
