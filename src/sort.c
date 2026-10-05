/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:22:20 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:22:20 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to_top(t_ps *ps, size_t idx)
{
	size_t	size;

	size = stack_size(ps->a);
	if (idx <= size / 2)
	{
		while (idx > 0)
		{
			ra(ps);
			idx--;
		}
	}
	else
	{
		while (idx < size)
		{
			rra(ps);
			idx++;
		}
	}
}

void	rotate_b_to_top(t_ps *ps, size_t idx)
{
	size_t	size;

	size = stack_size(ps->b);
	if (idx <= size / 2)
	{
		while (idx > 0)
		{
			rb(ps);
			idx--;
		}
	}
	else
	{
		while (idx < size)
		{
			rrb(ps);
			idx++;
		}
	}
}

static void	set_strategy(t_ps *ps)
{
	if (ps->flag == FLAG_SIMPLE)
		ps->strategy = "Simple";
	else if (ps->flag == FLAG_MEDIUM)
		ps->strategy = "Medium";
	else if (ps->flag == FLAG_COMPLEX)
		ps->strategy = "Complex";
	else
		ps->strategy = "Adaptive";
	if (ps->flag == FLAG_SIMPLE
		|| (ps->flag == FLAG_ADAPTIVE && ps->disorder < 0.2))
		ps->complexity = "O(n^2)";
	else if (ps->flag == FLAG_MEDIUM
		|| (ps->flag == FLAG_ADAPTIVE && ps->disorder < 0.5))
		ps->complexity = "O(n√n)";
	else
		ps->complexity = "O(n log n)";
}

static void	sort_adaptive(t_ps *ps)
{
	size_t	size;

	size = stack_size(ps->a);
	if (size == 2)
		sa(ps);
	else if (size == 3)
		sort_three(ps);
	else if (size <= 5)
		sort_five(ps);
	else if (ps->disorder < 0.2)
		insertion_sort(ps);
	else if (ps->disorder < 0.5)
		chunk_sort(ps);
	else
		radix_sort(ps);
}

void	sort_stack(t_ps *ps)
{
	set_strategy(ps);
	if (is_sorted(ps->a))
		return ;
	if (ps->flag == FLAG_SIMPLE)
		insertion_sort(ps);
	else if (ps->flag == FLAG_MEDIUM)
		chunk_sort(ps);
	else if (ps->flag == FLAG_COMPLEX)
		radix_sort(ps);
	else
		sort_adaptive(ps);
}
