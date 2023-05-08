/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:11:18 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/08 19:24:17 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Formatted print of error.
 * Exit after it has printed.
*/
int	print_error(char *s, char *str)
{
	//TO DO : Changer la sortie vers la sortie d'erreur
	stderr_print(s);
	stderr_print(str);
	printf("\n");
	exit(EXIT_SUCCESS);
}

/**
 * Print the stack depending on the format asked.
*/
void	print_stack(t_stack *stk, char format)
{
	if (format == 'n')
	{
		while (stk != NULL)
		{
			ft_printf("%d\n", stk->nb);
			stk = stk->next;
		}	
		ft_printf("The end\n");
	}
	else if (format == 'l')
	{
		while (stk != NULL)
		{
			ft_printf("%d -> ", stk->nb);
			stk = stk->next;
		}
		ft_printf("The end\n");
	}
}

void	stderr_print(char *s)
{
	ft_printf("%s", s);
}
