/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:31:07 by asouchet          #+#    #+#             */
/*   Updated: 2022/12/28 20:49:51 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pix_to_complex(int x, int y, t_params param)
{
	t_complex loc;
	double min;
	double max;

	min = param.min * param.zoom;
	max = param.max * param.zoom;
	loc.real = (x / (double)WIDTH) * (max - min) - ((max - min) / 2) + param.offset_x;
	loc.img = (y / (double)HEIGTH) * (max - min) - ((max - min) / 2) + param.offset_y;
	return (loc);
}

void	*pix_to_vector(int x, int y, t_params *loc)
{
	double min;
	double max;

	min = loc->min * loc->zoom;
	max = loc->max * loc->zoom;
	loc->offset_x = (x / (double)WIDTH) * (max - min) - ((max - min) / 2);
	loc->offset_y = (y / (double)HEIGTH) * (max - min) - ((max - min) / 2);
}


