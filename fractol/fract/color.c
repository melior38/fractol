/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:53:31 by asouchet          #+#    #+#             */
/*   Updated: 2023/02/23 11:38:31 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	my_mlx_get_color_value(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

int	ft_color(t_params *params, int i)
{
	double	shading;
	int		max_iter;

	max_iter = params->max_iter;
	shading = 155 / params->max_iter * i * i * i * i * i;
	if (i < params->max_iter && params->rgb == GREEN)
		return (my_mlx_get_color_value(0, 100 + shading, 0));
	if (i < params->max_iter && params->rgb == RED)
		return (my_mlx_get_color_value(50 + shading, 0, 0));
	if (i < params->max_iter && params->rgb == BLUE)
		return (my_mlx_get_color_value(0, 0, 50 + shading));
	else
		return (my_mlx_get_color_value(0, 0, 0));
}

// juste des fonctions randoms qui n'ont pas leur place ici mais tkt
int	ft_strcmp(char *str1, char *str2)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (str1[k] || str2[i])
	{
		if (str1[k] != str2[i])
			return (1);
		if (str1[k] == str2[i])
		{
			i++;
			k++;
		}
	}
	return (0);
}

int	ft_fractol(int x, int y, t_data *img)
{
	if (img->param->type == MANDELBROT)
		my_mlx_pixel_put(img, x, y, mandelbrot(img->param,
				new_complex(0.0, 0.0), pix_to_complex(x, y, img->param)));
	else if (img->param->type == JULIA)
		my_mlx_pixel_put(img, x, y, burning_ship(img->param,
				pix_to_complex(x, y, img->param), img->param->new_complex));
	else if (img->param->type == BURNING_SHIP)
		my_mlx_pixel_put(img, x, y, burning_ship(img->param,
				new_complex(0.0, 0.0), pix_to_complex(x, y, img->param)));
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
