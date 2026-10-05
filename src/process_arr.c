/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denibyko <denibyko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 17:00:11 by denibyko          #+#    #+#             */
/*   Updated: 2026/09/12 09:27:28 by denibyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	is_duplicate(int *numbers, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	fill_split(char **split, int *numbers, size_t *k)
{
	size_t	j;

	j = 0;
	while (split[j])
	{
		if (!ft_atoi_parse(split[j], &numbers[*k]))
			return (0);
		(*k)++;
		j++;
	}
	return (1);
}

static int	fill_numbers(char **av, int *numbers)
{
	size_t	i;
	size_t	k;
	char	**split;

	i = 0;
	k = 0;
	while (av[i])
	{
		split = ft_split(av[i], " \t\n\v\f\r");
		if (!split)
			return (0);
		if (!fill_split(split, numbers, &k))
		{
			free_split(split);
			return (0);
		}
		free_split(split);
		i++;
	}
	return (1);
}

int	process_arr(char **av, int **numbers, size_t size_of_arr)
{
	*numbers = malloc(sizeof(int) * size_of_arr);
	if (!*numbers)
		return (0);
	if (!fill_numbers(av, *numbers))
	{
		free(*numbers);
		*numbers = NULL;
		return (0);
	}
	if (is_duplicate(*numbers, size_of_arr))
	{
		free(*numbers);
		*numbers = NULL;
		return (0);
	}
	return (1);
}
