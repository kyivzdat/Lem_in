/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:44:53 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/12 20:17:04 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putmin(int n)
{
	if (n == 2147483648 * (-1))
	{
		ft_putchar('-');
		ft_putchar('2');
		return (147483648);
	}
	return (n);
}

void		ft_putnbr(int n)
{
	long long	div;
	int			i;
	char		rez;

	i = 1;
	div = 1;
	n = ft_putmin(n);
	while (n / (div * 10) != 0)
	{
		div *= 10;
		i++;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= (-1);
	}
	while (i-- > 0)
	{
		rez = n / div % 10 + '0';
		write(1, &rez, 1);
		div /= 10;
	}
}
