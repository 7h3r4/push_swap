/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize(main).c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denibyko <denibyko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:00:07 by denibyko          #+#    #+#             */
/*   Updated: 2026/09/10 15:02:46 by denibyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_list(int ac, char **av)
{
	t_stack	*stack_a;
	int		bench;
	int		flag;
	size_t	size_of_arr;

	stack_a = NULL;
	if (ac < 2)
		return (NULL);
	av++;
	check_flags(av, &bench, &flag);
	size_of_arr = count_size(av);
	stack_a = process_arr(av);
	return (stack_a);
}
