/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:04:05 by atahtouh          #+#    #+#             */
/*   Updated: 2024/07/10 21:19:56 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot(t_fractol *f)
{
    int i;
    double tmp;
    f->name = "mandel";
    f->zx = 0.0;
    f->zy = 0.0;
    i = 0;
    f->cx = (f->x / f->zoom )+ f->offset_x;
    f->cy = (f->y / f->zoom) + f->offset_y;
    while (i < f->max_iter)
    {
        tmp = f->zx * f->zx - f->zy * f->zy + f->cx;
        f->zy = 2. * f->zx * f->zy + f->cy;
        f->zx = tmp;
        if(f->zx * f->zx + f->zy * f->zy >= 4.0)
            break;
        i++;
    }
    if(i == f->max_iter)
        color_pixel(f,f->x,f->y,0x2596be);//bleu
    else
         color_pixel(f,f->x,f->y,0xF8F9F8 );//orange
}