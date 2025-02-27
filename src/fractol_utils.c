/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:31:05 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/24 10:14:16 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	choose_set(t_fpoint *c, t_fpoint *z, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->set, "Julia"))
	{
		c->i = fractal->julia.i;
		c->real = fractal->julia.real;
	}
	else
	{
		c->i = z->i;
		c->real = z->real;
	}
}

void	handle_iter(int x, int y, t_fractal *fractal)
{
	int			color;
	int			iter;
	t_fpoint	z;
	t_fpoint	c;

	z.real = normalize(x, fractal->grid_low,
			fractal->grid_high, WIDTH) + fractal->offset_x;
	z.i = normalize(y, fractal->grid_low,
			fractal->grid_high, HEIGHT) + fractal->offset_y;
	choose_set(&c, &z, fractal);
	iter = 0;
	while (iter < MAX_ITER)
	{
		z = fractal_sum(fractal_sqr(z), c);
		if ((z.real * z.real + z.i * z.i) > 4)
		{
			color = get_color(iter, fractal->color_shift);
			my_mlx_pixel_put(fractal->img, x, y, color);
			return ;
		}
		iter++;
	}
	my_mlx_pixel_put(fractal->img, x, y, get_color(iter, fractal->color_shift));
}

void	my_mlx_pixel_put(t_imgdata img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_iter(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->win.mlx, fractal->win.window,
		fractal->img.img, 0, 0);
	return (0);
}
