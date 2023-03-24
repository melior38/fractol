/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:48:35 by asouchet          #+#    #+#             */
/*   Updated: 2023/01/09 18:28:41 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h> 
#include <stdio.h> 

int	render_next_frame(void *yourstruct)
{
	t_data	*img;
	int		x;
	int		y;

	img = (t_data *)yourstruct;
	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			if (img->param->type == MANDELBROT || img->param->type
				== JULIA || img->param->type == BURNING_SHIP)
				ft_fractol(x, y, img);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

void	ft_fractal_setup(t_params *param)
{
	if (param->rgb != RED || param->rgb != GREEN
		|| param->rgb != BLUE)
		param->rgb = BLUE;
	param->offset_x = 0.0;
	param->offset_y = 0.0;
	param->min = -2.0;
	param->max = 2.0;
	param->zoom = 1.0;
	param->max_iter = 50;
	param->new_complex.real = 0.285;
	param->new_complex.img = 0.01;
}

int	ft_handle_exit(void)
{
	exit(0);
	return (0);
}

int	ft_handle_argument(int ac, char **av, t_params *param)
{
	ft_fractal_setup(param);
	if (!ft_strcmp(av[1], "julia") && av[1])
		param->type = JULIA;
	else if (!ft_strcmp(av[1], "mandelbrot") && av[1])
		param->type = MANDELBROT;
	else if (!ft_strcmp(av[1], "burning ship") && av[1])
		param->type = BURNING_SHIP;
	else
		return (handle_wrong_argument(ac, 0));
	return (0);
}

int	main(int ac, char **av)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_params	param;

	if (ac != 2)
		return (handle_wrong_argument(ac, 0));
	if (ft_handle_argument(ac, av, &param))
		return (0);
	else
		ft_handle_argument(ac, av, &param);
	img.param = &param;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, HEIGTH, WIDTH, "Hell world!");
	img.img = mlx_new_image(mlx, HEIGTH, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	img.mlx = mlx;
	img.mlx_win = mlx_win;
	mlx_hook(mlx_win, ON_KEYUP, 0, ft_offset_hook, &img);
	mlx_hook(mlx_win, ON_DESTROY, 0, ft_handle_exit, &img);
	mlx_hook(mlx_win, ON_MOUSEDOWN, 0, ft_mouse_press, &img);
	mlx_hook(mlx_win, ON_MOUSEUP, 0, ft_mouse_release, &img);
	mlx_loop_hook(mlx, render_next_frame, &img);
	mlx_loop(mlx);
}
