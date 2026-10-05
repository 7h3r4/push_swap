/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:22:57 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:22:57 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_chunks(int size)
{
	int	root;

	root = 0;
	while ((root + 1) * (root + 1) <= size)
		root++;
	if (root / 2 < 1)
		return (1);
	return (root / 2);
}

static void	push_chunks(t_ps *ps, int chunk_size)
{
	int	size;
	int	limit;
	int	pushed;

	size = stack_size(ps->a);
	pushed = 0;
	limit = chunk_size;
	while (pushed < size)
	{
		if (ps->a->index < limit)
		{
			pb(ps);
			pushed++;
			if (ps->b->index < limit - chunk_size / 2)
				rb(ps);
		}
		else
			ra(ps);
		if (pushed == limit)
			limit += chunk_size;
	}
}

static void	push_back(t_ps *ps)
{
	while (ps->b)
	{
		rotate_b_to_top(ps, find_max_index(ps->b));
		pa(ps);
	}
}

void	chunk_sort(t_ps *ps)
{
	int	size;
	int	chunks;
	int	chunk_size;

	size = stack_size(ps->a);
	chunks = count_chunks(size);
	chunk_size = (size + chunks - 1) / chunks;
	push_chunks(ps, chunk_size);
	push_back(ps);
}
