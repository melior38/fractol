/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:27:34 by asouchet          #+#    #+#             */
/*   Updated: 2022/12/08 16:49:57 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex z, t_complex c)
{
	int	i;

	i = 0;
	while (ft_norme(z) < 4.0 && i <= 100)
	{
		z = complex_add(complex_power(z), c);
		i++;
	}
	return(ft_color(i));
}