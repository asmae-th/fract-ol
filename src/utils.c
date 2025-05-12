/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:51:00 by atahtouh          #+#    #+#             */
/*   Updated: 2025/05/12 12:31:53 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
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
		ft_putstr_fd("Enter 2 arguments ✌️​ :\n", 1);
		ft_putstr_fd("Enter 'mandelbrot'\n", 1);
		ft_putstr_fd("OR\n", 1);
		ft_putstr_fd("Enter 'ship'🚢​\n", 1);
		ft_putstr_fd("OR\n", 1);
		ft_putstr_fd("Enter 'julia' with 2 double numbers\n", 1);
	}
	if (i == 0)
		ft_putstr_fd("Enter 'julia' with 2 valid double numbers\n", 1);
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
