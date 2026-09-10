/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denibyko <denibyko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:39:22 by denibyko          #+#    #+#             */
/*   Updated: 2026/09/10 15:01:50 by denibyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	check_flags(char **av, int *bench, int *flag)
{
	size_t	i;

	i = 0;
	*bench = 0;
	*flag = 0;
	while (av[i])
	{
		if (!ft_strcmp(av[i], "--bench"))
			*bench = 1;
		else if (!ft_strcmp(av[i], "--simple"))
			*flag = 1;
		else if (!ft_strcmp(av[i], "--medium"))
			*flag = 2;
		else if (!ft_strcmp(av[i], "--complex"))
			*flag = 3;
		else if (!ft_strcmp(av[i], "--adaptive"))
			*flag = 4;
		i++;
	}
}
