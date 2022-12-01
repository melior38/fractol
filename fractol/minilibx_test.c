/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:48:35 by asouchet          #+#    #+#             */
/*   Updated: 2022/11/27 17:48:38 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
/*
int	main()
{
	void	*mlx;
	void	*win;
	t_data	img;

	mlx = mlx_init(); // permet d'acceder au serveur graphique
	win = mlx_new_window(mlx, 1920, 1080, "HELLO WORLD!"); // permet d'ouvrir une nouvelle fenetre
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	
	// 
	// After creating an image, we can call `mlx_get_data_addr`, we pass
	//`bits_per_pixel`, `line_length`, and `endian` by reference. These will
	// then be set accordingly for the *current* data address.
	// 
	mlx_loop(mlx);
	return (0);
}*/

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_coor	loc;
	int		i;
	int		x = 0;
	int		y = 0;


	i = 0;
	loc.w = 1920;
	loc.h = 1080;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hell world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// while (i++ <= 20)
	// // my_mlx_pixel_put(&img, loc.w / 2 + i, loc.h / 2 + i, 0x00FF0000);
	while (loc.w / 2 + x < )
		{
			y = 0;
			while (loc.h / 2 + y < loc.h)
			{
				my_mlx_pixel_put(&img, (loc.w / 2 + x) - (loc.w / 4), (loc.h / 2 + y) - (loc.h / 4), 0x00FF0000);
				y++;
			}
			x++;
		}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}