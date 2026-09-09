/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denibyko <denibyko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:24:30 by denibyko          #+#    #+#             */
/*   Updated: 2026/09/08 18:35:31 by denibyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_overflow(long nb, int sign)
{
	if (sign == 1 && nb > INT_MAX)
		return (0);
	if (sign == -1 && nb > -(long)INT_MIN)
		return (0);
	return (1);
}

int ft_atoi(const char *nptr, int *result)
{
	int sign;
	long nb;

	sign = 1;
	nb = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	if (!(*nptr >= '0' && *nptr <= '9'))
		return (0);
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = (nb * 10) + (*nptr - '0');
		nptr++;
		if (!check_overflow(nb, sign))
			return (0);
	}
	*result = (int)(nb * sign);
	return (1);
}

int	main(void)
{
	int	nb;

	nb = 42;
	printf("%d\n", ft_atoi("2147483647", &nb));
	printf("%d", nb);
}
