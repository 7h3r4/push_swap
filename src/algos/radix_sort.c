/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:22:57 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:22:57 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

static void	radix_pass(t_ps *ps, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((ps->a->index >> bit) & 1)
			ra(ps);
		else
			pb(ps);
		i++;
	}
	while (ps->b)
		pa(ps);
}

void	radix_sort(t_ps *ps)
{
	int	size;
	int	bits;
	int	bit;

	size = stack_size(ps->a);
	bits = count_bits(size);
	bit = 0;
	while (bit < bits && !is_sorted(ps->a))
	{
		radix_pass(ps, bit, size);
		bit++;
	}
}
