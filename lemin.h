/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:29:21 by vpalamar          #+#    #+#             */
/*   Updated: 2019/07/23 21:29:23 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_way
{
	char			*neighbor;
	struct s_lst	*point;
	struct s_lst	*input_point;
	struct s_way	*next;
	struct s_way	*prev;
}					t_way;

typedef struct		s_lst
{
	char			*name;
	int				x;
	int				y;
	int				level;
	int				visited;
	int				block;
	struct s_way	*link;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_queue
{
	struct s_lst	*point;
	struct s_queue	*parent;
	struct s_queue	*next;
	struct s_queue	*prev;
	int				ant;
}					t_queue;

typedef	struct		s_list_q
{
	struct s_queue	*q;
	struct s_list_q	*next;
	struct s_list_q	*prev;
	int				fork;
	int				len;
}					t_list_q;

typedef struct		s_l_print
{
	char				*str;
	struct s_l_print	*head;
	struct s_l_print	*next;
}					t_l_print;

typedef struct		s_data
{
	int		num_ants;
}					t_data;

t_lst				*lst_init(char *name, int x, int y, int start_end);
t_lst				*lst_add(char *name, int x, int y, int start_end);
t_lst				*lst_start(t_lst *list);
t_lst				*lst_find(t_lst *list, char *name);

t_way				*way_init(t_lst *input_point, t_lst *list, char *neighbor);
t_way				*way_add(t_way *way, t_lst *ip, t_lst *lst, char *neighbor);

int					parse(t_data *data);
int					check_valid_link(t_lst *list, char *line);
void				def_number_ants(char *line, t_data *data);
int					chk(t_lst *list, char *name, int x, int y);
int					parse_add_way(t_lst *list, char *l, t_data *data);
int					parse_add_list(char *l, int *se, t_data *d);

void				def_number_ants(char *line, t_data *data);

int					list_path(t_lst *list);

int					print_output(t_list_q *lq, t_data *data, int ac, char **av);

void				way_delete(t_way *way);
void				delete_point(t_lst *point);
void				list_q_print(t_list_q *lq);

t_queue				*q_init(t_lst *list);
void				q_add(t_queue *q, t_lst *list, t_queue *parent);
t_list_q			*list_q_init(t_queue *q);
void				list_q_add(t_list_q *lq, t_queue *q);
t_list_q			*sort_lq(t_list_q *lq);
t_queue				*free_q(t_queue *path);
void				clear_visited(t_lst *list);

t_lst				*g_list;
t_way				*g_way;
t_list_q			*g_lq;
t_l_print			*g_print;

#endif
