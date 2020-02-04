/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:26:40 by vpalamar          #+#    #+#             */
/*   Updated: 2019/07/23 21:26:42 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lst	*lst_init(char *name, int x, int y, int level)
{
	t_lst	*list;

	list = (t_lst *)malloc(sizeof(t_lst));
	list->next = NULL;
	list->prev = NULL;
	list->name = ft_strdup(name);
	list->x = x;
	list->y = y;
	list->level = level;
	list->link = NULL;
	list->visited = 0;
	list->block = 0;
	return (list);
}

t_lst	*lst_add(char *name, int x, int y, int level)
{
	t_lst	*new_list;

	new_list = (t_lst *)malloc(sizeof(t_lst));
	while (g_list->next)
		g_list = g_list->next;
	new_list->next = NULL;
	new_list->prev = g_list;
	g_list->next = new_list;
	new_list->name = ft_strdup(name);
	new_list->x = x;
	new_list->y = y;
	new_list->level = level;
	new_list->link = NULL;
	new_list->visited = 0;
	new_list->block = 0;
	return (new_list);
}

t_lst	*lst_start(t_lst *list)
{
	if (!list->prev)
		return (list);
	while (list->prev)
		list = list->prev;
	return (list);
}

t_lst	*lst_find(t_lst *list, char *name)
{
	list = lst_start(list);
	if (!list->next && !ft_strcmp(list->name, name))
		return (list);
	while (list)
	{
		if (!ft_strcmp(list->name, name))
			return (list);
		list = list->next;
	}
	return (NULL);
}
