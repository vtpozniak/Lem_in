/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:47:08 by vpozniak          #+#    #+#             */
/*   Updated: 2019/06/12 14:47:17 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		ft_start(t_rooms *path, t_room *room, int ac)
{
	while (--g_mv >= 0)
		if (path->rooms[g_mv]->ant > 0)
		{
			if (g_mv == path->len - 1)
			{
				ac < 2 ? ft_printf(P1, path->rooms[g_mv]->ant, g_end->name) : 0;
				g_col--;
			}
			else
			{
				path->rooms[g_mv + 1]->ant = path->rooms[g_mv]->ant;
				(ac < 2) ? ft_printf("\e[0;35mL%d-%s  \e[0m",
					path->rooms[g_mv]->ant, path->rooms[g_mv + 1]->name) : 0;
			}
			path->rooms[g_mv]->ant = 0;
		}
	g_mv = -1;
	while (++g_mv < g_ants_col->len)
		if (g_ants_col->rooms[g_mv] && g_ants_col->rooms[g_mv] == room)
		{
			g_ants_col->rooms[g_mv] = 0;
			room->ant = g_mv + 1;
			return ((ac < 2) ? ft_printf(P2, room->ant, room->name) : 0);
		}
	return (0);
}

void	add_antts(ssize_t *k)
{
	int i;
	int w;

	i = -1;
	w = 0;
	while (++i < g_puti->len)
	{
		if (*k > (g_puti->paths[i]->len * i - w))
		{
			add_mas(g_ants_col, g_puti->paths[i]->rooms[0]);
			(*k)--;
		}
		w += g_puti->paths[i]->len;
	}
}

void	move(int ac)
{
	ssize_t i;
	ssize_t j;
	ssize_t k;

	j = 0;
	k = g_col;
	g_ants_col = ad_m(g_col);
	while (k)
		add_antts(&k);
	while (g_col)
	{
		i = -1;
		while (++i < g_puti->len)
		{
			g_mv = g_puti->paths[i]->len;
			ft_start(g_puti->paths[i], g_puti->paths[i]->rooms[0], ac);
		}
		(ac < 2) ? ft_printf("\n") : 0;
		j++;
	}
	g_num[0] = j;
}
