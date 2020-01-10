/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 07:55:04 by fserlut           #+#    #+#             */
/*   Updated: 2020/01/10 17:53:13 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF__

#define __FDF__

#include <mlx.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <math.h>

#define EKEY 53

typedef struct	s_cords
{
	int **map;
	int height;
	int width;
	int zoom;
	int color;
	void *mlx_ptr;
	void *win_ptr;
	int move_x;
	int move_y;
}               t_cords;

int				make_key(int key, t_cords *mw);
int				open_file(char *name_file);
void			read_map(char *name_file, t_cords *cords);
void			algh(float x, float y, float x1, float y1, t_cords *cords);
void			draw(t_cords *cords);
void			set_zoom(float *x, float *y, float *x1, float *y1, t_cords *cords);
void			set_color(t_cords *cords, int x_cord, int y_cord, int x1_cord, int y1_cord);
void			isometric(float *x, float *y, int z);
void			shift(float *x, float *x1, float *y, float *y1, t_cords *cords);
void			rotate_cords(float *x, float *y, float *x1, float *y1, t_cords *cords);
void			move_up_key(t_cords *mw);
void			move_down_key(t_cords *mw);
void			move_right_key(t_cords *mw);
void			move_left_key(t_cords *mw);

#endif