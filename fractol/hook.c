/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:10:20 by asouchet          #+#    #+#             */
/*   Updated: 2022/12/28 15:47:49 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
int	ft_offset_hook(int keycode, t_data *vars)
{
	(void) vars;
	// printf("%i\n", keycode);
	if (keycode == DOWN)
		vars->param->offset_y += 0.1;
	if (keycode == UP)
		vars->param->offset_y -= 0.1;
	if (keycode == LEFT)
		vars->param->offset_x -= 0.1;
	if (keycode == RIGHT)
		vars->param->offset_x += 0.1;
	if (keycode == MINUS)
		vars->param->zoom *= 1.10;
	else if (keycode == PLUS)
		vars->param->zoom *= 0.90;
	if (keycode == ESC)
		ft_handle_exit();
	return 0;
}

int	ft_handle_exit()
{
	exit(0);
	return (0);
}

int	ft_handle_roll_down(int keycode, int x, int	y, t_data *vars)
{
	(void) vars;
	(void) x;
	(void) y;
	printf("x[%i]\ny[%i]\n", x, y);
	if (keycode == SCROLL_DOWN)
		vars->param->zoom *= 1.10;
	else if (keycode == SCROLL_UP)
		vars->param->zoom *= 0.90;
	return (0);
}
int	ft_handle_roll_up(int keycode, int x, int y, t_data *vars)
{
	(void) vars;
	(void) x;
	(void) y;
	if (keycode == SCROLL_UP)
		vars->param->zoom *= 0.90;
	return (0);
}


// int ft_mouse_pos(int x, int y, int keycode, t_data *vars)
// {
// 	double	*offset_y;
// 	double	*offset_x;

// 	offset_x = &vars->param->offset_x;
// 	offset_y = &vars->param->offset_y;
	
// }
