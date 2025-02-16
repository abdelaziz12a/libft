/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:08:26 by aaboudra          #+#    #+#             */
/*   Updated: 2024/11/21 20:38:04 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freee(char **strs, int i)
{
	while (i-- > 0)
	{
		free(strs[i]);
	}
	free(strs);
}

static int	w_count(const char *str, char d)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != d && !in_word)
		{
			in_word = 1;
			count++;
		}
		else
		{
			if (*str == d)
				in_word = 0;
		}
		str++;
	}
	return (count);
}

static void	cpy(char *word, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + i] != '\0' && str[j + i] != c)
	{
		word[i] = str[j + i];
		i++;
	}
	word[i] = '\0';
}

static char	*alloc_w(char *str, char de, int *pos)
{
	char	*word;
	int		len;
	int		start;

	len = 0;
	while (str[*pos] && str[*pos] == de)
		(*pos)++;
	start = *pos;
	while (str[*pos] && str[*pos] != de)
	{
		len++;
		(*pos)++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	cpy(word, str, de, start);
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		a;
	int		b;
	int		puse;

	if (s == NULL)
		return (NULL);
	a = 0;
	puse = 0;
	b = w_count((char *)s, c);
	p = (char **) malloc((sizeof(char *) * (b + 1)));
	if (!p)
		return (NULL);
	while (a < b)
	{
		p[a] = alloc_w((char *)s, c, &puse);
		if (!p[a])
		{
			freee(p, a);
			return (NULL);
		}
		a++;
	}
	p[a] = NULL;
	return (p);
}
