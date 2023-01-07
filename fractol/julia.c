/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:27:37 by asouchet          #+#    #+#             */
/*   Updated: 2023/01/05 18:04:04 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_params *params, t_complex z, t_complex c)
{
	int	max_iter;
	int	i;

	i = 0;
	max_iter = params->max_iter;
	if (z.real == 0 && z.img == 0)
		return (0);
	
	while (ft_norme(z) < 4.0 && i <= max_iter)
	{
		z = complex_add(complex_power(z), c);
		i++;
	}
	return(ft_color(params, i));
}