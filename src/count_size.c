/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denibyko <denibyko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:58:39 by denibyko          #+#    #+#             */
/*   Updated: 2026/09/10 15:11:45 by denibyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

size_t	count_size(char **av)
{
	size_t	count;
	char	**split;
	size_t	i;
	size_t	j;

	count = 0;
	i = 0;
	while (av[i])
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			count += ft_atoi(split[j]);
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (count);
}
