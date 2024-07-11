/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:45:40 by atahtouh          #+#    #+#             */
/*   Updated: 2024/07/11 11:09:10 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia(t_fractol *f, double cx, double cy)
{
    int i;
    double tmp;
    f->name = "julia";
    f->zx = f->x / f->zoom + f->offset_x;
    f->zy = f->y / f->zoom + f->offset_y;
    f->cx = cx;
    f->cy = cy;
    i = 0;
    while (i < f->max_iter)
    {
        tmp = f->zx * f->zx - f->zy * f->zy + cx;
        f->zy = 2. * f->zx * f->zy + cy;
        f->zx = tmp;
        if(f->zx * f->zx + f->zy * f->zy >= 4.0)
            break;
        i++;
    }
    if(i == f->max_iter)
        color_pixel(f,f->x,f->y,0x000000);//bleu
    else
         color_pixel(f,f->x,f->y,f->color );//orange
}
