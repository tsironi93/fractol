/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:37:09 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/07 18:48:33 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# define HEIGHT 800
# define WIDTH 800
# define MAX_ITER 42

# define ESC_KEY_MAC 53
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

# define COLOR_WHITE 0xFFFFFF
# define COLOR_BLACK 0x000000

typedef struct s_window_vars
{
	void		*mlx;
	void		*window;
}				t_window_vars;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_imgdata;

typedef struct s_fpoint
{
	double	real;
	double	i;
}				t_fpoint;

typedef struct s_fractal
{
	t_window_vars	win;
	t_imgdata		img;
	double			offset_x;
	double			offset_y;
	double			zoom;
	t_fpoint		julia;
}				t_fractal;

typedef struct s_screenpnt
{
	int	x;
	int	y;
}			t_screenpnt;

void		handle_iter(int x, int y, t_fractal *fractal);
void		render(t_fractal *fractal);
void		my_mlx_pixel_put(t_imgdata img, int x, int y, int color);
int			get_color(int iter);
t_fpoint	fractal_sum(t_fpoint z1, t_fpoint z2);
t_fpoint	fractal_sqr(t_fpoint z);
double		atoi_double(char *str);
double		normalize(double un_number, double new_min, double new_max,
				double old_max);

#endif