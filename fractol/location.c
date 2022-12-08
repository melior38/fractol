/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:31:07 by asouchet          #+#    #+#             */
/*   Updated: 2022/12/08 18:18:01 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pix_to_complex(int x, int y, double offset_x, double offset_y)
{
	t_complex loc;
	double min;
	double max;

	min = -2;
	max = 2;
	loc.real = (x / (double)WIDTH) * (max - min) - ((max - min) / 2) + offset_x;
	loc.img = (y / (double)HEIGTH) * (max - min) - ((max - min) / 2) + offset_y;
	return (loc);
}

