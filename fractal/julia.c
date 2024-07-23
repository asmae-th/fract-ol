/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:45:40 by atahtouh          #+#    #+#             */
/*   Updated: 2024/07/22 23:30:04 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractol *f)
{
	int		i;
	double	tmp;

	f->name = "julia";
	f->zx = ((f->x - (W / 2.0)) / W) / f->zoom + f->offset_x;
	f->zy = ((f->y - (H / 2.0)) / H) / f->zoom + f->offset_y;
	f->cx = f->rj;
	f->cy = f->ij;
	i = 0;
	while (i < f->max_iter)
	{
		tmp = f->zx * f->zx - f->zy * f->zy + f->rj;
		f->zy = 2. * f->zx * f->zy + f->ij;
		f->zx = tmp;
		if (f->zx * f->zx + f->zy * f->zy >= 4.0)
			break ;
		i++;
	}
	if (i == f->max_iter)
		color_pixel(f, f->x, f->y, 0x000000);
	else
		color_pixel(f, f->x, f->y, f->color * i);
}
