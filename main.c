/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:33:36 by fserlut           #+#    #+#             */
/*   Updated: 2019/10/26 17:16:26 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		destroy_key(int key, t_struct_mlx_win *mw)
{
	if (key == 53)
		mlx_destroy_window(mw->mlx_ptr, mw->win_ptr);
	return (0);
}

int		main()
{
	t_struct_mlx_win *m_w_struct;
	int x;
	int y;

	x = 250;
	y = 250;
	m_w_struct = (t_struct_mlx_win*)ft_memalloc(sizeof(t_struct_mlx_win));
	m_w_struct->mlx_ptr = mlx_init();
	m_w_struct->win_ptr = mlx_new_window(m_w_struct->mlx_ptr, width, height, "Fserlut");
	mlx_key_hook(m_w_struct->win_ptr, destroy_key, (void*)m_w_struct);
	while (x < width && y < height)
		mlx_pixel_put(m_w_struct->mlx_ptr, m_w_struct->win_ptr, x++, y++, 0x00FF00);
	mlx_loop(m_w_struct->mlx_ptr);
	return (0);
}
