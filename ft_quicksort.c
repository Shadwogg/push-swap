/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:23:11 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/11 17:11:44 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_val(t_stack *stk_a, t_stack *stk_b,
	t_stack *swapped_l, t_stack *swapped_r)
{
	(void) stk_a;
	(void) stk_b;
	(void) swapped_l;
	(void) swapped_r;
	printf("	SWAPPED \n");
}

/*t_stack	*get_next_val(t_stack *stk, unsigned int piv)
{
	unsigned int	ct;

	ct = 0;
	while (ct < piv)
		ct++;
	while ()
	{
		
	}
}*/

// On regarde chaque element, et on les swap apres lindex du pivot.
void	swap_part_stk(t_stack *stk_a, t_stack *stk_b, unsigned int piv)
{
	unsigned int	ct;
	t_stack			*swapped;
	t_stack			*cur;

	cur = stk_a;
	ct = 0;
	while (ct < piv)
	{
		printf("TEST\n");
		if (cur->sorted_index > piv)
		{
			swapped = get_el(stk_a, piv);
			while (swapped != NULL && swapped->sorted_index > piv)
				swapped = swapped->next;
			swap_val(stk_a, stk_b, cur, swapped);
		}
		cur = cur->next;
		ct++;
	}
}

void	quicksort(t_stack *stk_a, t_stack *stk_b)
{
	unsigned int	piv;

	piv = get_pivot(stk_a);
	swap_part_stk(stk_a, stk_b, piv);
}

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

/**
 * The pivot is the index of the median value rounded down to the integer below.
*/
unsigned int	get_pivot(t_stack *a)
{
	unsigned int	pivot;

	pivot = get_stack_size(a) / 2;
	printf("pivot = %d\n", pivot);
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
