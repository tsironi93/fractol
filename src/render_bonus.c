/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:55:46 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/24 19:28:03 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_imgdata img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	sierpinski(t_fractal *fractal, double x, double y, int size, int depth)

{
	int		i;
	int		j;
	double	n_size;

	i = 0;
	j = 0;
	if (depth == 0)
		while (i++ < size)
			while (j++ < size)
				my_mlx_pixel_put(fractal->img, x + j, y + i, 0xFFFFFF);
	else
	{
		n_size = size / 3.0;
		i = -1;
		while (++i < 3)
		{
			j = -1;
			while (++j < 3)
			{
				if (i == 1 && j == 1)
					continue ;
				sierpinski(fractal, x + i * n_size, y + j * n_size, n_size, depth - 1);
			}
		}
	}
}

int	render_sierpinski(t_fractal *fractal)
{
	double	size;
	double	x_offset;
	double	y_offset;

	mlx_destroy_image(fractal->win.mlx, fractal->img.img);
	fractal->img.img = mlx_new_image(fractal->win.mlx, WIDTH, HEIGHT);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bits_per_pixel, &fractal->img.line_length,
			&fractal->img.endian);
	size = 800 * fractal->zoom;
	x_offset = fractal->offset_x * WIDTH;
	y_offset = fractal->offset_y * HEIGHT;
	sierpinski(fractal, 0, 0, size, 6);
	mlx_put_image_to_window(fractal->win.mlx, fractal->win.window,
		fractal->img.img, 0, 0);
	return (0);
}
