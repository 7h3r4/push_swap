/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:22:57 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:22:57 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps *ps)
{
	int	first;
	int	second;
	int	third;

	first = ps->a->val;
	second = ps->a->next->val;
	third = ps->a->next->next->val;
	if (first > second && second < third && first < third)
		sa(ps);
	else if (first > second && second > third)
	{
		sa(ps);
		rra(ps);
	}
	else if (first > second && second < third && first > third)
		ra(ps);
	else if (first < second && second > third && first < third)
	{
		sa(ps);
		ra(ps);
	}
	else if (first < second && second > third && first > third)
		rra(ps);
}

void	sort_five(t_ps *ps)
{
	while (stack_size(ps->a) > 3)
	{
		rotate_a_to_top(ps, find_min_index(ps->a));
		pb(ps);
	}
	if (!is_sorted(ps->a))
		sort_three(ps);
	while (ps->b)
		pa(ps);
}
