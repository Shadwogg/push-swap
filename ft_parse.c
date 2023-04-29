/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:55:54 by ggiboury          #+#    #+#             */
/*   Updated: 2023/03/22 14:41:03 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns the length of the array of string.
int	arrstr_len(char **tab)
{
	int	ct;

	if (tab == NULL)
		return (-1);
	ct = 0;
	while (tab[ct] != NULL)
		ct++;
	return (ct);
}

// Test if the number is an integer.
int	is_not_int(char *nb)
{
	long	tmp;
	int		ct;

	ct = 0;
	tmp = 0;
	if (nb == NULL || *nb == 0)
		return (1);
	if (nb[0] == '-')
		ct++;
	while (nb[ct])
	{
		if (nb[ct] < 48 || nb[ct] > 57)
			return (1);
		tmp *= 10;
		tmp += nb[ct] - 48;
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

// Convert a number (string format) to a number (int).
int	ft_atoi(char *s)
{
	long	nb;
	int		ct;

	nb = 0;
	ct = 0;
	if (s[ct] == '+' || s[ct] == '-')
		ct++;
	while (s[ct])
		nb = 10 * nb + s[ct++] - 48;
	if (s[0] == '-')
		nb = -nb;
	return ((int)(nb));
}

// Check if the input has the appropriate format.
int	input_is_invalid(char *argv)
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
}

// Returns a new stack made of the list of integer given.
t_array	*parse(char *argv)
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
}
