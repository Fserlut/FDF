/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:14:19 by fserlut           #+#    #+#             */
/*   Updated: 2020/01/10 17:46:02 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	algh(float x, float y, float x1, float y1, t_cords *cords)
{
	int max;
	float xstep;
	float ystep;

	rotate_cords(&x, &y, &x1, &y1, cords);
	xstep = x1 - x;
	ystep = y1 - y;
	max = MAX(MOD(xstep), MOD(ystep));
	xstep /= max;
	ystep /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		
		mlx_pixel_put(cords->mlx_ptr, cords->win_ptr, x, y, cords->color);
		x += xstep;
		y += ystep;
	}
}

void	rotate_cords(float *x, float *y, float *x1, float *y1, t_cords *cords)
{
	int z;
	int z1;

	z = cords->map[(int)*y][(int)*x];
	z1 = cords->map[(int)*y1][(int)*x1];
	cords->color = (z || z1) ? 0xe80c0c : 0xffffff;
	set_zoom(x, x1, y, y1, cords);
	isometric(x, y, z);
	isometric(x1, y1, z1);
	shift(x, x1, y, y1, cords);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.9);
	*y = (*x + *y) * sin(0.9) - z;
}

void	shift(float *x, float *x1, float *y, float *y1, t_cords *cords)
{
	*x += cords->move_x;
	*x1 += cords->move_x;
	*y += cords->move_y;
	*y1 += cords->move_y; 
}

void	set_zoom(float *x, float *y, float *x1, float *y1, t_cords *cords)
{
	*x *= cords->zoom;
	*x1 *= cords->zoom;
	*y *= cords->zoom;
	*y1 *= cords->zoom;
}

void	draw(t_cords *cords)
{
	int x;
	int y;

	y = 0;
	while (y < cords->height)
	{
		x = 0;
		while (x < cords->width)
		{
			if (x < cords->width - 1)
				algh(x, y, x + 1, y, cords);
			if (y < cords->height - 1)
				algh(x, y, x, y + 1, cords);
			x++;
		}
		y++;
	}
}