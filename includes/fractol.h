/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:51:14 by atahtouh          #+#    #+#             */
/*   Updated: 2025/05/12 12:30:48 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "/home/atahtouh/Desktop/minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h> 
# include <X11/X.h>
# include <X11/Xlib.h>
# include <string.h>
# define H 800
# define W 800

typedef struct fractol
{
	void	*mlx_ptr;
	void	*img_ptr;
	void	*win;
	char	*name;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	void	*data_addr;
	double	color;
	int		x;
	int		y;
	double	rj;
	double	ij;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	double	zoom;
}	t_fractol;
void	init_fract(t_fractol *f, char **av);
void	init_mlx_fract(t_fractol *f);
int		ft_strcmp(char *s1, char *s2);
void	mandelbrot(t_fractol *f);
void	draw_fractal(t_fractol *f);
void	color_pixel(t_fractol *f, int x, int y, double color);
void	julia(t_fractol *f);
void	ft_put_msg(int i);
void	ft_putstr_fd(char *str, int fd);
double	ft_pow(int a, int b);
double	ft_atof(char *str);
int		mouse_hook(int code, int x, int y, t_fractol *f);
int		funct_ptr(int x_event, t_fractol *f);
int		mouse_move(int key, int x, int y, t_fractol *fract);
void	free_funct(t_fractol *f);
int		ft_check(int ac, char **av);
void	ft_exit(t_fractol *f);
void	burning_ship(t_fractol *f);
void	ft_error(char *str);
double	ft_calcule(char *str, int i);
void	ft_change_color(t_fractol *f);
int		handle_window_close(t_fractol *f);
int		ft_strlen(char *str);
int		ft_valid(char *arg);
void	error(t_fractol *f);
void	ft_check_args(char *str, int i);
#endif