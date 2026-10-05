/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:21:42 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:21:42 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	*stack = (*stack)->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_ps *ps)
{
	rotate(&ps->a);
	ps->count.ra++;
	if (!ps->silent)
		write(1, "ra\n", 3);
}

void	rb(t_ps *ps)
{
	rotate(&ps->b);
	ps->count.rb++;
	if (!ps->silent)
		write(1, "rb\n", 3);
}

void	rr(t_ps *ps)
{
	rotate(&ps->a);
	rotate(&ps->b);
	ps->count.rr++;
	if (!ps->silent)
		write(1, "rr\n", 3);
}
