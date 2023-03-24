/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:31:07 by asouchet          #+#    #+#             */
/*   Updated: 2023/01/09 17:57:02 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pix_to_complex(int x, int y, t_params *param)
{
	t_complex	loc;
	double		min;
	double		max;

	min = param->min * param->zoom;
	max = param->max * param->zoom;
	param->x = x;
	param->y = y;
	loc.real = (x / (double)WIDTH) * (max - min) - ((max - min) / 2)
		+ param->offset_x;
	loc.img = (y / (double)HEIGTH) * (max - min) - ((max - min) / 2)
		+ param->offset_y;
	return (loc);
}

// juste des fonctions randoms qui n'ont pas leur place ici mais tkt
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	handle_wrong_argument(int ac, int wrong)
{
	if (ac > 2 || ac == 1)
		ft_putstr("please enter the good amount of argument\n");
	if (wrong == 0)
	{
		ft_putstr("wrong parameter input\n");
		ft_putstr("please choose between mandelbrot, burning ship and julia\n");
		return (1);
	}
	return (0);
}
