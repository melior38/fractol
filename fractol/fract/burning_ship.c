/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:27:37 by asouchet          #+#    #+#             */
/*   Updated: 2023/01/09 15:30:46 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(t_params *params, t_complex z, t_complex c)
{
	int	max_iter;
	int	i;

	i = 0;
	max_iter = params->max_iter;
	while (ft_norme(z) < 4.0 && i <= max_iter)
	{
		z.real = fabs(z.real);
		z.img = fabs(z.img);
		z = complex_add(complex_power(z), c);
		i++;
	}
	return (ft_color(params, i));
}

int	ft_handle_fractol_input(int keycode, t_data *vars)
{
	(void) vars;
	if (keycode == JULIA)
		vars->param->type = JULIA;
	if (keycode == BURNING_SHIP)
		vars->param->type = BURNING_SHIP;
	if (keycode == MANDELBROT)
		vars->param->type = MANDELBROT;
	return (0);
}
