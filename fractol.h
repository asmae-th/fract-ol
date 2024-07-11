/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:51:14 by atahtouh          #+#    #+#             */
/*   Updated: 2024/07/11 10:54:27 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "minilibx-linux/mlx.h"
#include<stdlib.h>
#include<unistd.h>
#include <stdio.h>
#include <math.h> 


#define H 500
#define W 500


typedef struct fractol
{
    void *mlx_ptr;
	void *img_ptr;
	void *win;
	char *name;
	int bits_per_pixel;
	int size_line;
	int endian;
	void *data_addr;
	int color;
	int x;
	int y;
	double zx;
	double zy;
	double cx;
	double cy;
	double offset_x;
	double offset_y;
	int max_iter;
	double zoom;
    
}t_fractol;

void init_fract(t_fractol *f);
void init_mlx_fract(t_fractol *f);
int ft_strcmp(char *s1, char *s2);
void mandelbrot(t_fractol *f);
void draw_fractal(t_fractol *f,int ac, char **av);
void color_pixel(t_fractol *f, int x, int y, double color);
void julia(t_fractol *f, double cx, double cy);
#endif