/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:41:45 by ggiboury          #+#    #+#             */
/*   Updated: 2023/03/22 15:13:41 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_array
{
	int	size;
	int	*arr;
}	t_array;

void	add_first(t_array *arr, int nb);
int		arrstr_len(char **tab);
void	free_array(t_array *arr);
char	**free_tab_str(char **tab, size_t size);
int		ft_atoi(char *s);
char	**ft_split(char *s, char del);
int		get_len_arr(char *s);
int		get_pivot(t_array *arr);
int		single_input_is_invalid(char *argv);
void	inputs_is_invalid(char **argv);
int		in_stack(int *arr, int size, int nb);
int		is_not_int(char *nb);
t_array	*parse(char *argv);
int		pop_first(t_array *arr);
int		print_error(char *str);
void	push(t_array *arr_a, t_array *arr_b);
void	reverse_rotate(t_array *arr);
void	rotate(t_array *arr);
void	swap(t_array *arr);

#endif