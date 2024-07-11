/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:02:42 by atahtouh          #+#    #+#             */
/*   Updated: 2024/07/11 11:09:54 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_fractal(t_fractol *f,int ac, char **av)
{
	double r;
	double i;
	f->x = 0;
	f->y = 0;
	while (f->x < W)
	{
		while (f->y < H)
		{
				if(ac == 2 && ft_strcmp(av[1],"mandelbrot") == 1)
				{
					mandelbrot(f);
				}
				if(ac > 2 && ft_strcmp(av[1],"julia") == 1)
				{
					r = atof(av[2]);
					i = atof(av[3]);
					julia(f,r,i);
				}
					
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	mlx_put_image_to_window(f->mlx_ptr,f->win,f->img_ptr,0,0);
}

int main(int ac, char **av)
{
	t_fractol *f;
	f = malloc(sizeof(t_fractol));
	init_fract(f);
	init_mlx_fract(f);
	// printf(":::::::::::::::::::::::::::");
	 draw_fractal(f,ac, av);
	 mlx_loop(f->mlx_ptr);
}


// mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param) 
// mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param)