/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 13:15:07 by abukh             #+#    #+#             */
/*   Updated: 2026/08/22 14:03:22 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*new;
	size_t	len;
	long	nb;

	nb = n;
	len = num_len(nb);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	new[len] = '\0';
	if (nb < 0)
	{
		new[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		new[0] = '0';
	while (nb > 0)
	{
		len--;
		new[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (new);
}
