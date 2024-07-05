/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahtouh <atahtouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:49:51 by atahtouh          #+#    #+#             */
/*   Updated: 2024/07/05 09:45:09 by atahtouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600
// #define SCALE 25 // Échelle pour agrandir la sinusoïde

// typedef struct {
//     void *mlx_ptr;
//     void *win_ptr;
// } t_mlx;

// void draw_axes(t_mlx *mlx) {
//     int mid_x = WIDTH / 2;
//     int mid_y = HEIGHT / 2;

//     // Axe des x
//     for (int x = 0; x < WIDTH; x++) {
//         mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, mid_y, 0xFFFFFF);
//     }

//     // Axe des y
//     for (int y = 0; y < HEIGHT; y++) {
//         mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mid_x, y, 0xFFFFFF);
//     }
// }

// void draw_sin(t_mlx *mlx) {
//     int mid_x = WIDTH / 2;
//     int mid_y = HEIGHT / 2;
//     int x = 0;
//     while ( x < WIDTH )
//      {
//         double real_x = (x - mid_x) / (double)SCALE;  // Conversion en coordonnées réelles
//         double real_y = sin(real_x);  // Calcul de sin(x)
//         int y = mid_y - (int)(real_y * SCALE);  // Conversion en pixels

//         mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xFF0000);
//         x++;  // Dessiner le point
//     }
// }

// int main() {
//     t_mlx mlx;

//     mlx.mlx_ptr = mlx_init();
//     mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Sin(x) Function");

//     draw_axes(&mlx);
//     draw_sin(&mlx);

//     mlx_loop(mlx.mlx_ptr);

//     return 0;
// }
int	main(int ac, char **av)
{
	int i = 0;
	void *mlx_ptr;
	void *img_ptr;
	void *win;

	int bits_per_pixel;
	int size_line;
	int endian;
	char *data_addr;

	mlx_ptr = mlx_init();
	win = mlx_new_window(mlx_ptr, 800, 800, "test");
	img_ptr = mlx_new_image(mlx_ptr, 400, 400);
	data_addr = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	while (1)
	{
		mlx_pixel_put(mlx_ptr,win,i,i,0xFF0000);
		i++;
	}
	
	mlx_put_image_to_window(mlx_ptr, win, img_ptr, 200, 200);

	mlx_destroy_image(mlx_ptr,img_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}