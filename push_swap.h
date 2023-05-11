/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:41:45 by ggiboury          #+#    #+#             */
/*   Updated: 2023/05/11 17:10:14 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				nb;
	unsigned int	sorted_index;
	struct s_stack	*next;
}	t_stack;

//int		arrstr_len(char **tab);
//int		get_len_arr(char *s);

/************************************PRINT*************************************/
void			print_stack(t_stack *stk, char *str);
int				print_error(char *nb, char *str);

void			stderr_print(char *s);

/************************************UTILS*************************************/
void			push(t_stack *stk_a, t_stack *stk_b);
void			reverse_rotate(t_stack *stk);
void			rotate(t_stack *stk);
void			swap(t_stack *stk);

void			insert_first(t_stack *stk, t_stack *el);
t_stack			*pop_first(t_stack *stk);
t_stack			*pop_last(t_stack *stk);

int				is_sorted(t_stack *stk);

unsigned int	get_stack_size(t_stack *stk);
t_stack			*get_last(t_stack *stk);
t_stack			*get_el(t_stack *stk, unsigned int numero);

void			free_stack(t_stack *stk);
void			free_tab_str(char **arr, int size);

/************************************PARSE*************************************/
void			parse_str(char *arg, t_stack **stk);
void			parse_strs(int size, char **argv, t_stack **stk);
t_stack			*ft_parse(int size, char **input);

void			check_input(char **argv);
void			check_double(t_stack *stk);
int				is_not_number(char *nb);
int				is_not_int(char *nb);
int				in_stack(int nb, t_stack *stk);

/************************************MAIN************************************/

void			push_swap(t_stack *stk_a);
void			quicksort(t_stack *a, t_stack *b);
unsigned int	get_pivot(t_stack *arr);

void			pre_optimization(t_stack *stk_a, t_stack *stk_b);

#endif