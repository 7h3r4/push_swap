/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:21:42 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:21:42 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_ps *ps)
{
	swap(&ps->a);
	ps->count.sa++;
	if (!ps->silent)
		write(1, "sa\n", 3);
}

void	sb(t_ps *ps)
{
	swap(&ps->b);
	ps->count.sb++;
	if (!ps->silent)
		write(1, "sb\n", 3);
}

void	ss(t_ps *ps)
{
	swap(&ps->a);
	swap(&ps->b);
	ps->count.ss++;
	if (!ps->silent)
		write(1, "ss\n", 3);
}
