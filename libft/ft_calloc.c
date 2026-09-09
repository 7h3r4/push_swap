/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:19:16 by abukh             #+#    #+#             */
/*   Updated: 2026/08/19 15:22:14 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	total;

	total = nmemb * size;
	if (size && total / size != nmemb)
		return (NULL);
	mem = malloc(total);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, total);
	return (mem);
}
