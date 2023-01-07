/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:31:07 by asouchet          #+#    #+#             */
/*   Updated: 2023/01/05 16:29:27 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pix_to_complex(int x, int y, t_params *param)
{
	t_complex loc;
	double min;
	double max;

	min = param->min * param->zoom;
	max = param->max * param->zoom;
	param->x = x;
	param->y = y;
	loc.real = (x / (double)WIDTH) * (max - min) - ((max - min) / 2) + param->offset_x;
	loc.img = (y / (double)HEIGTH) * (max - min) - ((max - min) / 2) + param->offset_y;
	// param->zoom = 1;
	return (loc);
}

// t_complex	*pix_to_vector(int x, int y, t_)
// {	
// 	t_complex loc;
// 	double min;
// 	double max;

// 	min = param->min * param->zoom;
// 	max = param->max * param->zoom;
// 	param->x = x;
// 	param->y = y;
// 	loc.real = (x / (double)WIDTH) * (max - min) - ((max - min) / 2) + param->offset_x;
// 	loc.img = (y / (double)HEIGTH) * (max - min) - ((max - min) / 2) + param->offset_y;
// 	// param->zoom = 1;
// 	return (loc);
// }
