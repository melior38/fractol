/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:27:34 by asouchet          #+#    #+#             */
/*   Updated: 2023/01/09 17:42:23 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_params *params, t_complex z, t_complex c)
{
	int	max_iter;
	int	i;

	i = 0;
	max_iter = params->max_iter;
	while (ft_norme(z) < 4.0 && i <= max_iter)
	{
		z = complex_add(complex_power(z), c);
		i++;
	}
	return (ft_color(params, i));
}
