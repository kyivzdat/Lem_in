/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:26:57 by vpalamar          #+#    #+#             */
/*   Updated: 2019/07/23 21:26:58 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list_q		*sort_lq(t_list_q *lq)
{
	t_list_q	*start;
	t_queue		*q;
	int			len;

	if (!lq)
		return (NULL);
	start = lq;
	while (lq)
	{
		len = 0;
		q = lq->q;
		while (q)
		{
			len++;
			q = q->next;
		}
		lq->len = len;
		lq = lq->next;
	}
	return (start);
}

void			clear_visited(t_lst *list)
{
	list = lst_start(list);
	while (list)
	{
		list->visited = 0;
		list = list->next;
	}
}

t_queue			*free_q(t_queue *path)
{
	t_queue	*free_path;

	while (path)
	{
		free_path = path;
		path = path->next;
		free(free_path);
	}
	path = NULL;
	return (path);
}
