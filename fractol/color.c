/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:53:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/01/07 20:33:09 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int my_mlx_get_color_value(int red, int green, int blue)
{
  // Calculate and return the color value for the given red, green, and blue values
  return ((red << 16) | (green << 8) | blue);
}

int	ft_color(t_params *params, int i)
{
	double shading;
	int max_iter;

	max_iter = params->max_iter;
	// if (i > 150)
	// 	printf("i = (%d)", i);
	shading = 155 / params->max_iter * i * i;

	// if (i >= 0 && i < max_iter / 6)
	// 	return(my_mlx_get_color_value(227, 131, 219));
	// else if (i >= max_iter / 6 && i < (max_iter / 6) * 2)
	// 	return (my_mlx_get_color_value(199, 0, 57));
	// else if (i >= (max_iter / 6) * 2 && i < (max_iter / 6) * 3)
	// 	return (my_mlx_get_color_value(97, 249, 18));
	// else if (i >= (max_iter / 6) * 3 && i <= (max_iter / 6) * 4)
	// 	return (my_mlx_get_color_value(18, 249, 234));
	// else if (i >= (max_iter / 6) * 4 && i <= (max_iter / 6) * 5)
	// 	return (my_mlx_get_color_value(18, 249, 234));
	// else if (i >= (max_iter / 6) * 5 && i < max_iter)
	// 	return (my_mlx_get_color_value(31, 18, 249));
	// else
	if (i < params->max_iter && params->rgb == GREEN)
		return(my_mlx_get_color_value(0,100 + shading,0));
	if (i < params->max_iter && params->rgb == RED)
		return(my_mlx_get_color_value(50 + shading,0,0));
	if (i < params->max_iter && params->rgb == BLUE)
		return(my_mlx_get_color_value(0,0,50 + shading));
	else
		return (my_mlx_get_color_value(0, 0, 0));
}
