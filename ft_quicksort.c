/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:23:11 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/13 12:25:57 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	swap_val(t_stack *stk, t_inst *inst, t_stack *el, t_stack *el2)
{
	int				tmp;
	unsigned int	tmp2;

	pre_traduction(stk, inst, el, el2);
	tmp = el->nb;
	tmp2 = el->s_ind;
	el->nb = el2->nb;
	el2->nb = tmp;
	el->s_ind = el2->s_ind;
	el2->s_ind = tmp2;
}

void	swap_pivot(t_stack *stk, unsigned int piv, t_inst *inst)
{
	unsigned int	ct;
	t_stack			*cur;
	t_stack			*false_piv;
	t_stack			*true_piv;

	ct = 0;
	cur = stk;
	false_piv = get_el(stk, piv);
	true_piv = get_el_sorted(stk, piv);
	if (false_piv == NULL || true_piv == NULL)
		print_error("", "NULL ERREUR SWAP PIVOT");
	if (true_piv != false_piv)
		swap_val(stk, inst, true_piv, false_piv);
}

// On regarde chaque element, et on les swap apres lindex du pivot.
void	swap_part_stk(t_stack *stk_a, unsigned int piv, t_inst *inst)
{
	unsigned int	ct;
	t_stack			*swapped;
	t_stack			*cur;

	cur = stk_a;
	ct = 0;
	while (ct < piv)
	{
		if (cur->s_ind > piv)
		{
			swapped = get_el(stk_a, piv);
			while (swapped != NULL && swapped->s_ind >= piv)
				swapped = swapped->next;
			swap_val(stk_a, inst, cur, swapped);
		}
		cur = cur->next;
		ct++;
	}
}*/

/**
 * 
 * Non thread safe.
 */
/*void	quicksort(t_stack *stk_a, t_inst *instructions)
{
	unsigned int	piv;
	t_stack			*right;

	if (is_sorted(stk_a))
		return ;
	//print_stack(stk_a, "\n");
	piv = get_pivot(stk_a);
	swap_pivot(stk_a, piv, instructions);
	//printf("--------------------\n");
	swap_part_stk(stk_a, piv, instructions);
	//print_stack(stk_a, "\n");
	right = divide(stk_a, piv, instructions);
	//quicksort(stk_a, instructions);
	//quicksort(right, instructions);
	//print_stack(right, "| ");
	//print_stack(stk_a, "| ");
}*/

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
