/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:55:54 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/06 16:09:12 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Parse the input, when it's an array within a single string. 
*/
void	parse_str(char *arg, t_stack *stk)
{
	//if (arg[0] == 0)
	//	print_error("???");
	//single_input_is_invalid(arg);
	//stk = parse(arg);
	(void) stk;
	(void) arg;
}

/**
 * Parse the input, when it's multiple string.
*/
void	parse_strs(int size, char **argv, t_stack *stk)
{
	(void) size;
	(void) stk;
	(void) argv;
	//inputs_is_invalid(argv);
}

// Check if the input has the appropriate format.
/*int	input_is_invalid(char *argv)
{
	char	**tab;
	int		ct;
	int		*arr;
	int		nb;

	tab = ft_split(argv, ' ');
	ct = 0;
	arr = malloc(arrstr_len(tab) * sizeof(int));
	if (arr == NULL)
		print_error("Malloc failed");
	while (tab[ct] != NULL)
	{
		if (is_not_int(tab[ct]))
			print_error("The list should only have integers.");
		nb = ft_atoi(tab[ct]);
		if (in_stack(arr, ct, nb))
			print_error("Duplicate are not allowed.");
		arr[ct] = nb;
		ct++;
	}
	free_tab_str(tab, ct);
	free(arr);
	return (0);
}*/

// Returns a new stack made of the list of integer given.
/*t_array	*parse(char *argv)
{
	t_array	*arr;
	char	**tab;
	int		ct;

	arr = malloc(sizeof(t_array));
	if (arr == NULL)
	{
		print_error("Malloc failed.");
		return (NULL);
	}
	arr->size = get_len_arr(argv);
	arr->arr = malloc((arr->size) * sizeof(int));
	tab = ft_split(argv, ' ');
	ct = 0;
	while (tab[ct] != NULL)
	{
		arr->arr[ct] = ft_atoi(tab[ct]);
		ct++;
	}
	free_tab_str(tab, ct);
	return (arr);
}*/
