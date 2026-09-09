/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:54:15 by abukh             #+#    #+#             */
/*   Updated: 2026/08/19 16:11:06 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	new = malloc(len);
	if (!new)
		return (NULL);
	ft_memcpy(new, s, len);
	return (new);
}
