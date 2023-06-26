/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:54:36 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/26 16:53:19 by ggiboury         ###   ########.fr       */
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

void	pls(t_state *s)
{
	while (s != NULL)
	{
		ft_printf("%p | ", s);
		s = s->next;
	}
	ft_printf("|\n");
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

// int	has_opposite(char *inst, char **m)
// {
// 	int	ct;
// 	int	bool;

// 	bool = 0;
// 	ct = -1;
// 	while (m[++ct])
// 	{
// 		if (inst[0] == 'p' && m[ct][0] == 'p' && inst[1] != m[ct][1])
// 		{
// 			m[ct][0] = 'z';
// 			bool = 1;
// 		}
// 		if (inst[0] == 's' && m[ct][0] == 's' && m[ct][1] == inst[1])
// 		{
// 			m[ct][0] = 'z';
// 			bool = 1;
// 		}
// 		if (inst[0] == 'r' && m[ct][0] == 'r' && m[ct][1] == inst[1])
// 		{
// 			m[ct][0] = 'z';
// 			bool = 1;
// 		}
// 		if (inst[0] == 'r' && inst[1] == 'r'
// 			&& m[ct][0] == 'r' && m[ct][1] == 'r'
// 			&& inst[2] == m[ct][2])
// 		{
// 			m[ct][0] = 'z';
// 			bool = 1;
// 		}
// 	}
// 	return (bool);
// }

int	has_opposite(char *inst, char **m)
{
	int	ct;

	ct = -1;
	while (m[++ct])
	{
		if (inst[0] == 'p' && m[ct][0] == 'p' && inst[1] != m[ct][1])
			m[ct] = "zz";
		if (inst[0] == 's' && m[ct][0] == 's' && m[ct][1] == inst[1])
			m[ct] = "zz";
		if (inst[0] == 'r' && m[ct][0] == 'r' && m[ct][1] == inst[1])
			m[ct] = "zz";
		if (inst[0] == 'r' && inst[1] == 'r'
			&& m[ct][0] == 'r' && m[ct][1] == 'r'
			&& inst[2] == m[ct][2])
			m[ct] = "zzz";
	}
	ct = -1;
	while (m[++ct])
		if (m[ct][0] == 'z')
			return (1);
	return (0);
}

/**
 * Rapproche de 1 case vers la gauche pour chaque case ou y a un z
*/
void	remove_opposite(char **m)
{
	int	ct;
	int	ct2;

	ct = -1;
	while (m[++ct])
	{
		if (m[ct][0] == 'z')
		{
			ct2 = ct - 1;
			while (m[++ct2] && m[ct2 + 1])
				m[ct2] = m[ct2 + 1];
			m[ct2 + 1] = NULL;
		}
	}
}

t_inst	*get_last_inst(t_inst *inst)
{
	if (inst == NULL)
		return (NULL);
	while (inst->next != NULL)
		inst = inst->next;
	return (inst);
}

char	**opti_moves(char **moves, t_inst *inst)
{
	if (inst == NULL || inst->str == NULL || moves == NULL || *moves == NULL)
		return (moves);
	if (has_opposite(get_last_inst(inst)->str, moves))
		remove_opposite(moves);
	return (moves);
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

	new = malloc(sizeof(t_state));
	if (new == NULL)
		print_error("", "Malloc error");
	new->inst = cp_inst(cur->inst);
	new->s_a = cp_stack(cur->s_a);
	new->s_b = cp_stack(cur->s_b);
	new->next = NULL;
	new->prev = NULL;
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

	if (moves == NULL || *moves == NULL)
		print_error("", "No move allocated");
	if (init_state == NULL)
		print_error("", "Erreur in adding new states ; init_state is null");
	ct = 0;
	cur = init_state;
	while (cur->next != NULL)
		cur = cur->next;
	while (moves[ct] != NULL)
	{
		next = new_state(init_state, moves[ct]);
		next->prev = cur;
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

/**
 * Remove the wanted state from s and free it
*/
// void	remove_state(t_state **s, t_state *removed)
// {
// 	t_state	*cur;

// 	cur = *s;
// 	if (removed == NULL)
// 	{
// 		free_state(*s);
// 		*s = NULL;
// 	}
// 	if (s == NULL || *s == NULL)
// 	{
// 		// printf("%p %p\n", *s, removed);
// 		return ;
// 	}
// 	if (*s == removed)
// 	{
// 		*s = removed->next;
// 		free_state(removed);
// 		return ;
// 	}
// 	while (cur != NULL && cur->next != removed)
// 		cur = cur->next;
// 	if (cur == NULL)
// 		print_error("", "ERROROROROR");
// 	if (cur->next == removed)
// 	{
// 		cur->next = removed->next;
// 		removed->next = NULL;
// 		free_state(removed);
// 	}
// }

void	remove_state(t_state **s, t_state *removed)
{
 	t_state	*cur;

	printf("STATE REMOVING\n");
	if (removed == NULL)
		return ;
	if (s == NULL || *s == NULL)
		print_error("", "No list of state provided.");
	if (*s == removed)
	{
		//SYMPTOME DU PB ICI *s = removed->next;
		// printf("Branche du s == removed\n");
		(*s)->prev->next = removed->next;
		*s = removed->next;
		removed->next = NULL;
		free(removed);
		return ;
	}
	cur = *s;
	while (cur != NULL && cur->next != NULL && cur->next != removed)
		cur = cur->next;
	if (cur->next == removed && removed != NULL)
	{
		printf("removing\n");
		cur->next = removed->next;
		removed->next = NULL;
		free_state(removed);
	}
	else if (cur->next == NULL && cur != removed)
	{
		pls(*s);
		printf("%p\n", removed);
		print_error("", "Bouh\n");
	}
	// printf("HERE ?\n");
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
	return (min_state);
}

t_state	*mon_algo(t_state *cur, unsigned int depth)
{
	t_state			*s;
	t_state			*next_state;
	char			**moves;

	// Tester le noeud en cours
	if (depth == 100 || cur == NULL)
		return (NULL);
	if (is_sorted(cur->s_a, 0) && is_sorted(cur->s_b, 1))
		return (cur);
	// printf("depth = %d\n", depth);
	//Ajouter les nouveaux noeuds de l'arbre
	moves = opti_moves(get_moves(cur), cur->inst);
	s = NULL;
	add_next_states(cur, moves);
	free(moves);
	// printf("\n\n\n");
	// print_all(cur);
	// printf("d = %d\n", depth);
	// Parcourir les nouveaux noeuds
	while (cur != NULL && cur->next != NULL)
	{
		// printf("MON PROBLEME, C'EST QUAND BEST STATE = CUR, A REGLER (resolvable avec un attribut prev ?)\n");
		// printf("DEPTH = %d\n", depth);
		// print_all(cur);
		// pls(cur);
		printf("-------------\n");
		next_state = get_next_best_state(cur);
		s = mon_algo(next_state, depth + 1);
		if (s != NULL)
			return (s);
		remove_state(&cur, next_state);
	}
	// printf("	Return\n");
	return (s);
}

/*

Plan : 

	CSP : Contraint Satisfaction Planification

	On explore l'arbre des possibles, en essayant de trouver l'arbre de la
	solution, sans faire trop de detours.








*/