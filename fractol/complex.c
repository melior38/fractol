/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:43:44 by asouchet          #+#    #+#             */
/*   Updated: 2022/12/12 14:11:23 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	new_complex(double real, double img)
{
	t_complex	ret;

	ret.real = real;
	ret.img = img;
	return (ret);
}

t_complex	complex_power(t_complex z)
{
	t_complex	ret;

	ret = new_complex(z.real * z.real - z.img * z.img, z.real * z.img * 2.0);
	return (ret);
}

t_complex	complex_add(t_complex a, t_complex b)
{
	return (new_complex(a.real + b.real, a.img + b.img));
}

double	ft_norme(t_complex z)
{
	return(z.real * z.real + z.img * z.img);
}
