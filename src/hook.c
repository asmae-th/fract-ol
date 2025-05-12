/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:54:37 by atahtouh          #+#    #+#             */
/*   Updated: 2025/05/12 12:31:41 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_exit(t_fractol *f)
{
	free_funct(f);
	exit(1);
}

void	ft_change_color(t_fractol *f)
{
	static int	i;

	if (i == 0)
	{
		f->color = 0xB81212;
		i = 1;
	}
	else if (i == 1)
	{
		f->color = 0x1AB812;
		i = 2;
	}
	else if (i == 2)
	{
		f->color = 0xE7A90A;
		i = 0;
	}
}

int	funct_ptr(int x_event, t_fractol *f)
{
	if (x_event == 65307)
		ft_exit(f);
	if (x_event == 65361)
		f->offset_x += 0.1;
	if (x_event == 65362)
		f->offset_y += 0.1;
	if (x_event == 65363)
		f->offset_x -= 0.1;
	if (x_event == 65364)
		f->offset_y -= 0.1;
	if (x_event == 65453)
		f->max_iter -= 10;
	if (x_event == 65451)
		f->max_iter += 10;
	if (x_event == 99)
		ft_change_color(f);
	draw_fractal(f);
	return (0);
}

int	mouse_hook(int code, int x, int y, t_fractol *f)
{
	if (code == 4 || code == 5)
		mouse_move(code, x, y, f);
	return (0);
}

int	mouse_move(int key, int x, int y, t_fractol *fract)
{
	double	mouse_re;
	double	mouse_im;
	double	new_zoom;

	mouse_re = (x - (W / 2.0)) / W / fract->zoom + fract->offset_x;
	mouse_im = (y - (H / 2.0)) / H / fract->zoom + fract->offset_y;
	if (key == 4)
		new_zoom = fract->zoom * 1.15;
	else if (key == 5)
		new_zoom = fract->zoom * 0.85;
	else
		return (0);
	if (new_zoom != fract->zoom)
	{
		fract->zoom = new_zoom;
		fract->offset_x = mouse_re
			- (x - W / 2.0) / W / fract->zoom;
		fract->offset_y = mouse_im
			- (y - H / 2.0) / W / fract->zoom;
		draw_fractal(fract);
	}
	return (0);
}
