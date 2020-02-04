/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:42:49 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/03 21:38:56 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	char	*tmp;

	tmp = (char *)string;
	while (*tmp && *tmp != (char)symbol)
		tmp++;
	if (*tmp == (char)symbol)
		return (tmp);
	else
		return (NULL);
}
