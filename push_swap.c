/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:42:56 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/24 19:26:35 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
t_list	*ft_sort(t_list *a)
{
	t_list	*lst;
	int		min;

	if (a == NULL || ft_len_stack(a) == 1)
		return (a);
	min = INT_MAX;
	lst = NULL;
	while (ft_len_stack(lst) < ft_len_stack(a))
	{
		
		if ()
		{
			
		}
	}
	return (lst);
}

  *
  *
  *
  * 
3 numbers -> 2 or 3 moves
5 numbers ->   <12 moves
100 numbers:
    <700 moves = 5 pts
    <900 moves = 4 pts
    <1,100 moves = 3 pts
    <1,300 moves = 2 pts
    <1,500 moves = 1 pts
500 numbers:
    <5,500 moves = 5 pts
    <7,000 moves = 4 pts
    <8,500 moves = 3 pts
    <10,000 moves = 2 pts
    <11,500 moves = 1 pts
  * 
  *  
z
*/
/*
t_array	*divide(t_array *a, int piv)
{
	(void) a;
	(void) piv;
	return (NULL);
}*/

/**
 * Swap the elements so that each element are sorted in relative to the pivot.
 * Then, it places the pivot in the median index
*//*
void	partition(t_array *a, int ind_piv)
{
	(void) a;
	(void) ind_piv;
}*/

void	init_stack(t_stack *stk)
{
	t_stack			*cur;
	t_stack			*save;
	unsigned int	nb;

	cur = stk;
	save = stk;
	while (cur != NULL)
	{
		nb = 0;
		stk = save;
		while (stk != NULL)
		{
			if (cur->nb > stk->nb)
				nb++;
			stk = stk->next;
		}
		cur->sorted_index = nb;
		cur = cur->next;
	}
}

void	push_swap(t_stack *stk_a)
{
	t_stack	*stk_b;

	stk_b = NULL;
	init_stack(stk_a);
	print_stack(stk_a, "-> ");
	pre_optimization(stk_a, stk_b);
	quicksort(stk_a, 0);
	//print_stack(stk_a, "\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stk;

	stk = NULL;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
		parse_str(argv[1], &stk);
	else
		parse_strs(argc - 1, argv + 1, &stk);
	if (is_sorted(stk))
		return (0);
	push_swap(stk);
	//system("leaks push_swap");
}
