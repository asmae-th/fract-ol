/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:04:05 by atahtouh          #+#    #+#             */
/*   Updated: 2025/05/12 12:31:51 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_valid(char *arg)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (arg[i])
	{
		if ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == '.'
			|| arg[i] == '+' || arg[i] == '-' || arg[i] == ' ')
		{
			if (arg[i] == '.')
				j++;
			i++;
		}
		else
			return (5);
	}
	if (j > 1)
		return (0);
	return (1);
}

void	error(t_fractol *f)
{
	free(f);
	ft_put_msg(0);
	exit(1);
}
