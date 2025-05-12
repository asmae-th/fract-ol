/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:32:56 by atahtouh          #+#    #+#             */
/*   Updated: 2025/05/12 12:31:26 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	burning_ship(t_fractol *f)
{
	int		i;
	double	x_temp;

	f->name = "ship";
	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = ((f->x - (W / 2.0)) / W)
		/ f->zoom + f->offset_x;
	f->cy = ((f->y - (H / 2.0)) / H)
		/ f->zoom + f->offset_y;
	while (i < f->max_iter)
	{
		x_temp = f->zx * f->zx - f->zy
			*f->zy + f->cx;
		f->zy = fabs(2.0 * f->zx * f->zy) + f->cy;
		f->zx = fabs(x_temp);
		if (f->zx * f->zx + f->zy * f->zy >= 4)
			break ;
		i++;
	}
	if (i == f->max_iter)
		color_pixel(f, f->x, f->y, 0x000000);
	else
		color_pixel(f, f->x, f->y, (f->color * i));
}
