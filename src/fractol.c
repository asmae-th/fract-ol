/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:02:42 by atahtouh          #+#    #+#             */
/*   Updated: 2025/05/12 12:31:38 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	ft_calcule(char *str, int i)
{
	double	reslt2;
	int		j;

	reslt2 = 0;
	j = 0;
	i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		reslt2 = reslt2 * 10 + str[i] - '0';
		i++;
		j++;
	}
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i])
		ft_error("args non valid");
	return (reslt2 / ft_pow(10, j));
}

void	ft_check_args(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			ft_error("args non valid");
		i++;
	}
}

double	ft_atof(char *str)
{
	int		i;
	double	sig;
	double	reslt1;
	double	reslt2;

	i = 0;
	sig = 1;
	reslt1 = 0;
	reslt2 = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str [i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		reslt1 = reslt1 * 10 + str[i++] - '0';
	ft_check_args(str, i);
	if (str[i] && str[i] == '.')
		reslt2 = ft_calcule(str, i);
	else
		return (sig * reslt1);
	return (sig * (reslt1 + reslt2));
}

void	draw_fractal(t_fractol *f)
{
	f->x = 0;
	f->y = 0;
	while (f->x < W)
	{
		while (f->y < H)
		{
			if (ft_strcmp(f->name, "mandelbrot") == 1)
				mandelbrot(f);
			if (ft_strcmp(f->name, "julia") == 1)
				julia(f);
			if (ft_strcmp(f->name, "ship") == 1)
				burning_ship(f);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win, f->img_ptr, 0, 0);
}

int	main(int ac, char **av)
{
	t_fractol	*f;

	if (ac >= 2 && ft_check(ac, av) == 1)
	{
		f = malloc(sizeof(t_fractol));
		if (ac > 2)
		{
			if ((ft_valid(av[2]) == 1) && (ft_valid(av[3]) == 1))
			{
				f->rj = ft_atof(av[2]);
				f->ij = ft_atof(av[3]);
			}
			else
				error(f);
		}
		init_fract(f, av);
		init_mlx_fract (f);
		draw_fractal (f);
		mlx_mouse_hook (f->win, mouse_hook, f);
		mlx_key_hook (f->win, funct_ptr, f);
		mlx_hook(f->win, 17, 0, handle_window_close, f);
		mlx_loop (f->mlx_ptr);
	}
	else
		ft_put_msg(1);
}
