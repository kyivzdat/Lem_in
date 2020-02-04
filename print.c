/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:26:46 by vpalamar          #+#    #+#             */
/*   Updated: 2019/07/23 21:26:47 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				print_ant(char **ant, int num_ants, int argc, char **argv)
{
	int	i;
	int	isprint;

	i = 0;
	isprint = 0;
	while (i < num_ants)
	{
		if (ant[i])
		{
			if (!(argc > 3 && !ft_strcmp(argv[3], "-output")))
			{
				if (isprint)
					ft_printf(" ");
				ft_printf("L%d-%s", i + 1, ant[i]);
			}
			isprint = 1;
		}
		i++;
	}
	if (!isprint)
		return (1);
	if (!(argc > 3 && !ft_strcmp(argv[3], "-output")))
		ft_printf("\n");
	return (0);
}

char			*find_path(t_list_q *lq, char *name)
{
	t_queue	*path;

	while (lq)
	{
		path = lq->q;
		while (path)
		{
			if (!ft_strcmp(path->point->name, name))
			{
				if (path->next)
					return (path->next->point->name);
				return (NULL);
			}
			path = path->next;
		}
		lq = lq->next;
	}
	return ("find_path!");
}

static void		def_path(t_list_q *lq, char **ant, t_data *data, int cp_ants)
{
	t_list_q	*copy_lq;
	t_list_q	*start_lq;
	int			sum;

	start_lq = lq;
	while ((sum = 0) == 0 && lq)
	{
		copy_lq = start_lq;
		while (copy_lq != lq)
		{
			sum += lq->len - copy_lq->len;
			copy_lq = copy_lq->next;
		}
		if (sum < data->num_ants && (sum = cp_ants) == cp_ants && copy_lq == lq)
		{
			while (sum > 0 && ant[sum - 1] == NULL)
				sum--;
			ant[sum] = lq->q->point->name;
			lq->q->ant = cp_ants - data->num_ants + 1;
			data->num_ants--;
		}
		else
			break ;
		lq = lq->next;
	}
}

static char		**get_arr(t_data *data)
{
	int			n_ant;
	char		**ant;

	ant = (char **)malloc(sizeof(char *) * data->num_ants);
	if (!ant)
		return (NULL);
	n_ant = 0;
	while (n_ant < data->num_ants)
	{
		ant[n_ant] = NULL;
		n_ant++;
	}
	return (ant);
}

int				print_output(t_list_q *lq, t_data *data, int argc, char **argv)
{
	int			cp_num_ants;
	int			res;
	int			i;
	char		**ant;

	ant = get_arr(data);
	cp_num_ants = data->num_ants;
	res = 0;
	while (1)
	{
		if (data->num_ants > 0)
			def_path(lq, ant, data, cp_num_ants);
		if (print_ant(ant, cp_num_ants, argc, argv))
			break ;
		i = 0;
		while (i < cp_num_ants)
		{
			if (ant[i])
				ant[i] = find_path(lq, ant[i]);
			i++;
		}
		res++;
	}
	free(ant);
	return (res);
}
