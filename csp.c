/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:54:36 by ggiboury          #+#    #+#             */
/*   Updated: 2023/06/22 18:58:28 by ggiboury         ###   ########.fr       */
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

t_state	*new_state(t_state *cur, char *action)
{
	t_state	*new;
	t_inst	*tmp;
	t_stack	*tmp2;
	t_stack	*tmp3;

	new = malloc(sizeof(t_state));
	if (new == NULL)
		print_error("", "Malloc error");
	tmp = cp_inst(cur->inst);
	new->inst = tmp;
	tmp2 = cp_stack(cur->s_a);
	new->s_a = tmp2;
	tmp3 = cp_stack(cur->s_b);
	new->s_b = tmp3;
	new->cost = -1;
	new->next = NULL;
	play(new, action);
	printf("	%s\n", new->inst->str);
	return (new);
}

void	add_next_states(t_state *init_state, char **moves)
{
	unsigned int	ct;
	t_state			*next;
	t_state			*cur;

	ct = 0;
	cur = init_state;
	while (moves[ct] != NULL)
	{
		next = new_state(init_state, moves[ct]);
		printf("		%s\n", next->inst->str);
		cur->next = next;
		cur = cur->next;
		ct++;
	}
}

void	print_all(t_state *s)
{
	while (s != NULL)
	{
		printf("===========================================================\n");
		printf("Stack :\n");
		print_stack(s->s_a, " ");
		print_stack(s->s_b, " ");
		if (s->inst != NULL)
			printf("Inst :\n%s\n", s->inst->str);
		printf("Cost : %ld\n", s->cost);
		printf("===========================================================\n");
		s = s->next;
	}
}

t_state	*mon_algo(t_state *cur)
{
	t_state			*s;
	// t_state			*next;
	char			**moves;
	unsigned int	ct;

	if (is_sorted(cur->s_a, 0) && cur->s_a == NULL)
		return (cur);
	moves = get_moves(cur);
	s = NULL;
	ct = 0;
	//print_moves(moves);
	add_next_states(cur, moves);
	free(moves);
	print_all(cur);
	printf("States !!!!!\n");
	return (s);
}

/*

Plan : 

	CSP : Contraint Satisfaction Planification

	On explore l'arbre des possibles, en essayant de trouver l'arbre de la
	solution, sans faire trop de detours.








*/