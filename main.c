/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:33:36 by fserlut           #+#    #+#             */
/*   Updated: 2020/01/10 17:54:03 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		make_key(int key, t_cords *mw)
{
	if (key == EKEY)
	{
		mlx_destroy_window(mw->mlx_ptr, mw->win_ptr);
		exit(0);
	}
	key == 126 ? move_up_key(mw) : 0;
	key == 125 ? move_down_key(mw) : 0;
	key == 123 ? move_left_key(mw) : 0;
	key == 124 ? move_right_key(mw) : 0;
	return (0);
}

int		main(int ac, char **av)
{
	t_cords *cords;
	int i;
	int j;

	i = 0;
	cords = (t_cords *)ft_memalloc(sizeof(t_cords));
	read_map(av[1], cords);
	cords->mlx_ptr = mlx_init();
	cords->win_ptr = mlx_new_window(cords->mlx_ptr, 1000, 1000, "FDF");
	
	cords->zoom = 20;
	draw(cords);
	mlx_key_hook(cords->win_ptr, make_key, (void*)cords);
	// mlx_mouse_hook(cords->win_ptr, mouse_key, (void*)cords);
	mlx_loop(cords->mlx_ptr);
	return (0);
}
