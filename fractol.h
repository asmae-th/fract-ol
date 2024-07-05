/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:51:14 by atahtouh          #+#    #+#             */
/*   Updated: 2024/07/05 09:48:40 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "minilibx-linux/mlx.h"
#include<stdlib.h>
#include<unistd.h>
#include <stdio.h>
#include <math.h> 

typedef struct fractol
{
    void *mlx_ptr;
	void *img_ptr;
	void *win;
	int bits_per_pixel;
	int size_line;
	int endian;
	char *data_addr;
    
};


#endif