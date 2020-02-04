/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:26:28 by vpalamar          #+#    #+#             */
/*   Updated: 2019/07/23 21:26:34 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_queue	*reverse(t_queue *final_path)
{
	t_queue	*sort;
	t_queue	*free_path;

	free_path = final_path;
	while ((sort = NULL) == NULL && final_path->next)
		final_path = final_path->next;
	while (final_path)
	{
		if (!sort)
			sort = q_init(final_path->point);
		else
			q_add(sort, final_path->point, NULL);
		final_path = final_path->prev;
	}
	free_q(free_path);
	return (sort);
}

t_queue			*block_path(t_queue *path)
{
	t_queue	*final_path;
	t_queue	*free_path;

	clear_visited(path->point);
	free_path = path;
	while (path->next)
		path = path->next;
	final_path = q_init(path->point);
	path = path->parent;
	while (path->parent)
	{
		q_add(final_path, path->point, NULL);
		if (path->point->level != -1 || path->point->level != -2)
			path->point->block = 1;
		path = path->parent;
	}
	free_q(free_path);
	return (reverse(final_path));
}

t_queue			*get_path(t_lst *list)
{
	t_way		*w;
	t_queue		*path;
	t_queue		*start;

	path = q_init(list);
	start = path;
	list->visited = 1;
	while (path)
	{
		w = path->point->link;
		while (w)
		{
			if (!w->point->visited && !w->point->block)
			{
				q_add(path, w->point, path);
				if ((w->point->visited = 1) == 1 && w->point->level == -2)
					return (block_path(start));
			}
			w = w->next;
		}
		path = path->next;
	}
	free_q(start);
	clear_visited(list);
	return (NULL);
}

int				list_path(t_lst *list)
{
	t_queue	*path;

	while (list)
	{
		if (list->level == -1)
			break ;
		list = list->next;
	}
	if ((g_lq = NULL) == NULL && !list)
		return (1);
	while (1)
	{
		path = NULL;
		path = get_path(list);
		if (path)
		{
			if (!g_lq)
				g_lq = list_q_init(path);
			else
				list_q_add(g_lq, path);
		}
		else
			break ;
	}
	return (0);
}
