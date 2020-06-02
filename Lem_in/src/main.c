/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:26:20 by vpozniak          #+#    #+#             */
/*   Updated: 2019/06/12 14:26:22 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		main(int ac, char **av)
{
	g_graph = ad_m(50);
	pars();
	if (ac < 2)
		output();
	strakt();
	move(ac);
	if (ac == 2)
	{
		if (ft_atoi(av[1]) == 1)
			path();
		if (ft_atoi(av[1]) == 2)
			print_stat();
		if (ft_atoi(av[1]) == 3)
			print();
		if (ft_atoi(av[1]) == 4)
			system("leaks -q lem-in\n");
	}
	return (0);
}
