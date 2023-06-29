/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:55:54 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/29 11:19:43 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Parse the input.
*/
void	parse_strs(int size, char **argv, t_stack **stk)
{
	check_input(argv);
	*stk = ft_parse(size, argv);
	check_double(*stk);
}

/**
 * Error in input handling :
 *	If the input is not an int
 *	If the input is not a number
*/
void	check_input(char **argv)
{
	int	ct;

	ct = -1;
	while (argv[++ct] != NULL)
	{
		if (is_not_number(argv[ct]))
			print_error(ft_strdup(argv[ct]), " is not an number.");
		else if (is_not_int(argv[ct]))
			print_error(ft_strdup(argv[ct]), " is not an integer.");
	}
}

/**
 * Checks if a number appears twice in the stack
*/
void	check_double(t_stack *stk)
{
	t_stack	*cur;
	int		nb;

	cur = stk;
	while (cur != NULL)
	{
		nb = cur->nb;
		if (in_stack(nb, cur->next))
		{
			free_stack(stk);
			print_error(ft_itoa(nb), " should be unique.");
		}
		cur = cur->next;
	}
}

t_stack	*ft_parse(int size, char **input)
{
	t_stack	*stk;
	t_stack	*last;

	stk = NULL;
	while (--size >= 0)
	{
		last = malloc(sizeof(t_stack));
		if (last == NULL)
			print_error(NULL, "Malloc error in ft_parse");
		last->s_ind = 0;
		last->nb = ft_atoi(input[size]);
		last->next = stk;
		stk = last;
	}
	return (stk);
}
