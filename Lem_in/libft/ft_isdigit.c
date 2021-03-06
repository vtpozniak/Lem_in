/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:40:47 by vpozniak          #+#    #+#             */
/*   Updated: 2018/10/30 13:23:15 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int s)
{
	if (s >= 0 && s <= 9)
		return (1);
	return (0);
}
