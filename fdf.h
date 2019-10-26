/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 07:55:04 by fserlut           #+#    #+#             */
/*   Updated: 2019/10/26 17:15:24 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF__

#define __FDF__

#include <mlx.h>
#include "libft/libft.h"
#include <math.h>

#define width 500
#define height 500

typedef struct s_struct
{
    void *mlx_ptr;
    void *win_ptr;
}               t_struct_mlx_win;


int     destroy_key(int key, t_struct_mlx_win *mw);

#endif