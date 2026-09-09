/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:46:07 by denibyko          #+#    #+#             */
/*   Updated: 2026/09/09 16:31:44 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int		ft_atoi(const char *nptr, int *result);
int		check_overflow(long nb, int sign);

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}					t_stack;

/*			MOVESETS			*/
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

#endif