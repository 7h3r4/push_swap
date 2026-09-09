/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:35:49 by denibyko          #+#    #+#             */
/*   Updated: 2026/09/09 15:22:40 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(int *stack, size_t size_a)
{
	double	mistakes;
	double	total_pairs;
	size_t	i;
	size_t	j;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < size_a)
	{
		j = i + 1;
		while (j < size_a)
		{
			total_pairs++;
			if (stack[i] > stack[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}

int	main(void)
{
	double	disorder;
	int	stack[] = {1, 2, 4, -10};
	size_t	size_a = 4;

	disorder = compute_disorder(stack, size_a);
	printf("%.2f", disorder);
}
