/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:51:53 by vpalamar          #+#    #+#             */
/*   Updated: 2019/07/24 14:51:55 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		add_list_way(char *line, int *se, t_data *data)
{
	if (line[0] != '#' && (ft_nbwords(line, ' ') == 3))
	{
		if (parse_add_list(line, se, data))
			return (1);
	}
	else if (line[0] != '#' && ft_nbwords(line, '-') == 2)
	{
		if (*se != 0)
			return (1);
		if (parse_add_way(g_list, line, data))
			return (1);
	}
	return (0);
}

static int		first_check(char *line, t_data *data, int *se, int *marker)
{
	if (line[0] >= '0' && line[0] <= '9' && data->num_ants == -1)
	{
		def_number_ants(line, data);
		if (data->num_ants < 1)
			return (1);
	}
	else if (line[0] == '#' && line[1] == '#')
	{
		if (*se != 0)
			return (1);
		else if (!ft_strcmp("start", &line[2]))
			*se = -1;
		else if (!ft_strcmp("end", &line[2]))
			*se = -2;
		else
			return (0);
		(*marker)++;
		if (*marker > 2)
			return (1);
	}
	return (0);
}

static void		get_g_print(char *line)
{
	t_l_print	*head;
	t_l_print	*new;

	if (!g_print)
	{
		g_print = (t_l_print *)malloc(sizeof(t_l_print));
		g_print->head = g_print;
		g_print->next = NULL;
		g_print->str = ft_strdup(line);
	}
	else
	{
		head = g_print;
		while (head->next)
			head = head->next;
		new = (t_l_print *)malloc(sizeof(t_l_print));
		head->next = new;
		new->head = g_print;
		new->next = NULL;
		new->str = ft_strdup(line);
	}
}

static int		parse1(char *line, t_data *data, int *start_end, int *marker)
{
	if (!(line[0] >= '0' && line[0] <= '9') && data->num_ants == -1 &&
	(line[0] != '#' || line[0] == '\n' || !line[0]))
		return (1);
	if ((line[0] >= '0' && line[0] <= '9' && data->num_ants == -1) ||
	(line[0] == '#' && line[1] == '#'))
	{
		if (first_check(line, data, start_end, marker))
			return (1);
	}
	else if (line[0] != '#' &&
	(ft_nbwords(line, ' ') == 3 || ft_nbwords(line, '-') == 2))
	{
		if (add_list_way(line, start_end, data))
			return (1);
	}
	else if (line[0] != '#')
		return (1);
	free(line);
	return (0);
}

int				parse(t_data *data)
{
	char	*line;
	int		start_end;
	int		marker;
	int		len;

	line = NULL;
	g_list = NULL;
	marker = 0;
	start_end = 0;
	g_print = NULL;
	while ((len = get_next_line(0, &line)) > 0)
	{
		get_g_print(line);
		if (parse1(line, data, &start_end, &marker))
		{
			free(line);
			return (1);
		}
	}
	if (len <= 0 && !g_print)
		return (-1);
	if (line)
		free(line);
	return (0);
}
