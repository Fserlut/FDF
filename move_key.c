/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:53:43 by fserlut           #+#    #+#             */
/*   Updated: 2020/01/10 17:53:53 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_up_key(t_cords *mw)
{
	mlx_clear_window(mw->mlx_ptr, mw->win_ptr);
	mw->move_y -= 10;
	draw(mw);
}

void	move_down_key(t_cords *mw)
{
	mlx_clear_window(mw->mlx_ptr, mw->win_ptr);
	mw->move_y += 10;
	draw(mw);
}

void	move_left_key(t_cords *mw)
{
	mlx_clear_window(mw->mlx_ptr, mw->win_ptr);
	mw->move_x -= 10;
	draw(mw);
}

void	move_right_key(t_cords *mw)
{
	mlx_clear_window(mw->mlx_ptr, mw->win_ptr);
	mw->move_x += 10;
	draw(mw);
}