/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:15:34 by atahtouh          #+#    #+#             */
/*   Updated: 2024/07/11 11:07:30 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_fract(t_fractol *f)
{
    f->x = 0;
    f->y = 0;
    f->color = 0x1B998B;
    f->offset_x = -2.5;
    f->offset_y = -2.5;
    f->max_iter = 42;
    f->zoom = 100;
    // f->name = "fractal";
    
}

void init_mlx_fract(t_fractol *f)
{
    f->mlx_ptr = mlx_init();
    f->win = mlx_new_window(f->mlx_ptr,H,W,f->name);
    f->img_ptr = mlx_new_image(f->mlx_ptr,W,H);
    f->data_addr = mlx_get_data_addr(f->img_ptr,&f->bits_per_pixel,&f->size_line,&f->endian);
}

void color_pixel(t_fractol *f, int x, int y, double color)
{

   int *b;
   b = f->data_addr;
   b[(y * f->size_line / 4) + x] = color;
//    b =  ((f->data_addr) + y * f->size_line + x * (f->bits_per_pixel / 4));
//    *(int *)b = color;
}
