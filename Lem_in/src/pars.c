/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:26:47 by vpozniak          #+#    #+#             */
/*   Updated: 2019/06/12 14:26:49 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		check_coords(t_room *room)
{
	int i;

	i = -1;
	while (++i < g_graph->len)
	{
		if ((g_graph->rooms[i]->cor[0] == room->cor[0] &&
		g_graph->rooms[i]->cor[1] == room->cor[1])
			|| ft_strcmp(g_graph->rooms[i]->name, room->name) == 0)
			return (0);
	}
	return (1);
}

void	add_room(char **arr)
{
	t_room *room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	valid_cor(arr[1]);
	valid_cor(arr[2]);
	room->name = ft_strdup(arr[0]);
	room->cor[0] = ft_atoi(arr[1]);
	room->cor[1] = ft_atoi(arr[2]);
	room->links = ad_m(4);
	if (!check_coords(room))
		error("ERROR");
	if (g_start_point && !g_start)
		g_start = room;
	else if (g_end_point && !g_end)
		g_end = room;
	g_start_point = 0;
	g_end_point = 0;
	ft_free(arr, 2);
	add_mas(g_graph, room);
}

void	add_link(char **arr)
{
	t_room	*first_room;
	t_room	*next_room;

	first_room = NULL;
	next_room = NULL;
	arr[0] == NULL ? error("ERROR") : 0;
	arr[1] == NULL ? error("ERROR") : 0;
	if (!find_room(arr[0]))
		error("ERROR");
	if (!find_room(arr[1]))
		error("ERROR");
	if (find_room(arr[1]) != NULL && find_room(arr[0]) != NULL)
	{
		first_room = find_room(arr[0]);
		next_room = find_room(arr[1]);
	}
	first_room == next_room ? error("ERROR") : 0;
	add_mas(first_room->links, next_room);
	add_mas(next_room->links, first_room);
	ft_free(arr, 1);
}

void	check_line(char *line)
{
	if (ft_int(ft_atoi(line)) == ft_strlen(line))
		g_col = ft_atoi(line);
	*line != '#' && (!g_col || g_col > 1000000 ||
	g_col < -1000000) ? error("ERROR") : 0;
	if (*line == '#')
		if (line[1] == '#')
		{
			if (!ft_strcmp(line, "##start"))
			{
				g_start_point = 1;
				g_i++;
			}
			else if (!ft_strcmp(line, "##end"))
			{
				g_end_point = 1;
				g_i++;
			}
		}
	line[0] != '#' && check_sym(line, ' ') > 2 ? error("ERROR") : 0;
	if (check_sym(line, ' ') == 2)
		add_room(ft_strsplit(line, ' '));
	line[0] != '#' && check_sym(line, '-') > 1 ? error("ERROR") : 0;
	if (check_sym(line, '-') == 1)
		add_link(ft_strsplit(line, '-'));
}

void	pars(void)
{
	char	*line;

	line = NULL;
	g_output = ad_m(100);
	while (get_next_line(0, &line) > 0)
	{
		valid_l(line);
		check_line(line);
		add_mas(g_output, line);
	}
	!g_start || !g_end ? error("ERROR") : 0;
	!g_end->links->rooms[0] || !g_start->links->rooms[0] ? error("ERROR") : 0;
	g_i > 2 || g_i < 2 ? error("ERROR") : 0;
	if (!line)
		error("ERROR");
}
