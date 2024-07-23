/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:04:05 by atahtouh          #+#    #+#             */
/*   Updated: 2024/07/23 12:35:56 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *f)
{
	int		i;
	double	tmp;

	f->name = "mandelbrot";
	f->zx = 0.0;
	f->zy = 0.0;
	i = 0;
	f->cx = ((f->x - (W / 2.0)) / W) / f->zoom + f->offset_x;
	f->cy = ((f->y - (H / 2.0)) / H) / f->zoom + f->offset_y;
	while (i < f->max_iter)
	{
		tmp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2. * f->zx * f->zy + f->cy;
		f->zx = tmp;
		if (f->zx * f->zx + f->zy * f->zy >= 4.0)
			break ;
		i++;
	}
	if (i == f->max_iter)
		color_pixel(f, f->x, f->y, 0x000000);
	else
		color_pixel (f, f->x, f->y, f->color * i);
}
