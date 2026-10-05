/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:22:20 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:22:20 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

static int	add_node(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->val = value;
	new->index = 0;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		return (1);
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	return (1);
}

t_stack	*create_stack(int *numbers, size_t size)
{
	t_stack	*stack;
	size_t	i;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		if (!add_node(&stack, numbers[i]))
		{
			free_stack(stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}

void	set_indexes(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*other;

	cur = stack;
	while (cur)
	{
		cur->index = 0;
		other = stack;
		while (other)
		{
			if (other->val < cur->val)
				cur->index++;
			other = other->next;
		}
		cur = cur->next;
	}
}
