/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:48:35 by asouchet          #+#    #+#             */
/*   Updated: 2022/12/08 18:17:32 by asouchet         ###   ########.fr       */
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
	int		x = 0;
	int		y = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, HEIGTH, WIDTH, "Hell world!");
	img.img = mlx_new_image(mlx, HEIGTH, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// render next frame sur la boucle (chercher le hook)
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			my_mlx_pixel_put(&img, x, y, mandelbrot(new_complex(0.0,0.0), pix_to_complex(x,y, ft_hook_x(0), ft_hook_y(0))));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}