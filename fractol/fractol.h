/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:15:58 by asouchet          #+#    #+#             */
/*   Updated: 2022/12/05 21:21:06 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_coor {
	int	x;
	int	y;
	int w; 
	int	h;
} 				t_coor;

typedef struct	s_complex {
	double a;
	double b;
}				t_complex;

int main();
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
