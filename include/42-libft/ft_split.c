/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotelho <dbotelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:17:21 by dbotelho          #+#    #+#             */
/*   Updated: 2025/11/11 12:34:28 by dbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_str(const char *start, size_t len)
{
	size_t	i;
	char	*s;

	i = 0;
	if (!start)
		return (NULL);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (i < len)
	{
		s[i] = start[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static void	free_arr(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	size_t	i;
	int		in_word;

	i = 0;
	in_word = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static size_t	word_size(const char *s, char c)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	n;
	size_t	words;

	n = 0;
	if (!s)
		return (NULL);
	words = word_count(s, c);
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (n < words)
	{
		while (*s && *s == c)
			s++;
		arr[n] = fill_str(s, word_size(s, c));
		if (!arr[n])
			return (free_arr(arr, n), NULL);
		s += word_size(s, c);
		n++;
	}
	arr[n] = NULL;
	return (arr);
}

/*int	main(void)
{
	char const	*s = NULL;
	char		c = ',';
	char		**words = ft_split(s, c);
	int			i = 0;

	if (words == NULL)
	{
		printf("ft_split returned NULL (as expected)\n");
		return (0);
	}
	for (i = 0; words[i] != NULL; i++)
	{
		printf("%s\n", words[i]);
		free(words[i]);
	}
	free(words);
	return (0);
}*/