/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:31:05 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/03 16:53:02 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//				TO DO
//	3).	LEARN AND IMPLIMENT COLORS
//	4).	LEARN ABOUT LOOPS AND SYNC


//Function needs to take in any position height and width
//and normalize the value to the screen

#include "../fractol.h"

static double	normalize(double un_number, double new_min, double new_max,
	double old_max)
{
	return ((((new_max - new_min) * un_number) / old_max) + new_min);
}

void	handle_iter(int x, int y, t_fractal *fractal)
{
	int			color;
	int			iter;
	t_fpoint	z;
	t_fpoint	c;

	z.real = 0.0;
	z.i = 0.0;
	c.real = normalize(x, -2, 2, WIDTH);
	c.i = normalize(y, 2, -2, HEIGHT);
	iter = 0;
	while (iter < MAX_ITER)
	{
		z = fractal_sum(fractal_sqr(z), c);
		if ((z.real * z.real + z.i * z.i) > 4)
		{
			//color = normalize(iter, COLOR_BLACK, COLOR_WHITE, MAX_ITER);
			color = get_color(iter);
			my_mlx_pixel_put(fractal->img, x, y, color);
			return ;
		}
		iter++;
	}
	my_mlx_pixel_put(fractal->img, x, y, COLOR_BLACK);
}

void	my_mlx_pixel_put(t_imgdata img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *)(img.bits_per_pixel + dst) = color;
}

void	render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_iter(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->win.mlx, fractal->win.window,
		fractal->img.img, 0, 0);
}

int	get_color(int iter)
{
	double t = (double)iter / MAX_ITER;
	int r = (int)(9 * (1 - t) * t * t * t * 255);
	int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}
