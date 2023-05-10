/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:23:11 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/10 19:04:23 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_val(t_stack *stk_a, t_stack *stk_b,
	unsigned int ind_a, unsigned int ind_b)
{
	(void) stk_a;
	(void) stk_b;
	(void) ind_a;
	(void) ind_b;
	printf("TEST \n");
}

// On regarde chaque element, et on les swap apres lindex du pivot.
// SI un el a gauche est mal place, alors a droite aussi puisque pivot est valeur median.
//CA VA MARCHER
void	separate_stk(t_stack *stk_a, t_stack *stk_b, unsigned int piv)
{
	unsigned int	ct;
	unsigned int	ct2;
	t_stack			*swapped;

	ct = 0;
	while (ct < piv)
	{
		if (stk_a->sorted_index > piv)
		{
			//swap(stk_a, stk_b, ct, ct2);
			ct2 = ct;
			swapped = stk_a;
			while (swapped != NULL && ct2 < piv && swapped->sorted_index > piv)
			{
				swapped = swapped->next;
				ct2++;
			}
			swap_val(stk_a, stk_b, ct, ct2);
		}
		stk_a = stk_a->next;
		ct++;
	}
}

void	quicksort(t_stack *stk_a, t_stack *stk_b)
{
	unsigned int	piv;

	ft_printf("C'est a ce moment que Mom su, il s'etait viande ;");
	ft_printf(" Guigui, t'as mal compris l'algo en fait\n");
	piv = get_pivot(stk_a);
	separate_stk(stk_a, stk_b, piv);
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
