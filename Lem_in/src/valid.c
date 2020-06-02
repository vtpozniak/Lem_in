/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:27:03 by vpozniak          #+#    #+#             */
/*   Updated: 2019/06/12 14:27:04 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void		valid_l(char *line)
{
	if (*line == 'L')
		error("not a valid room name");
}

int			check_sym(char *line, char s)
{
	int			i;
	int			rez;

	i = 0;
	rez = 0;
	while (line[i])
		if (line[i++] == s)
			rez++;
	return (rez);
}

t_room		*find_room(char *name)
{
	ssize_t		i;

	i = -1;
	while (++i < g_graph->len)
	{
		if (!ft_strcmp(name, g_graph->rooms[i]->name))
			return (g_graph->rooms[i]);
	}
	return (NULL);
}

void		valid_cor(char *arr)
{
	int			i;

	i = 0;
	arr == NULL ? error("ERROR") : 0;
	while (arr[i])
	{
		if (arr[i] >= '0' && arr[i] <= '9')
			i++;
		else
			error("ERROR");
	}
}
