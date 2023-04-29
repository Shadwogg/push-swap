/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:04:25 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/10 15:46:03 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_stack(int *arr, int size, int nb)
{
	int	ct;

	ct = 0;
	while (ct < size)
	{
		if (arr[ct] == nb)
			return (1);
		ct++;
	}
	return (0);
}

int	get_len_arr(char *s)
{
	int	size;
	int	ct;

	size = 1;
	ct = 0;
	while (s[ct])
	{
		if (s[ct] == ' ')
			size++;
		ct++;
	}
	return (size);
}

int	pop_first(t_array *arr)
{
	int	val;
	int	ct;

	val = arr->arr[0];
	ct = 0;
	while (ct < arr->size - 1)
	{
		arr->arr[ct] = arr->arr[ct + 1];
		ct++;
	}
	arr->arr[ct] = 0;
	return (val);
}

void	add_first(t_array *arr, int nb)
{
	int	ct;

	if (arr->size == 0)
	{
		arr->arr[0] = nb;
		return ;
	}
	ct = arr->size;
	while (ct > 0)
	{
		arr->arr[ct] = arr->arr[ct - 1];
		ct--;
	}
	arr->arr[0] = nb;
}
