/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:21:42 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:21:42 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!*from)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

void	pa(t_ps *ps)
{
	push(&ps->b, &ps->a);
	ps->count.pa++;
	if (!ps->silent)
		write(1, "pa\n", 3);
}

void	pb(t_ps *ps)
{
	push(&ps->a, &ps->b);
	ps->count.pb++;
	if (!ps->silent)
		write(1, "pb\n", 3);
}
