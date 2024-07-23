/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:32:56 by atahtouh          #+#    #+#             */
/*   Updated: 2024/07/23 12:18:00 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship(t_fractol *fractal)
{
	int		i;
	double	x_temp;

	fractal->name = "ship";
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = ((fractal->x - (W / 2.0)) / W)
		/ fractal->zoom + fractal->offset_x;
	fractal->cy = ((fractal->y - (H / 2.0)) / H)
		/ fractal->zoom + fractal->offset_y;
	while (i < fractal->max_iter)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy
			*fractal->zy + fractal->cx;
		fractal->zy = fabs(2.0 * fractal->zx * fractal->zy) + fractal->cy;
		fractal->zx = fabs(x_temp);
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4)
			break ;
		i++;
	}
	if (i == fractal->max_iter)
		color_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		color_pixel(fractal, fractal->x, fractal->y, (fractal->color * i));
}
