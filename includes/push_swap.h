/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:21:42 by abukh             #+#    #+#             */
/*   Updated: 2026/09/14 14:21:42 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define FLAG_SIMPLE 1
# define FLAG_MEDIUM 2
# define FLAG_COMPLEX 3
# define FLAG_ADAPTIVE 4

typedef struct s_stack
{
	int				val;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_count
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_count;

typedef struct s_ps
{
	t_stack	*a;
	t_stack	*b;
	t_count	count;
	int		flag;
	int		bench;
	int		silent;
	double	disorder;
	char	*strategy;
	char	*complexity;
}			t_ps;

void	error_message(void);
void	free_split(char **split);
int		init_stack(char **av, t_ps *ps);
int		process_arr(char **av, int **numbers, size_t size_of_arr);
t_stack	*create_stack(int *numbers, size_t size);
void	set_indexes(t_stack *stack);
void	free_stack(t_stack *stack);
double	compute_disorder(int *stack, size_t size_a);

size_t	stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
size_t	find_min_index(t_stack *stack);
size_t	find_max_index(t_stack *stack);
void	rotate_a_to_top(t_ps *ps, size_t idx);
void	rotate_b_to_top(t_ps *ps, size_t idx);

void	sort_stack(t_ps *ps);
void	sort_three(t_ps *ps);
void	sort_five(t_ps *ps);
void	insertion_sort(t_ps *ps);
void	chunk_sort(t_ps *ps);
void	radix_sort(t_ps *ps);
void	print_bench(t_ps *ps);

void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);
void	pa(t_ps *ps);
void	pb(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);

#endif
