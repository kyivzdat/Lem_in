/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:25:59 by vpalamar          #+#    #+#             */
/*   Updated: 2019/07/23 21:26:04 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_start_end(void)
{
	t_way	*way;
	t_queue	*q;

	g_list = lst_start(g_list);
	while (g_list)
	{
		if (g_list->level == -1)
			break ;
		g_list = g_list->next;
	}
	way = g_list->link;
	while (way)
	{
		if (way->point->level == -2)
		{
			q = q_init(way->point);
			g_lq = list_q_init(q);
			return (0);
		}
		way = way->next;
	}
	return (1);
}

static void	print_result(int i)
{
	ft_printf(BLUE);
	write(1, "RESULT = ", ft_strlen("RESULT = "));
	ft_printf("%d\n"RESET, i);
}

static void	print_map(void)
{
	t_l_print	*head;
	t_l_print	*free_tmp;

	head = g_print;
	while (head)
	{
		ft_printf(GREEN);
		write(1, head->str, ft_strlen(head->str));
		ft_printf("\n"RESET);
		head = head->next;
	}
	write(1, "\n", 1);
	head = g_print;
	while (head)
	{
		free(head->str);
		free_tmp = head;
		head = head->next;
		free(free_tmp);
	}
}

int			main(int argc, char **argv)
{
	t_data		data;
	int			i;

	data.num_ants = -1;
	if (parse(&data))
	{
		write(1, "ERROR\n", ft_strlen("ERROR\n"));
		return (0);
	}
	if (check_start_end())
		list_path(g_list);
	if (!g_lq)
	{
		write(1, "ERROR\n", ft_strlen("ERROR\n"));
		return (0);
	}
	if (!(argc > 2 && !ft_strcmp(argv[2], "-map")))
		print_map();
	g_lq = sort_lq(g_lq);
	i = print_output(g_lq, &data, argc, argv);
	if (argc > 4 && !ft_strcmp(argv[4], "-path"))
		list_q_print(g_lq);
	if (argc > 1 && !ft_strcmp(argv[1], "-result"))
		print_result(i);
	return (0);
}
