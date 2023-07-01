/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:42:56 by ggiboury          #+#    #+#             */
/*   Updated: 2023/07/02 00:35:46 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
*/

int	is_min(int nb, t_stack *a)
{
	while (a != NULL)
	{
		if (nb > a->nb)
			return (0);
		a = a->next;
	}
	return (1);
}

int	is_max(int nb, t_stack *a)
{
	while (a != NULL)
	{
		if (nb < a->nb)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_three(t_stack **a, t_inst **inst)
{
	if (is_sorted(*a, 0))
		return ;
	if (is_min((*a)->nb, *a))
	{
		rotate_a(a, inst, 1);
		swap_a(a, inst, 1);
		reverse_rotate_a(a, inst, 1);
	}
	else if (is_max((*a)->nb, *a)
		&& !is_min((*a)->next->nb, *a) && !is_max((*a)->next->nb, *a))
	{
		rotate_a(a, inst, 1);
		swap_a(a, inst, 1);
	}
	else if (is_max((*a)->nb, *a))
		rotate_a(a, inst, 1);
	else if (!is_max((*a)->nb, *a) && !is_min((*a)->nb, *a)
		&& is_max((*a)->next->nb, *a))
		reverse_rotate_a(a, inst, 1);
	else
		swap_a(a, inst, 1);
}

void	insert_sort(t_stack **a, t_stack **b, t_inst **inst)
{
	unsigned int	ct;

	if (b == NULL || *b == NULL)
		return ;
	ct = 0;
	while (*b != NULL)
	{
		if (ct == (*b)->s_ind)
			push_a(a, b, inst, 1);
		else if ((*b)->next != NULL && ct == (*b)->next->s_ind)
		{
			swap_b(b, inst, 1);
			push_a(a, b, inst, 1);
		}
		else
			rotate_a(a, inst, 1);
		ct++;
	}
}

void	sort_five(t_stack **a, t_stack **b, t_inst **inst)
{
	push_b(a, b, inst, 2);
	sort_three(a, inst);
	// print_stack(*a, " ");
	// print_stack(*b, " ");
	insert_sort(a, b, inst);
	if ((*a)->s_ind != 0 && (*a)->s_ind < 3)
		reverse_rotate_a(a, inst, (*a)->s_ind);
	else
		rotate_a(a, inst, (5 - (*a)->s_ind) + 1);
}

// unsigned int	get_way(unsigned int a, unsigned int b, size_t size)
// {
// 	unsigned int	min;
// 	unsigned int	max;

// 	// ft_printf("		get_way %u, %u, %u\n", a, b, size);
// 	min = a;
// 	max = b;
// 	if (a > b)
// 	{
// 		min = b;
// 		max = a;
// 	}
// 	if (max - min <= size / 2)
// 		return (max - min);
// 	return (size - max + min);
// }

// unsigned int	get_way_b(unsigned int pos, unsigned int sorted_pos,
// 	size_t s_a, size_t s_b)
// {
// 	ft_printf("		get_way_b %u, %u, %u, %u\n", pos, sorted_pos, s_a, s_b);
// 	if (pos > s_b / 2)
// 		pos = s_b - pos;
// 	if (sorted_pos > s_a / 2)
// 		sorted_pos = s_a - sorted_pos;
// 	// ft_printf("		pos = %u\n", pos);
// 	return (pos + 1 + sorted_pos);
// }

// // TOUT EST BON POUR STACK A
// unsigned int	get_pos_lowest_move(t_stack *a, t_stack *b, size_t size)
// {
// 	unsigned int	ct;
// 	unsigned int	pos;
// 	unsigned int	cost_min;
// 	unsigned int	pos_el_sorted;
// 	unsigned int	way;

// 	ct = 0;
// 	cost_min = (unsigned int) -1;
// 	// ft_printf("LOWEST\n");
// 	while (ct < size)
// 	{
// 		// ft_printf("	ct = %u\n", ct);
// 		if (ct < get_stack_size(a))
// 		{
// 			pos_el_sorted = get_el(a, ct)->s_ind;
// 			way = get_way(ct, pos_el_sorted, get_stack_size(a));
// 		}
// 		else
// 		{
// 			pos_el_sorted = get_el(b, ct - get_stack_size(a))->s_ind;
// 			way = get_way_b(ct - get_stack_size(a), pos_el_sorted, get_stack_size(a), get_stack_size(b));
// 		}
// 		// ft_printf("	way = %u\n", way);
// 		if (way < cost_min && way > 0)
// 		{
// 			pos = ct;
// 			cost_min = way;
// 		}
// 		// ft_printf("\n");
// 		ct++;
// 	}
// 	return (pos);
// }

// void	set_push(t_move **m, unsigned int pos)
// {
// 	(*m)->str[0] = 'p';
// 	if ((*m)->str[1] == 'a')
// 		(*m)->str[1] = 'b';
// 	else
// 		(*m)->str[1] = 'a';
// 	(*m)->time = pos;
// }
// void	set_move(t_move **m, unsigned int pos, size_t s_a, size_t s_b)
// {
// 	size_t	s;
// 	char	*cmd;

// 	cmd = ft_calloc(4, sizeof(char));
// 	if (cmd == NULL)
// 		print_error("", "Malloc error in set_move");
// 	ft_memset(cmd, 'a', 3 * sizeof(char));
// 	(*m)->str = cmd;
// 	// ft_printf("	MEMSETTED\n");
// 	s = s_a;
// 	if (pos > s_a)
// 	{
// 		ft_memset(cmd, 'b', 3 * sizeof(char));
// 		pos -= s_a;
// 		s = s_b;
// 	}
// 	// ft_printf("	COMPARED1\n");
// 	if (pos == 1 && pos > s_a)
// 		return (set_push(m, pos));
// 	// ft_printf("	NOT PUSHED\n");
// 	if (pos > s / 2)
// 	{
// 		(*m)->str[0] = 'r';
// 		(*m)->time = s - pos;
// 		return ;
// 	}
// 	(*m)->str[0] = 'r';
// 	(*m)->str[1] = 'r';
// 	(*m)->time = pos;
// }

// t_move	*get_next_best_move(t_stack *a, t_stack *b, size_t size)
// {
// 	unsigned int	pos;
// 	unsigned int	ct;
// 	t_move			*m;

// 	m = ft_calloc(1, sizeof(t_move));
// 	if (m == NULL)
// 		print_error("", "Malloc error");
// 	ct = 0;
// 	pos = get_pos_lowest_move(a, b, size);
// 	// ft_printf("POS = %u\n", pos);
// 	set_move(&m, pos, get_stack_size(a), get_stack_size(b));
// 	// ft_printf("Move setted\n");
// 	return (m);
// }

// void	sort_low_stack(t_stack **a, t_stack **b, t_inst **inst, size_t size)
// {
// 	t_move			*m;

// 	push_b(a, b, inst, size);
// 	while (!is_sorted(*a, 0) || a == NULL || *b != NULL)
// 	{
// 		m = get_next_best_move(*a, *b, size);
// 		ft_printf("m done %s\n", m->str);
// 		if (m->str[0] == 'p' && m->str[1] == 'a')
// 			push_a(a, b, inst, m->time);
// 		else if (m->str[0] == 'p' && m->str[1] == 'b')
// 			push_b(a, b, inst, m->time);
// 		else if (m->str[0] == 's' && m->str[1] == 'a')
// 			swap_a(a, inst, m->time);
// 		else if (m->str[0] == 's' && m->str[1] == 'b')
// 			swap_b(b, inst, m->time);
// 		else if (m->str[0] == 'r' && m->str[1] == 'a')
// 			rotate_a(a, inst, m->time);
// 		else if (m->str[0] == 'r' && m->str[1] == 'b')
// 			rotate_b(b, inst, m->time);
// 		else if (m->str[0] == 'r' && m->str[1] == 'r' && m->str[2] == 'a')
// 			reverse_rotate_a(a, inst, m->time);
// 		else if (m->str[0] == 'r' && m->str[1] == 'r' && m->str[2] == 'b')
// 			reverse_rotate_b(b, inst, m->time);
// 		free(m->str);
// 		free(m);
// 	}
// }

/**
 * The core of the program, initialize the stack_a then free the stack after
 * it is sorted. Also free the chained list of instructions after printing it.
*/
void	push_swap(t_stack *a)
{
	t_stack	*b;
	t_inst	*inst;

	b = NULL;
	inst = NULL;
	if (get_stack_size(a) == 3)
		sort_three(&a, &inst);
	else if (get_stack_size(a) == 5)
		sort_five(&a, &b, &inst);
	else
		radix_sort(&a, &b, &inst, 0);
	optimize(inst);
	read_inst(inst);
	free_inst(inst);
}

int	main(int argc, char **argv)
{
	t_stack	*stk;

	stk = NULL;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	else
		parse_strs(argc - 1, argv + 1, &stk);
	if (is_sorted(stk, 0))
	{
		free_stack(stk);
		return (0);
	}
	update_indexes(stk);
	push_swap(stk);
	free(stk);
	return (0);
}
