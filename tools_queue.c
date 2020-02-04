/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:27:05 by vpalamar          #+#    #+#             */
/*   Updated: 2019/07/23 21:27:06 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_queue		*q_init(t_lst *list)
{
	t_queue		*new;

	new = (t_queue *)malloc(sizeof(t_queue));
	new->next = NULL;
	new->prev = NULL;
	new->point = list;
	new->ant = 0;
	new->parent = NULL;
	return (new);
}

void		q_add(t_queue *q, t_lst *list, t_queue *parent)
{
	t_queue	*new;

	new = (t_queue *)malloc(sizeof(t_queue));
	while (q->next)
		q = q->next;
	q->next = new;
	new->next = NULL;
	new->prev = q;
	new->point = list;
	new->ant = 0;
	new->parent = parent;
}

t_list_q	*list_q_init(t_queue *q)
{
	t_list_q	*new;

	new = (t_list_q *)malloc(sizeof(t_list_q));
	new->next = NULL;
	new->prev = NULL;
	new->q = q;
	new->fork = 0;
	new->len = 0;
	return (new);
}

void		list_q_add(t_list_q *lq, t_queue *q)
{
	t_list_q	*new;

	new = (t_list_q *)malloc(sizeof(t_list_q));
	while (lq->next)
		lq = lq->next;
	lq->next = new;
	new->next = NULL;
	new->prev = lq;
	new->q = q;
	new->fork = 0;
	new->len = 0;
}

void		list_q_print(t_list_q *lq)
{
	t_queue	*q;

	while (lq)
	{
		ft_printf(BLUE"PATH:\n\t"RESET);
		ft_printf("len = %d\n\t", lq->len);
		q = lq->q;
		while (q)
		{
			ft_printf(GREEN"%s "RESET, q->point->name);
			q = q->next;
		}
		ft_printf("\n");
		lq = lq->next;
	}
}
