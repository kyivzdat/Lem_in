/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:23:52 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/10 16:05:11 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strmake(int n)
{
	size_t		i;
	long long	div;
	char		*str;

	i = 1;
	div = 1;
	while (n / (div * 10) != 0)
	{
		div *= 10;
		i++;
	}
	if (n < 0)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	return (str);
}

static char	*ft_strfill(char *str, int n)
{
	size_t		i;
	long long	div;
	char		*tmp;

	if (!str)
		return (NULL);
	i = 1;
	div = 1;
	while (n / (div * 10) != 0)
	{
		div *= 10;
		i++;
	}
	tmp = str;
	while (div > 0)
	{
		*str++ = n / div % 10 + '0';
		div /= 10;
	}
	*str = '\0';
	return (tmp);
}

static char	*ft_zero(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == 0)
		return (ft_zero());
	str = ft_strmake(n);
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		i = 1;
		str[0] = '-';
		if (n == -2147483648)
		{
			n = -147483648;
			str[1] = '2';
			i = 2;
		}
		n *= (-1);
	}
	ft_strfill(&str[i], n);
	return (str);
}
