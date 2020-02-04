/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:27:23 by vpalamar          #+#    #+#             */
/*   Updated: 2019/07/23 21:27:24 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			parse_add_way(t_lst *list, char *l, t_data *data)
{
	int		i;

	i = 0;
	while (l[i] != '-')
		i++;
	l[i] = '\0';
	if (!list || data->num_ants < 1 || l[0] == 'L'
	|| (list = lst_find(list, l)) == NULL || lst_find(list, &l[i + 1]) == NULL)
		return (1);
	if (!list->link)
	{
		g_way = way_init(list, lst_find(list, &l[i + 1]), &l[i + 1]);
		list->link = g_way;
	}
	else if (!check_valid_link(list, &l[i + 1]))
		way_add(list->link, list, lst_find(list, &l[i + 1]), &l[i + 1]);
	list = lst_find(list, &l[i + 1]);
	if (!list->link)
	{
		g_way = way_init(list, lst_find(list, l), l);
		list->link = g_way;
	}
	else if (!check_valid_link(list, l))
		way_add(list->link, list, lst_find(list, l), l);
	return (0);
}

static int	parse_check_coord(char *l)
{
	int	i;

	i = 0;
	while (l[i] && l[i] != ' ')
	{
		if (!(l[i] >= '0' && l[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static int	check(char *l, int j, int x, int i)
{
	if ((j > 10 || j != (int)ft_intlen(x)))
		return (1);
	if (parse_check_coord(&l[i + ft_intlen(x) + 1]))
		return (1);
	return (0);
}

int			parse_add_list(char *l, int *s, t_data *d)
{
	int		i[2];
	int		x[2];

	if (((i[0] = -1) == -1) && (l[0] == 'L' || l[0] == '-' || d->num_ants < 1))
		return (1);
	while (l[++i[0]] != ' ')
		if (((i[1] = 0) == 0) && l[i[0]] == '-')
			return (1);
	l[i[0]++] = '\0';
	if (parse_check_coord(&l[i[0]]))
		return (1);
	x[0] = ft_atoi(&l[i[0]]);
	while (l[i[0] + i[1]] && l[i[0] + i[1]] != ' ')
		i[1]++;
	if (check(l, i[1], x[0], i[0]) && (i[1] = 0) == 0)
		return (1);
	x[1] = ft_atoi(&l[i[0] + ft_intlen(x[0]) + 1]);
	i[0] += i[1] + 1;
	i[1] = 0;
	while (l[i[0] + i[1]])
		i[1]++;
	if (i[1] > 10 || i[1] != (int)ft_intlen(x[1]) || chk(g_list, l, x[0], x[1]))
		return (1);
	g_list = (!g_list) ? lst_init(l, *x, x[1], *s) : lst_add(l, *x, x[1], *s);
	return (((*s = 0) == 0) ? 0 : 1);
}
