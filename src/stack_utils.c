/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:22:20 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:22:20 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_size(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

size_t	find_min_index(t_stack *stack)
{
	size_t	i;
	size_t	min_i;
	int		min_val;

	i = 0;
	min_i = 0;
	min_val = stack->val;
	while (stack)
	{
		if (stack->val < min_val)
		{
			min_val = stack->val;
			min_i = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_i);
}

size_t	find_max_index(t_stack *stack)
{
	size_t	i;
	size_t	max_i;
	int		max_val;

	i = 0;
	max_i = 0;
	max_val = stack->val;
	while (stack)
	{
		if (stack->val > max_val)
		{
			max_val = stack->val;
			max_i = i;
		}
		i++;
		stack = stack->next;
	}
	return (max_i);
}
