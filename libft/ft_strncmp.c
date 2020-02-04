/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 18:44:37 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/07 19:58:12 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	while ((*str1 && *str2 && *str1 == *str2) && num > 0)
	{
		num--;
		str1++;
		str2++;
	}
	if (num == 0)
		return (0);
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
