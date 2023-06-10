/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:55:54 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/10 18:41:55 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Parse the input, when it's an array within a single string. 
*/
void	parse_str(char *arg, t_stack **stk)
{
	int		size;
	char	**input;

	if (arg == NULL)
		stk = NULL;
	else
	{
		input = ft_split(arg, ' ');
		size = -1;
		while (input[++size])
			;
		check_input(input);
		*stk = ft_parse(size, input);
		check_double(*stk);
		free_tab_str(input, size);
	}
}

/**
 * Parse the input, when it's multiple string.
*/
void	parse_strs(int size, char **argv, t_stack **stk)
{
	check_input(argv);
	*stk = ft_parse(size, argv);
	check_double(*stk);
}

/**
 * Erre handling :
 * If the input is not an int
 * If the input is not a number
 * If the input contains double. Thats all
*/
void	check_input(char **argv)
{
	int	ct;

	ct = -1;
	while (argv[++ct] != NULL)
	{
		if (is_not_number(argv[ct]))
			print_error(argv[ct], " is not an number.");
		else if (is_not_int(argv[ct]))
			print_error(argv[ct], " is not an integer.");
	}
}

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
			ft_putnbr_fd(nb, 2);
			print_error("", " should be unique.");
		}
		cur = cur->next;
	}
}

t_stack	*ft_parse(int size, char **input)
{
	t_stack	*stk;
	t_stack	*next;

	stk = NULL;
	next = NULL;
	while (--size >= 0)
	{
		stk = malloc(sizeof(t_stack));
		if (stk == NULL)
			printf("ERRERO");
		stk->nb = ft_atoi(input[size]);
		stk->next = next;
		next = stk;
	}
	return (stk);
}
