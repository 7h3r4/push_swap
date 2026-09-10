/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukh <abukh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 12:18:30 by abukh             #+#    #+#             */
/*   Updated: 2026/09/10 15:27:09 by abukh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i])
			words++;
		while (str[i] && !is_sep(str[i], charset))
			i++;
	}
	return (words);
}

static char	*word_dup(char *str, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**free_all(char **tab, int j)
{
	while (j > 0)
	{
		j--;
		free(tab[j]);
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		len;
	int		j;

	tab = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!tab)
		return (NULL);
	j = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		len = 0;
		while (str[len] && !is_sep(str[len], charset))
			len++;
		if (len == 0)
			break ;
		tab[j] = word_dup(str, len);
		if (!tab[j])
			return (free_all(tab, j));
		str += len;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
