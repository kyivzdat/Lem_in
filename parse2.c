/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:47:16 by vpalamar          #+#    #+#             */
/*   Updated: 2019/07/24 16:47:18 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			check_valid_link(t_lst *list, char *line)
{
	t_way	*way;

	way = list->link;
	while (way)
	{
		if (!ft_strcmp(way->neighbor, line))
			return (1);
		way = way->next;
	}
	return (0);
}

void		def_number_ants(char *line, t_data *data)
{
	int	len;

	len = ft_strlen(line);
	if (len > 10)
		return ;
	data->num_ants = ft_atoi(line);
	len = 0;
	while (line[len])
	{
		if (!(line[len] >= '0' && line[len] <= '9'))
		{
			data->num_ants = -1;
			return ;
		}
		len++;
	}
	if (data->num_ants > 100000000)
	{
		ft_printf("Too much number of ants\n");
		data->num_ants = -1;
	}
}

int			chk(t_lst *list, char *name, int x, int y)
{
	if (!list)
		return (0);
	while (list)
	{
		if (name == list->name || (y == list->y && x == list->x))
			return (1);
		list = list->next;
	}
	return (0);
}
