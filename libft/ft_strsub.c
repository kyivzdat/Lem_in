/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:00:30 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/12 19:09:20 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && i < start)
		i++;
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	j = 0;
	while (len > 0)
	{
		if (!s[i + j])
			return (NULL);
		tmp[j] = s[i + j];
		j++;
		len--;
	}
	tmp[j] = '\0';
	return (tmp);
}
