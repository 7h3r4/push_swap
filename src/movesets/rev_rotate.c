/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:21:42 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:21:42 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_ps *ps)
{
	rev_rotate(&ps->a);
	ps->count.rra++;
	if (!ps->silent)
		write(1, "rra\n", 4);
}

void	rrb(t_ps *ps)
{
	rev_rotate(&ps->b);
	ps->count.rrb++;
	if (!ps->silent)
		write(1, "rrb\n", 4);
}

void	rrr(t_ps *ps)
{
	rev_rotate(&ps->a);
	rev_rotate(&ps->b);
	ps->count.rrr++;
	if (!ps->silent)
		write(1, "rrr\n", 4);
}
