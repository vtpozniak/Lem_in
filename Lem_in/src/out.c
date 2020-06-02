/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:26:29 by vpozniak          #+#    #+#             */
/*   Updated: 2019/06/12 14:26:30 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	print_stat(void)
{
	ft_printf("\e[1;33m%s--->%i\e[0m\n", "My statistics steps", g_num[0]);
}

void	output(void)
{
	ssize_t i;

	i = -1;
	while (++i < g_output->len)
		ft_printf("\e[1;36m%s\e[0m\n", (char*)g_output->rooms[i]);
	ft_printf("\n");
}

void	path(void)
{
	t_rooms		*put;
	int			i;
	int			j;

	i = -1;
	while (++i < g_puti->len)
	{
		ft_printf("\e[1;31mPath %d\e[0m\n", i);
		j = -1;
		put = g_puti->paths[i];
		while (++j < put->len)
			ft_printf("\e[0;32m %s\e[0m", put->rooms[j]->name);
		ft_printf("\n");
	}
}

void	print(void)
{
	int			i;
	int			j;

	i = -1;
	while (++i < g_graph->len)
	{
		j = -1;
		ft_printf("\e[01;33m%s\e[0m\n", g_graph->rooms[i]->name);
		while (++j < g_graph->rooms[i]->links->len)
			ft_printf("\e[1;32m   %s - %s\e[0m\n",
					g_graph->rooms[i]->name,
					g_graph->rooms[i]->links->rooms[j]->name);
	}
}

void	print_end(void)
{
	int			i;

	i = 0;
	while (g_col > i)
		ft_printf("\e[0;35mL%d-%s \e[0m", ++i, g_end->name);
	ft_printf("\n");
	exit(0);
}
