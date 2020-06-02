/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strakt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:26:17 by vpozniak          #+#    #+#             */
/*   Updated: 2019/06/12 15:26:18 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	dellvizi(void)
{
	ssize_t		i;

	i = -1;
	while (++i < g_graph->len)
	{
		g_graph->rooms[i]->visit = 0;
		g_graph->rooms[i]->relatives = NULL;
	}
}

void	add_way(t_room *room)
{
	t_rooms		*way;

	way = ad_m(1);
	if (!(ft_strcmp(room->relatives->name, g_end->name)))
		print_end();
	room = room->relatives;
	while (room != g_end)
	{
		add_mas(way, room);
		room->bizi = 1;
		room = room->relatives;
	}
	add_mas(g_puti, way);
}

void	way(t_room *room)
{
	ssize_t		i;

	i = -1;
	room->visit = 1;
	while (++i < room->links->len)
	{
		if (room->links->rooms[i]->visit != 1 &&
		room->links->rooms[i]->bizi != 1 &&
		!room->links->rooms[i]->relatives)
		{
			room->links->rooms[i]->relatives = room;
			add_mas(g_order, room->links->rooms[i]);
		}
	}
}

void	strakt(void)
{
	ssize_t		i;

	i = -1;
	g_order = ad_m(1);
	g_puti = ad_m(1);
	add_mas(g_order, g_end);
	while (++i < g_order->len)
	{
		if (g_order->rooms[i] != g_start)
			way(g_order->rooms[i]);
		else
		{
			add_way(g_order->rooms[i]);
			i = -1;
			while (++i < g_graph->len)
			{
				g_graph->rooms[i]->visit = 0;
				g_graph->rooms[i]->relatives = NULL;
			}
			i = -1;
			g_order->len = 1;
			add_mas(g_order, g_end);
		}
	}
}
