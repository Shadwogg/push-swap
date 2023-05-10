/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:23:11 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/10 17:20:01 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort(t_stack *a, t_stack *b);

/*void	quicksort(t_array *a, t_array *b)
{
	t_array	*left;
	t_array	*right;
	int		ind_piv;

	if (!is_sorted(a))
	{
		ind_piv = get_pivot(a);
		//piv = partition(a, b, piv);
		partition(a, ind_piv);
		left = divide(a, ind_piv);
		right = divide(b, ind_piv);
		return ;
		quicksort(a, b); //deb
		quicksort(left, right); //fin
	}
}*/

int	get_pivot(t_stack *a)
{
	int	pivot;

	pivot = 0;
	(void) a;
	return (pivot);
}
/*
// Returns the chosen pivot, in this case, the median value
int	get_pivot(t_array *arr)
{
	int		piv;

	(void) arr;
	int		ct;
	t_array	sorted;

	piv = 0;
	sorted.size = arr->size;
	sorted.arr = malloc(sorted.size * sizeof(int));
	if (sorted.arr == NULL)
		return (-1);
	ct = 0;
	while (ct < sorted.size)
	{
		
		ct++;
	}
	piv = 0;
	return (piv);
}*/
