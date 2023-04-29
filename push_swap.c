/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:42:56 by ggiboury          #+#    #+#             */
/*   Updated: 2023/03/22 15:19:00 by ggiboury         ###   ########.fr       */
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

int	is_sorted(t_array *arr)
{
	int	ct;
	int	prev;

	if (arr->size == 0)
		return (1);
	ct = 1;
	prev = arr->arr[0];
	while (ct < arr->size)
	{
		if (prev >= arr->arr[ct])
			return (0);
		prev = arr->arr[ct];
		ct++;
	}
	return (1);
}

t_array	*divide(t_array *a, int piv)
{
	(void) a;
	(void) piv;
	return (NULL);
}

/**
 * Swap the elements so that each element are sorted in relative to the pivot.
 * Then, it places the pivot in the median index
*/
void	partition(t_array *a, int ind_piv)
{
	(void) a;
	(void) ind_piv;
}

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
	/*int		ct;
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
	}*/
	piv = 0;
	return (piv);
}

void	print_array(t_array *tab, char format)
{
	int	ct;

	ct = 0;
	if (format == 'n')
	{
		while (ct < tab->size)
		{
			printf("%d\n", tab->arr[ct]);
			ct++;
		}	
		printf("The end\n");
	}
	else if (format == 'l')
	{
		while (ct < tab->size)
		{
			printf("%d -> ", tab->arr[ct]);
			ct++;
		}
		printf("The end\n");
	}
}

int	push_swap(t_array *a)
{
	t_array	*b;
	//int		piv;
	//t_array	*sorted;

	//rotate(&stack);
	//reverse_rotate(&stack);
	//sorted = ft_sort(a);
	b = malloc(sizeof(t_array));
	if (b == NULL)
		return (print_error("Malloc failed"));
	b->size = 0;
	b->arr = malloc(a->size * sizeof(int));
	if (b->arr == NULL)
		return (print_error("Malloc failed"));
	print_array(a, 'l');
	//piv = get_pivot(a);
	quicksort(a, b);
	free(b->arr);
	free(b);
	return (1);
}

int	parse_str(char *arg, t_array **arr)
{
	if (arg[0] == 0)
		print_error("???");
	single_input_is_invalid(arg);
	*arr = parse(arg);
	if ((*arr)->size == 1 || (*arr)->size == 0)
		return (1);
	return (0);
}

void	inputs_is_invalid(char	**argv)
{
	if (argv)
}

int	parse_strs(int size, char **argv, t_array *arr)
{
	(void) size;
	(void) arr;
	inputs_is_invalid(argv);
	return (0);
}

int	main(int argc, char **argv)
{
	t_array	*arr;
	int		is_sorted;

	arr = NULL;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
		is_sorted = parse_str(argv[1], &arr);
	else
		is_sorted = parse_strs(argc, argv, arr);
	if (is_sorted)
		return (0);
	printf("On est censé accepter les inputs \"1 2 3\" mais aussi 1 2 3 ...\n");
	//SO FAR SO GOOD
	printf("Parsing fini, debut du programme\n");
	printf("TO-DO : Divide : Renvoie une coupe de l'array\n	Question a resoudre : La gestion des piles est elle en contradiction avec ma maniere de voir et de mon usage de mes arrays ?\n");
	printf("Finalement, changer l'array de debut par une array avec 1,2,3,4,5,6,7,8,etc\n");
	push_swap(arr);
	//system("leaks push_swap");
}
