/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:15:58 by asouchet          #+#    #+#             */
/*   Updated: 2022/12/08 18:16:35 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# define WIDTH 1080
# define HEIGTH 1080


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_complex {
	double real;
	double img;
}				t_complex;

int 		main();
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_complex	new_complex(double real, double img);
t_complex	complex_power(t_complex loc);
t_complex	complex_add(t_complex a, t_complex b);
double		ft_norme(t_complex z);
int			ft_color(int i);
int			mandelbrot(t_complex z, t_complex c);
t_complex	pix_to_complex(int x, int y, double offset_x, double offset_y);
int 		my_mlx_get_color_value(int red, int green, int blue);
double	ft_hook_y(int i);
double	ft_hook_x(int i);

#endif
