/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:11:18 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/29 16:44:32 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Formatted print of error.
 * Exit after it has printed.
*/
int	print_error(char *nb, char *str)
{
	stderr_print(nb);
	free(nb);
	stderr_print(str);
	stderr_print("\n");
	exit(EXIT_SUCCESS);
}

/**
 * Print the stack depending on the format asked.
*/
void	print_stack(t_stack *stk, char *str)
{
	while (stk != NULL)
	{
		ft_printf("%d%s", stk->nb, str);
		stk = stk->next;
	}
	ft_printf("\n");
}

void	stderr_print(char *s)
{
	if (s != NULL)
		ft_putstr_fd(s, 2);
}
