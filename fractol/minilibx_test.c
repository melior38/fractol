/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:48:35 by asouchet          #+#    #+#             */
/*   Updated: 2022/12/05 21:30:55 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_coor	loc;
	int		i;
	int		x = 0;
	int		y = 0;

	i = 500;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hell world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (x < 1920)
	{
		y = 0;
		while (y < 1080)
		{
			t_complex = convert_loc(x, y);
			//mandelbrot();
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}