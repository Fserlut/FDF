/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:49:13 by fserlut           #+#    #+#             */
/*   Updated: 2020/01/06 18:44:26 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_new_line(char **fd_save, char **line, int fd)
{
	char		*tmp;
	int			len;

	len = 0;
	while (fd_save[fd][len] != '\n' && fd_save[fd][len] != '\0')
		len++;
	if (fd_save[fd][len] == '\n')
	{
		if ((*line = ft_strsub(fd_save[fd], 0, len)) == NULL)
			return (-1);
		if ((tmp = ft_strdup(fd_save[fd] + len + 1)) == NULL)
			return (-1);
		ft_strdel(&fd_save[fd]);
		fd_save[fd] = tmp;
		if (fd_save[fd][0] == '\0')
			ft_strdel(&fd_save[fd]);
	}
	else if (fd_save[fd][len] == '\0')
	{
		if ((*line = ft_strdup(fd_save[fd])) == NULL)
			return (-1);
		ft_strdel(&fd_save[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*fd_save[10240];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			read_o;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((read_o = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_o] = '\0';
		if (fd_save[fd] == NULL)
			if ((fd_save[fd] = ft_strnew(1)) == NULL)
				return (-1);
		if ((tmp = ft_strjoin(fd_save[fd], buff)) == NULL)
			return (-1);
		ft_strdel(&fd_save[fd]);
		fd_save[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (read_o < 0)
		return (-1);
	else if (read_o == 0 && (fd_save[fd] == NULL || fd_save[fd][0] == '\0'))
		return (0);
	return (ft_new_line(fd_save, line, fd));
}
