/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denibyko <denibyko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:44:51 by denibyko          #+#    #+#             */
/*   Updated: 2026/09/08 18:25:14 by denibyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	fill_arr(char **av, int *stack)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (av[i])
	{
		len += ft_atoi(av[i], &stack[len]);
		i++;
	}
	return (len);
}

int	main(int ac, char **av)
{
	size_t	size_of_arr;
	int		*stack;
	size_t	check;

	if (ac < 2)
	{
		return (0);
	}
	if (av[1][0] == '-')
	{
		av = av + 2;
	}
	size_of_arr = arr_len();
	stack = malloc(sizeof(int) * size_of_arr);
	if (!stack)
		return(1);
	fill_arr(stack, av);
	check_arr();
}
