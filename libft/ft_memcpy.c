/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 16:52:25 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/16 14:46:27 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t num)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;

	tmp2 = (unsigned char *)s;
	tmp = (unsigned char *)d;
	while (num > 0)
	{
		*tmp = *tmp2;
		tmp++;
		tmp2++;
		num--;
	}
	return (d);
}
