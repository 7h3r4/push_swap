/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 11:19:46 by abukh             #+#    #+#             */
/*   Updated: 2026/08/22 11:52:51 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trim_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t	trim_end(char const *s1, char const *set, size_t start)
{
	size_t	end;

	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	start = trim_start(s1, set);
	end = trim_end(s1, set, start);
	len = end - start;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1 + start, len);
	new[len] = '\0';
	return (new);
}
