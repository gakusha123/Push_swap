/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheveny <btheveny@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:28:47 by btheveny          #+#    #+#             */
/*   Updated: 2026/03/02 19:07:06 by btheveny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	safe_malloc(char **split_string, int position, size_t buffer)
{
	int	i;

	split_string[position] = malloc(buffer);
	if (split_string[position] == NULL)
	{
		i = 0;
		while (i < position)
		{
			free(split_string[i]);
			i++;
		}
		free(split_string);
		return (1);
	}
	return (0);
}

static int	count_words(const char *s, char c)
{
	int	i;
	int	in_word;
	int	word_count;

	i = 0;
	in_word = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			word_count++;
			in_word = 1;
		}
		else if (s[i] == c && in_word == 1)
			in_word = 0;
		i++;
	}
	return (word_count);
}

static int	fill(char **split_string, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len > 0)
		{
			if (safe_malloc(split_string, i, len + 1))
				return (1);
			ft_strlcpy(split_string[i], s, len + 1);
			i++;
			s += len;
		}
	}
	split_string[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**split_string;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	split_string = malloc((word_count + 1) * sizeof(char *));
	if (split_string == NULL)
		return (NULL);
	if (fill(split_string, s, c))
		return (NULL);
	return (split_string);
}
