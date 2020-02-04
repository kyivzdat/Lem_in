/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:27:30 by vpalamar          #+#    #+#             */
/*   Updated: 2019/07/23 21:27:32 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_way	*way_init(t_lst *input_point, t_lst *list, char *neighbor)
{
	t_way	*way;

	way = (t_way *)malloc(sizeof(t_way));
	way->next = NULL;
	way->prev = NULL;
	way->neighbor = ft_strdup(neighbor);
	way->point = list;
	way->input_point = input_point;
	return (way);
}

t_way	*way_add(t_way *way, t_lst *input_point, t_lst *list, char *neighbor)
{
	t_way	*new_way;

	new_way = (t_way *)malloc(sizeof(t_way));
	while (way->next)
		way = way->next;
	new_way->next = NULL;
	new_way->prev = way;
	way->next = new_way;
	new_way->neighbor = ft_strdup(neighbor);
	new_way->point = list;
	new_way->input_point = input_point;
	return (new_way);
}
