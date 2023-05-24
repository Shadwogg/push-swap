/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:23:11 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/24 16:26:21 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_val(t_stack *stk_a, t_stack *stk_b,
	t_stack *el, t_stack *el2)
{
	int				tmp;
	unsigned int	tmp2;

	(void) stk_a;
	(void) stk_b;
	if (el == el2)
		return ;
	tmp = el->nb;
	el->nb = el2->nb;
	el2->nb = tmp;
	tmp2 = el->sorted_index;
	el->sorted_index = el2->sorted_index;
	el2->sorted_index = tmp2;
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

void	swap_pivot(t_stack *stk_a, t_stack *stk_b, unsigned int piv)
{
	unsigned int	ct;
	t_stack			*cur;
	t_stack			*swap_piv;
	t_stack			*swap_el;

	ct = 0;
	cur = stk_a;
	swap_piv = NULL;
	swap_el = NULL;
	while (cur != NULL)
	{
		if (cur->sorted_index == piv)
			swap_piv = cur;
		if (ct == piv)
			swap_el = cur;
		if (swap_piv == swap_el && swap_piv != NULL)
			return ;
		if (swap_piv != NULL && swap_el != NULL)
			break ;
		cur = cur->next;
		ct++;
	}
	swap_val(stk_a, stk_b, swap_piv, swap_el);
}

// On regarde chaque element, et on les swap apres lindex du pivot.
void	swap_part_stk(t_stack *stk_a, t_stack *stk_b, unsigned int piv)
{
	unsigned int	ct;
	t_stack			*swapped;
	t_stack			*cur;

	printf("Valeur median = %d", piv);
	cur = stk_a;
	ct = 0;
	while (ct < piv)
	{
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

	print_stack(stk_a, "\n");
	piv = get_pivot(stk_a);
	swap_pivot(stk_a, stk_b, piv);
	//swap_part_stk(stk_a, stk_b, piv);
	print_stack(stk_a, "\n");
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
