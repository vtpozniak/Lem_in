/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:56:44 by vpozniak          #+#    #+#             */
/*   Updated: 2018/11/28 18:16:20 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	view_end(char **s, char **line, int r, int fd)
{
	size_t	i;
	char	*t;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i])
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		t = ft_strdup(&s[fd][i + 1]);
		free(s[fd]);
		s[fd] = t;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][i] == '\0')
	{
		if (r == BUFF_SIZE)
			get_next_line(fd, line);
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[4864];
	char		buf[BUFF_SIZE + 1];
	char		*t;
	int			r;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (s[fd] == NULL)
		s[fd] = ft_strnew(1);
	while (ft_strchr(s[fd], '\n') == NULL && (r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		t = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = t;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (r == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	view_end(s, line, r, fd);
	return (1);
}
