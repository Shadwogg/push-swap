/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:42:56 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/06 20:26:33 by ggiboury         ###   ########.fr       */
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
/*
void	quicksort(t_array *a, t_array *b)
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
}

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

int	push_swap(t_stack *stk_a)
{
	t_stack	*stk_b;

	stk_b = NULL;
	print_stack(stk_a, 'l');
	//piv = get_pivot(a);
	//quicksort(a, b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stk;

	stk = NULL;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
		parse_str(argv[1], stk);
	else
		parse_strs(argc, argv, stk);
	if (is_sorted(stk))
		return (0);
	printf("On est censé accepter les inputs \"1 2 3\" mais aussi 1 2 3 ...\n");
	//printf("Parsing fini, debut du programme\n");
	//push_swap(arr);
	//system("leaks push_swap");
}
