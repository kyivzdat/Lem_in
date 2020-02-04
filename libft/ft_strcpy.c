/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:06:15 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/03 21:03:01 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *destptr, const char *srcptr)
{
	char	*tmp;

	tmp = destptr;
	while (*srcptr)
	{
		*tmp = *srcptr;
		srcptr++;
		tmp++;
	}
	*tmp = '\0';
	return (destptr);
}
