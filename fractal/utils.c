/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:51:00 by atahtouh          #+#    #+#             */
/*   Updated: 2024/07/23 12:03:01 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_put_msg(int i)
{
	if (i == 1)
	{
		ft_putstr_fd("entrer 2 args : \n", 1);
		ft_putstr_fd("enter mandelbrot\n", 1);
		ft_putstr_fd("OR \n", 1);
		ft_putstr_fd("enter julia with 2 double number\n", 1);
	}
}

double	ft_pow(int a, int b)
{
	if (a == 0)
		return (0);
	else if (b == 1)
		return (a);
	else
		return (a * ft_pow(a, b - 1));
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}
