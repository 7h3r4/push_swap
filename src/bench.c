/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:22:20 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:22:20 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	print_percent(double disorder)
{
	int	value;

	value = (int)(disorder * 10000 + 0.5);
	ft_putnbr_fd(value / 100, 2);
	write(2, ".", 1);
	if (value % 100 < 10)
		write(2, "0", 1);
	ft_putnbr_fd(value % 100, 2);
	write(2, "%\n", 2);
}

static void	print_count(char *name, int count)
{
	write(2, " ", 1);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
}

static void	print_counts(t_count *c)
{
	ft_putstr_fd("[bench]", 2);
	print_count("sa", c->sa);
	print_count("sb", c->sb);
	print_count("ss", c->ss);
	print_count("pa", c->pa);
	print_count("pb", c->pb);
	write(2, "\n[bench]", 8);
	print_count("ra", c->ra);
	print_count("rb", c->rb);
	print_count("rr", c->rr);
	print_count("rra", c->rra);
	print_count("rrb", c->rrb);
	print_count("rrr", c->rrr);
	write(2, "\n", 1);
}

void	print_bench(t_ps *ps)
{
	t_count	*c;
	int		total;

	c = &ps->count;
	total = c->sa + c->sb + c->ss + c->pa + c->pb + c->ra + c->rb + c->rr
		+ c->rra + c->rrb + c->rrr;
	ft_putstr_fd("[bench] disorder: ", 2);
	print_percent(ps->disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(ps->strategy, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(ps->complexity, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	write(2, "\n", 1);
	print_counts(c);
}
