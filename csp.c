/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:54:36 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/25 18:18:30 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_moves(char **m)
{
	unsigned int	ct;

	if (m == NULL || *m == NULL)
	{
		ft_printf("Tableau vide / NULL\n");
		return ;
	}
	ct = 0;
	while (m[ct])
	{
		ft_printf("%s ", m[ct]);
		ct++;
	}
	ft_printf("\n");
}

// 70%
unsigned int	get_number_moves(t_stack *a, t_stack *b)
{
	unsigned int	size;

	size = 0;
	if (a != NULL)
	{
		size++;
		if (a->next != NULL)
			size += 3;
	}
	if (b != NULL)
	{
		size++;
		if (b->next != NULL)
			size += 3;
	}
	return (size);
}

void	fill_move(char **tab, unsigned int size, t_stack *a, t_stack *b)
{
	unsigned int	ct;

	ct = 0;
	if (size == 0)
		return ;
	if (a != NULL)
	{
		tab[ct++] = "pb";
		if (a->next != NULL)
		{
			tab[ct++] = "sa";
			tab[ct++] = "ra";
			tab[ct++] = "rra";
		}
	}
	if (b != NULL)
	{
		tab[ct++] = "pa";
		if (b->next != NULL)
		{
			tab[ct++] = "sb";
			tab[ct++] = "rb";
			tab[ct++] = "rrb";
		}
	}
}

char	**get_moves(t_state *cur)
{
	char			**tab;
	unsigned int	size;

	size = get_number_moves(cur->s_a, cur->s_b);
	tab = malloc(sizeof(char *) * (size + 1));
	if (tab == NULL)
		print_error("", "Malloc error");
	tab[size] = NULL;
	fill_move(tab, size, cur->s_a, cur->s_b);
	return (tab);
}

void	play(t_state *s, char *action)
{
	if (action[0] == 'p')
	{
		if (action[1] == 'a')
			push_a(&(s->s_a), &(s->s_b), &(s->inst), 1);
		else if (action[1] == 'b')
			push_b(&(s->s_a), &(s->s_b), &(s->inst), 1);
	}
	else if (action[0] == 's')
	{
		if (action[1] == 'a')
			swap_a(&(s->s_a), &(s->inst), 1);
		else if (action[1] == 'b')
			swap_b(&(s->s_b), &(s->inst), 1);
	}
	else if (action[0] == 'r')
	{
		if (action[1] == 'a')
			rotate_a(&(s->s_a), &(s->inst), 1);
		else if (action[1] == 'b')
			rotate_b(&(s->s_b), &(s->inst), 1);
		else if (action[1] == 'r' && action[2] == 'a')
			reverse_rotate_a(&(s->s_a), &(s->inst), 1);
		else if (action[1] == 'r' && action[2] == 'b')
			reverse_rotate_b(&(s->s_b), &(s->inst), 1);
	}
}

unsigned int	get_pos(unsigned int nb, t_stack *s)
{
	unsigned int	ct;

	ct = 1;
	while (s != NULL && s->s_ind != nb)
	{
		ct++;
		s = s->next;
	}
	if (s == NULL)
		print_error("", "In calculate_sum : no number found.");
	return (ct);
}

unsigned long	get_shortest_way(unsigned long size, unsigned long pos_el,
	unsigned long sorted_pos, unsigned long offset)
{
	unsigned long	path;
	unsigned long	p;
	unsigned long	g;

	path = 0;
	p = sorted_pos + offset;
	g = pos_el + offset;
	// printf("%u | %u | %u |%u\n", size, pos_el, sorted_pos, offset);
	if (pos_el < sorted_pos)
	{
		p = pos_el + offset;
		g = sorted_pos + offset;
	}
	// printf("		path = %lu\n", path);
	if (g - p < (size + offset) / 2)
		path = g - p;
	else
		path = (size + offset) - (g + p);
	return (path);
}

/**
 * 
 * Je fais comme si la stack b etait pose sur la stack a dans l'ordre inverse
 * (simulate push_a(b, size(b)))
*/
unsigned long	calculate_sum(t_stack *a, t_stack *b)
{
	unsigned long	sum;
	unsigned int	ct;
	unsigned int	size_a;
	unsigned int	size_b;

	ct = 0;
	sum = 0;
	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	// printf("Somme = %lu\n", sum);
	while (ct < size_b)
	{
		sum += (unsigned long) get_shortest_way(size_b + size_a, size_b - ct,
				get_el(b, ct)->s_ind, 0);
		ct++;
	}
	// printf("Somme = %lu\n", sum);
	ct = 0;
	while (ct < size_a)
	{
		sum += (unsigned long) get_shortest_way(size_a + size_b, ct + size_b,
				get_el(a, ct)->s_ind, size_b);
		// printf("Somme = %lu\n", sum);
		ct++;
	}
	// printf("Calculated cost = %lu \n", sum);
	return (sum);
}

t_state	*new_state(t_state *cur, char *action)
{
	t_state	*new;
	t_stack	*tmp2;
	t_stack	*tmp3;

	new = malloc(sizeof(t_state));
	if (new == NULL)
		print_error("", "Malloc error");
	new->inst = cp_inst(cur->inst);
	tmp2 = cp_stack(cur->s_a);
	new->s_a = tmp2;
	tmp3 = cp_stack(cur->s_b);
	new->s_b = tmp3;
	new->next = NULL;
	play(new, action);
	new->cost = calculate_sum(new->s_a, new->s_b);
	// printf("	%s\n", new->inst->str);
	// printf("	%lu\n", new->cost);
	return (new);
}

/**
 * Add at the end of the state list the next possibles states.
*/
void	add_next_states(t_state *init_state, char **moves)
{
	unsigned int	ct;
	t_state			*next;
	t_state			*cur;

	ct = 0;
	cur = init_state;
	while (cur->next != NULL)
		cur = cur->next;
	while (moves[ct] != NULL)
	{
		next = new_state(init_state, moves[ct]);
		// printf("		%s\n", next->inst->str);
		// printf("\nTEST\nCost = %lu\n", next->cost);
		// print_stack(next->s_a, "+");
		// print_stack(next->s_b, "+");
		// read_inst(next->inst);
		// printf("SORTIE\n");
		cur->next = next;
		cur = cur->next;
		ct++;
	}
}

void	print_all(t_state *s)
{
	printf("===========================================================\n");
	while (s != NULL)
	{
		printf("Stack :\n");
		print_stack(s->s_a, " ");
		print_stack(s->s_b, " ");
		if (s->inst != NULL)
			printf("Inst :\n%s\n", s->inst->str);
		printf("Cost : %lu\n", s->cost);
		printf("===========================================================\n");
		s = s->next;
	}
}

void	remove_state(t_state **s, t_state *removed)
{
	t_state	*cur;

	cur = *s;
	if (removed == NULL)
	{
		free_state(*s);
		*s = NULL;
	}
	if (s == NULL || *s == NULL)
	{
		printf("%p %p\n", *s, removed);
		return ;
	}
	if (*s == removed)
	{
		*s = removed->next;
		free_state(removed);
		return ;
	}
	while (cur != NULL && cur->next != removed)
		cur = cur->next;
	if (cur == NULL)
		print_error("", "ERROROROROR");
	if (cur->next == removed)
	{
		cur->next = removed->next;
		// printf("HERE\n");
		removed->next = NULL;
		free_state(removed);
	}
}

t_state	*get_next_best_state(t_state *s)
{
	unsigned long	min;
	t_state			*min_state;
	t_state			*cur;

	if (s == NULL)
		print_error("", "TMTS");
	min = (unsigned long) -1;
	min_state = s;
	cur = s->next;
	while (cur != NULL)
	{
		if (cur->cost < min)
		{
			min = cur->cost;
			min_state = cur;
		}
		cur = cur->next;
	}
	if (s == min_state)
	{
		// printf("CAS BIZARRE\n");
		return (NULL);
	}
	return (min_state);
}

t_state	*mon_algo(t_state *cur, unsigned int depth)
{
	t_state			*s;
	t_state			*next_state;
	char			**moves;

	if (depth == 20 || cur == NULL)
		return (NULL);
	if (is_sorted(cur->s_a, 0) && is_sorted(cur->s_b, 1))
		return (cur);
	moves = get_moves(cur);
	s = NULL;
	add_next_states(cur, moves);
	free(moves);
	// printf("\n\n\n");
	// print_all(cur);
	while (cur != NULL && cur->next != NULL)
	{
		// printf("DEPTH = %d\n", depth);
		// print_all(cur);
		next_state = get_next_best_state(cur);
		s = mon_algo(next_state, depth + 1);
		if (s != NULL)
			return (s);
		remove_state(&cur, next_state);
	}
	return (s);
}

/*

Plan : 

	CSP : Contraint Satisfaction Planification

	On explore l'arbre des possibles, en essayant de trouver l'arbre de la
	solution, sans faire trop de detours.








*/