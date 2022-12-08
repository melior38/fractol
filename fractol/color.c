/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:53:31 by asouchet          #+#    #+#             */
/*   Updated: 2022/12/08 18:18:57 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int my_mlx_get_color_value(int red, int green, int blue)
{
  // Calculate and return the color value for the given red, green, and blue values
  return ((red << 16) | (green << 8) | blue);
}

int	ft_color(int i)
{
	if (i >= 0 && i < 30)
		return(my_mlx_get_color_value(73, 130, 252));
	else if (i >= 30 && i < 50)
		return (my_mlx_get_color_value(76, 54, 245));
	else if (i >= 50 && i < 70)
		return (my_mlx_get_color_value(151, 69, 245));
	else if (i >= 70 && i <= 100)
		return (my_mlx_get_color_value(252, 73, 252));
	else
		return (my_mlx_get_color_value(0, 0, 0));
}
