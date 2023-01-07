/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:10:20 by asouchet          #+#    #+#             */
/*   Updated: 2023/01/07 20:41:02 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
int	ft_offset_hook(int keycode, t_data *vars)
{
	(void) vars;
	// printf("%i\n", keycode);
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
	if (keycode == JULIA)
		vars->param->type = JULIA;
	vars->param->max_iter = 150;
	if (keycode == RED || keycode == GREEN || keycode == BLUE)
		return (ft_handle_color_event(keycode, vars));
	if (keycode == ESC)
		ft_handle_exit();
	return 0;
}

int ft_handle_color_event(int keycode, t_data *vars)
{
	(void) vars;

	if (keycode == BLUE)
		vars->param->rgb = BLUE;
	if (keycode == GREEN)
		vars->param->rgb = GREEN;
	if (keycode == RED)
		vars->param->rgb = RED;
	return 0;
}

int	ft_handle_exit()
{
	exit(0);
	return (0);
}

// int	ft_handle_roll_down(int keycode, int x, int	y, t_data *vars)
// {
// 	(void) vars;
// 	(void) x;
// 	(void) y;
// 	printf("x[%i]\ny[%i]\n", x, y);
// 	if (keycode == SCROLL_DOWN)
// 		vars->param->zoom *= 1.10;
// 	else if (keycode == SCROLL_UP)
// 		vars->param->zoom *= 0.90;
// 	return (0);
// }
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

int	ft_mouse_press(int keycode, int x, int y, t_data *vars) // ON_MOUSEDOWN
{
	double	zoom;

	zoom = vars->param->zoom;
	if(keycode == SCROLL_DOWN || keycode == SCROLL_UP)
		return (ft_handle_roll(keycode, x, y, vars));
	if (keycode == LEFT_CLICK && vars->param->type == JULIA)
		{
			t_complex new_complex;

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

// int	ft_mouse_move(int x, int y, t_data *vars) // ON_MOUSEMOVE
// {
// 	double	zoom;
// 	double	*offset_x;
// 	double	*offset_y;

// 	offset_x = &vars->param->offset_x;
// 	offset_y = &vars->param->offset_y;
// 	zoom = vars->param->zoom;
// 	if (!vars->param->rendering)
// 	{
// 		*offset_x += (vars->param->x - (double) x) / 1080.0 / zoom;
// 		*offset_y += (vars->param->y - (double) y) / 1080.0 / zoom;
// 	}
// 	return (0);
// }

// int ft_mouse_pos(int x, int y, t_data *vars)
// {
// 	double	zoom;
// 	double	*offset_y;
// 	double	*offset_x;

// 	offset_x = &vars->param->offset_x;
// 	offset_y = &vars->param->offset_y;
// 	zoom = vars->param->zoom;
// 	if (!vars->param->rendering)
// 	{
// 		*offset_x += (vars->param->x - (double) x) / 1080.0 / zoom;
// 		*offset_y += (vars->param->y - (double) y) / 1080.0 / zoom;
// 		vars->param->max_iter = fmin(vars->param->max_iter, fmax(50, zoom / 2));
// 	}
// 	return (0);
// }
	
	// MES CONNERIES
	// vector = pix_to_complex(x, y, vars->param);
		// printf("vector_x[%f]\nvector_y[%f]\nx[%d]\ny[%d]\n", vector.real, vector.img, x, y);
	// if (x <= HEIGTH / 2 && y <= WIDTH / 2)
	// {
	// 	vars->param->offset_y += vector.real * 0.2;
	// 	vars->param->offset_x += vector.img * 0.2;
	// }
	// else if (x <= HEIGTH / 2 && y >= WIDTH / 2)
	// {
	// 	vars->param->offset_x += vector.img * 0.2;
	// 	vars->param->offset_y += vector.real * 0.2;
	// }
	// else if (x >= HEIGTH / 2 && y <= WIDTH / 2)
	// {
	// 	vars->param->offset_y += vector.real * 0.2;
	// 	vars->param->offset_x -= vector.img * 0.2;
	// }
	// else if (x >= HEIGTH / 2 && y >= WIDTH / 2)
	// {
	// 	vars->param->offset_y += vector.real * 0.2;
	// 	vars->param->offset_x += vector.img * 0.2;
	// }
	// printf("vector_x[%f]\nvector_y[%f]\nx[%d]\ny[%d]\n", vars->param->offset_x, vars->param->offset_y, x, y);
	// return (0);