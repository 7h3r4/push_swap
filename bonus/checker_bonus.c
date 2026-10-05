/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:22:57 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:22:57 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	read_line(char *line)
{
	int	i;
	int	ret;

	i = 0;
	while (i < 4)
	{
		ret = read(0, &line[i], 1);
		if (ret < 0 || (ret == 0 && i > 0))
			return (-1);
		if (ret == 0)
			return (0);
		if (line[i] == '\n')
		{
			line[i] = '\0';
			return (1);
		}
		i++;
	}
	return (-1);
}

static int	exec_rotate(t_ps *ps, char *line)
{
	if (!ft_strcmp(line, "ra"))
		ra(ps);
	else if (!ft_strcmp(line, "rb"))
		rb(ps);
	else if (!ft_strcmp(line, "rr"))
		rr(ps);
	else if (!ft_strcmp(line, "rra"))
		rra(ps);
	else if (!ft_strcmp(line, "rrb"))
		rrb(ps);
	else if (!ft_strcmp(line, "rrr"))
		rrr(ps);
	else
		return (0);
	return (1);
}

static int	exec_op(t_ps *ps, char *line)
{
	if (!ft_strcmp(line, "sa"))
		sa(ps);
	else if (!ft_strcmp(line, "sb"))
		sb(ps);
	else if (!ft_strcmp(line, "ss"))
		ss(ps);
	else if (!ft_strcmp(line, "pa"))
		pa(ps);
	else if (!ft_strcmp(line, "pb"))
		pb(ps);
	else
		return (exec_rotate(ps, line));
	return (1);
}

static int	run_checker(t_ps *ps)
{
	char	line[5];
	int		ret;

	ret = read_line(line);
	while (ret == 1)
	{
		if (!exec_op(ps, line))
			return (0);
		ret = read_line(line);
	}
	return (ret == 0);
}

int	main(int ac, char **av)
{
	t_ps	ps;

	if (ac < 2)
		return (0);
	ft_memset(&ps, 0, sizeof(t_ps));
	ps.silent = 1;
	if (!init_stack(av + 1, &ps))
		return (error_message(), 1);
	if (!run_checker(&ps))
	{
		free_stack(ps.a);
		free_stack(ps.b);
		return (error_message(), 1);
	}
	if (is_sorted(ps.a) && !ps.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(ps.a);
	free_stack(ps.b);
	return (0);
}
