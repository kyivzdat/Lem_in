/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:07:26 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/04 14:53:01 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *string1, const char *string2)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	if (string2[0] == '\0')
		return ((char *)&string1[i]);
	while (string1[i])
	{
		j = 0;
		k = i;
		while (string2[j] && string1[k] == string2[j])
		{
			j++;
			k++;
		}
		if (string2[j] == '\0')
			return ((char *)&string1[k - j]);
		i++;
	}
	return (NULL);
}
