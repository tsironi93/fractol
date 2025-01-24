/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:37:09 by itsiros           #+#    #+#             */
/*   Updated: 2025/01/24 21:09:09 by itsiros          ###   ########.fr       */
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
# define MAX_ITER 500

# define ESC_KEY_MAC 53

typedef struct s_window_vars
{
	void	*mlx;
	void	*window;
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
	float	real;
	float	i;
}				t_fpoint;

typedef struct s_screenpnt
{
	int	x;
	int	y;
}			t_screenpnt;

void	draw_mandelbrot(t_imgdata *img);
int		mandelbrot(t_fpoint c);
void	my_mlx_pixel_put(t_imgdata *data, int x, int y, int color);
int		get_color(int iter);

#endif