/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:23:11 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/27 01:41:32 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_val(t_stack *stk_a, unsigned int deep, t_stack *el, t_stack *el2)
{
	int				tmp;
	unsigned int	tmp2;

	(void) stk_a;
	(void) deep;
	if (el == el2)
		return ;
	if (el == NULL)
		print_error("", "el null.");
	else if (el2 == NULL)
		print_error("", "el2 null.");
	tmp = el->nb;
	el->nb = el2->nb;
	el2->nb = tmp;
	tmp2 = el->sorted_index;
	el->sorted_index = el2->sorted_index;
	el2->sorted_index = tmp2;
	pre_traduction(stk_a, el, el2);
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

void	swap_pivot(t_stack *stk_a, unsigned int piv, unsigned int deep)
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
	swap_val(stk_a, deep, swap_piv, swap_el);
}

// On regarde chaque element, et on les swap apres lindex du pivot.
void	swap_part_stk(t_stack *stk_a, unsigned int piv, unsigned int deep)
{
	unsigned int	ct;
	t_stack			*swapped;
	t_stack			*cur;

	cur = stk_a;
	ct = 0;
	while (ct < piv)
	{
		if (cur->sorted_index > piv)
		{
			swapped = get_el(stk_a, piv);
			while (swapped != NULL && swapped->sorted_index >= piv)
				swapped = swapped->next;
			swap_val(stk_a, deep, cur, swapped);
		}
		cur = cur->next;
		ct++;
	}
}

/**
 * 
 * Non thread safe.
 */
void	quicksort(t_stack *stk_a, unsigned int deep)
{
	unsigned int	piv;
	t_stack			*right;

	if (is_sorted(stk_a))
		return ;
	//print_stack(stk_a, "\n");
	piv = get_pivot(stk_a);
	swap_pivot(stk_a, piv, deep);
	swap_part_stk(stk_a, piv, deep);
	//print_stack(stk_a, "\n");
	right = divide(stk_a, piv, deep);
	quicksort(stk_a, deep + 1);
	quicksort(right, deep + 1);
	print_stack(right, "| ");
	print_stack(stk_a, "| ");
}

/**
 * The pivot is the index of the median value rounded down to the integer below.
*/
unsigned int	get_pivot(t_stack *a)
{
	unsigned int	pivot;

	pivot = get_stack_size(a) / 2;
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
