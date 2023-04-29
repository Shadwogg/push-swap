/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiboury <ggiboury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:28:25 by ggiboury          #+#    #+#             */
/*   Updated: 2023/01/28 22:40:08 by ggiboury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_tab_str(char **tab, size_t n)
{
	while (n > 0)
	{
		free(tab[n]);
		n--;
	}
	free(tab[0]);
	free(tab);
	return (NULL);
}

void	free_array(t_array *arr)
{
	free(arr->arr);
	free(arr);
}
