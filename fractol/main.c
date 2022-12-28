/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:48:35 by asouchet          #+#    #+#             */
/*   Updated: 2022/12/28 15:35:15 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h> 
#include <stdio.h> 

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int	render_next_frame(void *YourStruct)
{
	t_data *img = (t_data *) YourStruct;
	// printf("%f\n", img->param->offset_x);
	int		x = 0;
	int		y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			my_mlx_pixel_put(img, x, y, mandelbrot(new_complex(0.0,0.0), pix_to_complex(x,y, *img->param)));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return 0;
}


int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_params param;
	
	param.offset_x = 0.0;
	param.offset_y = 0.0;
	param.min = -2.0;
	param.max = 2.0;
	param.zoom = 1.0;
	img.param = &param;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, HEIGTH, WIDTH, "Hell world!");
	img.img = mlx_new_image(mlx, HEIGTH, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	img.mlx = mlx;
	img.mlx_win = mlx_win;
	// render next frame sur la boucle (chercher le hook)

	mlx_hook(mlx_win, ON_KEYUP, 0, ft_offset_hook, &img);
	mlx_hook(mlx_win, ON_DESTROY, 0, ft_handle_exit, &img);
	mlx_hook(mlx_win, ON_MOUSEDOWN, 0, ft_handle_roll_down, &img);
	mlx_hook(mlx_win, ON_MOUSEUP, 0, ft_handle_roll_up, &img);
	mlx_loop_hook(mlx, render_next_frame, &img);
	mlx_loop(mlx);
}