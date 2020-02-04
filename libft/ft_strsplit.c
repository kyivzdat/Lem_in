/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:11:13 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/16 17:14:22 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbword(char *s, char c)
{
	size_t	i;
	size_t	marker;

	if (!s)
		return (0);
	i = 0;
	while (*s)
	{
		marker = 0;
		while (*s && *s != c)
		{
			s++;
			marker++;
		}
		while (*s && *s == c)
			s++;
		if (marker > 0)
			i++;
	}
	return (i);
}

static int		ft_wordlen(char *s, char c)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static char		**ft(size_t nb_words, char **arr, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < nb_words)
	{
		while (*s && *s == c)
			s++;
		arr[i] = (char *)malloc(sizeof(char) * (ft_wordlen((char *)s, c) + 1));
		if (!arr[i])
			return (NULL);
		j = 0;
		while (*s && *s != c)
			arr[i][j++] = *s++;
		arr[i][j] = '\0';
		i++;
	}
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	nb_words;
	char	**arr;

	if (!s)
		return (NULL);
	nb_words = ft_nbword((char *)s, c);
	arr = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!arr)
		return (NULL);
	arr[nb_words] = NULL;
	arr = ft(nb_words, arr, s, c);
	if (!arr)
		return (NULL);
	return (arr);
}
