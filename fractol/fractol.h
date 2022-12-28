/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:15:58 by asouchet          #+#    #+#             */
/*   Updated: 2022/12/28 16:00:59 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# define WIDTH 1080
# define HEIGTH 1080

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define W 13
# define A 0
# define S 1
# define D 2
# define RED 15// R
# define GREEN 5// G
# define BLUE 11// B
# define MANDELBROT 46// M+
# define JULIA 38// J
# define OTHER 31// O
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3
# define PLUS 69
# define MINUS 78
# define ESC 53

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	// t_data		*img;
}				t_vars;

typedef struct	s_params {
	double offset_x;
	double offset_y;
	double min;
	double max;
	double x;
	double y;
	double zoom;
}				t_params;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	t_params *param;
}				t_data;

typedef struct	s_complex {
	double real;
	double img;
}				t_complex;

// A MOI
int 		main();
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_complex	new_complex(double real, double img);
t_complex	complex_power(t_complex loc);
t_complex	complex_add(t_complex a, t_complex b);
double		ft_norme(t_complex z);
int			ft_color(int i);
int			mandelbrot(t_complex z, t_complex c);
t_complex	pix_to_complex(int x, int y, t_params param);
int 		my_mlx_get_color_value(int red, int green, int blue);
int			ft_offset_hook(int button, t_data *param);
int			ft_handle_exit();
int			ft_handle_roll_down(int keycode, int x, int	y, t_data *vars);
int			ft_handle_roll_up(int keycode, int x, int y, t_data *vars);

#endif
