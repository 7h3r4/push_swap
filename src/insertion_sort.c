/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denibyko <denibyko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:18:50 by denibyko          #+#    #+#             */
/*   Updated: 2026/09/08 15:47:29 by denibyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*insertion_sort(int	*stack, size_t size_a)
{
	size_t	i;
	size_t	j;
	int		*tmp;

	i = 1;
	while (i < size_a)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (stack[i] < stack[j])
				sa();
			j--;
		}
		i++;
	}
	return ();
}
