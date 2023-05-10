/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:11:18 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/10 17:36:14 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Formatted print of error.
 * Exit after it has printed.
*/
int	print_error(char *s, char *str)
{
	stderr_print(s);
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
		ft_printf("%d, (%d) %s", stk->nb, stk->sorted_index, str);
		stk = stk->next;
	}
	ft_printf("The end\n");
}

void	stderr_print(char *s)
{
	ft_putstr_fd(s, 2);
}
