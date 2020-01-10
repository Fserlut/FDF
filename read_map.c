/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 04:12:19 by fserlut           #+#    #+#             */
/*   Updated: 2020/01/10 17:46:06 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				open_file(char *name_file)
{
	return (open(name_file, O_RDONLY));
}

int			check_width(char *name_file)
{
	char *line;
	int width;
	int fd;

	fd = open_file(name_file);
	get_next_line(fd, &line);
	width = ft_count_word(line, ' ');
	close(fd);
	free(line);
	return (width);
}

int				check_height(char *name_file)
{
	char *line;
	int height;
	int fd;

	height = 0;
	fd = open_file(name_file);
	while (get_next_line(fd, &line))
		height++;
	close(fd);
	return (height);
}

void		place_cord(int *cords, char *line, int width)
{
	int i;
	char **arr;

	i = 0;
	arr = ft_strsplit(line, ' ');
	while (arr[i])
	{
		cords[i] = ft_atoi(arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
}

void		read_map(char *name_file, t_cords *cords)
{
	char *line;
	int fd;
	int x;

	x = 0;
	fd = open_file(name_file);
	cords->height = check_height(name_file);
	cords->width = check_width(name_file);
	cords->map = (int**) malloc(sizeof(int) * cords->height + 1);
	while (x <= cords->height)
		cords->map[x++] = (int*)malloc(sizeof(int) * cords->width);
	x = 0;
	while (get_next_line(fd, &line))
	{
		place_cord(cords->map[x], line, cords->width);
		free(line);
		x++;
	}
	close(fd);
	cords->move_x = (1000 / 2 - cords->height);
	cords->move_y = (1000 / 2 - cords->width);
	cords->map[x] = NULL;
}
