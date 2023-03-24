/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:10:20 by asouchet          #+#    #+#             */
/*   Updated: 2023/02/23 11:32:42 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_offset_hook(int keycode, t_data *vars)
{
	(void) vars;
	if (keycode == DOWN)
		vars->param->offset_y += 0.2 * vars->param->zoom;
	if (keycode == UP)
		vars->param->offset_y -= 0.2 * vars->param->zoom;
	if (keycode == LEFT)
		vars->param->offset_x -= 0.2 * vars->param->zoom;
	if (keycode == RIGHT)
		vars->param->offset_x += 0.2 * vars->param->zoom;
	if (keycode == MINUS)
		vars->param->zoom *= 1.10;
	else if (keycode == PLUS)
		vars->param->zoom *= 0.90;
	if (keycode == MANDELBROT || keycode == BURNING_SHIP
		|| keycode == JULIA)
		return (ft_handle_fractol_input(keycode, vars));
	vars->param->max_iter = 150;
	if (keycode == DEFAULT)
		ft_fractal_setup(vars->param);
	if (keycode == RED || keycode == GREEN || keycode == BLUE)
		return (ft_handle_color_event(keycode, vars));
	if (keycode == ESC)
		ft_handle_exit();
	return (0);
}

int	ft_handle_color_event(int keycode, t_data *vars)
{
	(void) vars;
	if (keycode == BLUE)
		vars->param->rgb = BLUE;
	if (keycode == GREEN)
		vars->param->rgb = GREEN;
	if (keycode == RED)
		vars->param->rgb = RED;
	return (0);
}

int	ft_handle_roll(int keycode, int x, int y, t_data *vars)
{
	(void) x;
	(void) y;
	if (keycode == SCROLL_UP)
		vars->param->zoom *= 0.85;
	else if (keycode == SCROLL_DOWN)
		vars->param->zoom *= 1.15;
	vars->param->max_iter = 150;
	return (0);
}

int	ft_mouse_press(int keycode, int x, int y, t_data *vars)
{
	double		zoom;
	t_complex	new_complex;

	zoom = vars->param->zoom;
	if (keycode == SCROLL_DOWN || keycode == SCROLL_UP)
		return (ft_handle_roll(keycode, x, y, vars));
	if (keycode == LEFT_CLICK && vars->param->type == JULIA)
	{
		new_complex = pix_to_complex(x, y, vars->param);
		vars->param->new_complex = new_complex;
		vars->param->max_iter = 150;
	}
	if (y < 0)
		return (0);
	vars->param->x = x;
	vars->param->y = y;
	vars->param->rendering = 0;
	return (0);
}

int	ft_mouse_release(int keycode, int x, int y, t_data *vars)
{
	(void) x;
	(void) keycode;
	if (y > 0)
		vars->param->rendering = 1;
	return (0);
}
