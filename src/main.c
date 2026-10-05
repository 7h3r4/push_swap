/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:22:20 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:22:20 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static size_t	check_flags(char **av, int *bench, int *flag)
{
	size_t	i;

	i = 0;
	*bench = 0;
	*flag = FLAG_ADAPTIVE;
	while (av[i])
	{
		if (!ft_strcmp(av[i], "--bench"))
			*bench = 1;
		else if (!ft_strcmp(av[i], "--simple"))
			*flag = FLAG_SIMPLE;
		else if (!ft_strcmp(av[i], "--medium"))
			*flag = FLAG_MEDIUM;
		else if (!ft_strcmp(av[i], "--complex"))
			*flag = FLAG_COMPLEX;
		else if (!ft_strcmp(av[i], "--adaptive"))
			*flag = FLAG_ADAPTIVE;
		else
			return (i);
		i++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	t_ps	ps;

	if (ac < 2)
		return (0);
	ft_memset(&ps, 0, sizeof(t_ps));
	av += 1 + check_flags(av + 1, &ps.bench, &ps.flag);
	if (!init_stack(av, &ps))
		return (error_message(), 1);
	sort_stack(&ps);
	if (ps.bench)
		print_bench(&ps);
	free_stack(ps.a);
	return (0);
}
