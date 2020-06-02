/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:00:54 by vpozniak          #+#    #+#             */
/*   Updated: 2018/10/30 12:06:47 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		z;
	char	*str;

	i = -1;
	z = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		ft_strdup(s2);
	if (!s2)
		ft_strdup(s1);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[z])
	{
		str[i] = s2[z];
		i++;
		z++;
	}
	str[i] = '\0';
	return (str);
}
