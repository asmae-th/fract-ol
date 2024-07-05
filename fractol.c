/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:02:42 by atahtouh          #+#    #+#             */
/*   Updated: 2024/07/05 09:47:35 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_must_int()
{
	write(1,"Enter param",12);
}

int main(int ac, char **av)
{
	if(ac >= 2 )
	{
		if(av[1] == "Mandelbrot")
			Drow_mandelbrot();
		else if(av[1] == "Julia")
			Drow_julai();
			
	}
	else
		ft_must_enter();
}
