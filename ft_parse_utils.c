/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:13:26 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/08 17:33:15 by ggiboury         ###   ########.fr       */
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
