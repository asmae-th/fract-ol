/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:15:34 by atahtouh          #+#    #+#             */
/*   Updated: 2025/05/12 12:31:43 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fract(t_fractol *f, char **av)
{
	f->name = av[1];
	f->x = 0;
	f->y = 0;
	f->color = 0x1C2C99;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iter = 40;
	f->zoom = 0.2;
}

void	init_mlx_fract(t_fractol *f)
{
	f->mlx_ptr = mlx_init();
	if (!f->mlx_ptr)
		free(f->mlx_ptr);
	f->win = mlx_new_window(f->mlx_ptr, H, W, f->name);
	if (!f->win)
		free(f->win);
	f->img_ptr = mlx_new_image(f->mlx_ptr, W, H);
	if (!f->img_ptr)
		free(f->img_ptr);
	f->data_addr = mlx_get_data_addr(f->img_ptr,
			&f->bits_per_pixel, &f->size_line, &f->endian);
	if (!f->data_addr)
		free(f->data_addr);
}

void	color_pixel(t_fractol *f, int x, int y, double color)
{
	int	*b;

	b = f->data_addr;
	b[(y * f->size_line / 4) + x] = color;
}

void	free_funct(t_fractol *f)
{
	mlx_destroy_window(f->mlx_ptr, f->win);
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	mlx_destroy_display(f->mlx_ptr);
	free(f->mlx_ptr);
	free(f);
}

int	ft_check(int ac, char **av)
{
	if ((ft_strcmp(av[1], "mandelbrot") == 1) && ac == 2)
		return (1);
	if ((ft_strcmp(av[1], "julia") == 1) && ac == 4)
		return (1);
	if ((ft_strcmp(av[1], "ship") == 1) && ac == 2)
		return (1);
	return (0);
}
