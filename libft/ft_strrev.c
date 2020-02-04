/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:32:35 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/18 14:32:39 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	len;
	size_t	i;

	if (s)
	{
		len = ft_strlen(s);
		i = 0;
		len--;
		while (len >= i)
			s = ft_swap(s, i++, len--);
		return (s);
	}
	return (NULL);
}
