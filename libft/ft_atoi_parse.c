/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 17:02:25 by denibyko          #+#    #+#             */
/*   Updated: 2026/09/12 10:29:50 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(long nb, int sign)
{
	if (sign == 1 && nb > INT_MAX)
		return (0);
	if (sign == -1 && nb > -(long)INT_MIN)
		return (0);
	return (1);
}

static int	check_sign(const char **str, int *sign)
{
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
	if (**str < '0' || **str > '9')
		return (0);
	return (1);
}

int	ft_atoi_parse(const char *str, int *result)
{
	int		sign;
	int		digit;
	long	nb;

	sign = 1;
	nb = 0;
	if (!check_sign(&str, &sign))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		nb = nb * 10 + digit;
		if (!check_overflow(nb, sign))
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
	*result = (int)(nb * sign);
	return (1);
}
