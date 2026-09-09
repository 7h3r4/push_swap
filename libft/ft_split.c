/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 12:18:30 by abukh             #+#    #+#             */
/*   Updated: 2026/08/22 13:06:11 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char **arr, size_t j)
{
	while (j--)
		free(arr[j]);
	free(arr);
	return (NULL);
}

static size_t	count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

static char	*fill_word(char const *word, char delim)
{
	char	*new;
	size_t	i;

	i = 0;
	while (word[i] && word[i] != delim)
		i++;
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	new[i] = '\0';
	while (i--)
		new[i] = word[i];
	return (new);
}

static char	**fill_arr(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			arr[j] = fill_word(&s[i], c);
			if (!arr[j])
				return (free_all(arr, j));
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (fill_arr(arr, s, c));
}
