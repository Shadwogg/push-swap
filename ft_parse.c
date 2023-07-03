/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:55:54 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/03 21:23:03 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Test if the number is an integer.
int	is_not_int(char *nb)
{
	long	tmp;
	int		ct;

	ct = 0;
	tmp = 0;
	if (nb[0] == '-' || nb[0] == '+')
		ct++;
	while (nb[ct])
	{
		tmp = tmp * 10 + nb[ct] - 48;
		if (tmp > INT_MAX)
			break ;
		ct++;
	}
	if (nb[0] == '-')
		tmp *= -1;
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (1);
	return (0);
}

int	is_not_number(char *nb)
{
	int	ct;

	ct = -1;
	if (nb == NULL)
		return (1);
	if (nb[0] == '+' || nb[0] == '-')
		ct++;
	while (nb[++ct])
	{
		if (nb[ct] < 48 || nb[ct] > 57)
			return (1);
	}
	return (0);
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
			print_error(NULL, NULL);
		else if (is_not_int(argv[ct]))
			print_error(NULL, NULL);
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
			print_error(NULL, stk);
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
			print_error(NULL, stk);
		last->s_ind = 0;
		last->nb = ft_atoi(input[size]);
		last->next = stk;
		stk = last;
	}
	return (stk);
}
