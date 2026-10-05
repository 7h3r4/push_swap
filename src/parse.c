/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:22:20 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:22:20 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	count_split(char **split, size_t *count)
{
	size_t	j;

	j = 0;
	while (split[j])
	{
		if (!ft_atoi(split[j]))
			return (0);
		(*count)++;
		j++;
	}
	return (j > 0);
}

static size_t	count_size(char **av)
{
	size_t	count;
	size_t	i;
	char	**split;

	count = 0;
	i = 0;
	while (av[i])
	{
		split = ft_split(av[i], " \t\n\v\f\r");
		if (!split)
			return (0);
		if (!count_split(split, &count))
		{
			free_split(split);
			return (0);
		}
		free_split(split);
		i++;
	}
	return (count);
}

int	init_stack(char **av, t_ps *ps)
{
	size_t	size_of_arr;
	int		*numbers;

	size_of_arr = count_size(av);
	if (!size_of_arr)
		return (0);
	if (!process_arr(av, &numbers, size_of_arr))
		return (0);
	ps->disorder = compute_disorder(numbers, size_of_arr);
	ps->a = create_stack(numbers, size_of_arr);
	free(numbers);
	if (!ps->a)
		return (0);
	set_indexes(ps->a);
	return (1);
}
