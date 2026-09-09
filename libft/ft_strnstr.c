/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:53:45 by abukh             #+#    #+#             */
/*   Updated: 2026/08/19 13:43:32 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	inner;
	size_t	outer;

	if (!*little)
		return ((char *)big);
	outer = 0;
	while (outer < len && big[outer])
	{
		inner = 0;
		while (little[inner] && outer + inner < len
			&& big[outer + inner] == little[inner])
			inner++;
		if (!little[inner])
			return ((char *)&big[outer]);
		outer++;
	}
	return (NULL);
}
