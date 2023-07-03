/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:11:18 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/03 21:24:17 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Formatted print of error.
 * Exit after it has printed.
*/
int	print_error(t_inst *inst, t_stack *s)
{
	if (inst != NULL)
		free_inst(inst);
	if (s != NULL)
		free_stack(s);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_SUCCESS);
}
