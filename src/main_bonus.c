/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:52:03 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/24 17:08:48 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	initialize(t_fractal *fractal)
{
	fractal->win.mlx = mlx_init();
	if (!fractal->win.mlx)
		exit(EXIT_FAILURE);
	fractal->win.window = mlx_new_window(fractal->win.mlx, WIDTH,
			HEIGHT, fractal->set);
	if (!fractal->win.window)
		exit(EXIT_FAILURE);
	fractal->img.img = mlx_new_image(fractal->win.mlx, WIDTH, HEIGHT);
	if (fractal->img.img == NULL)
		exit(EXIT_FAILURE);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bits_per_pixel,
			&fractal->img.line_length, &fractal->img.endian);
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	fractal->zoom = 1.0;
	fractal->color_shift = 0;
	fractal->grid_high = 2.0;
	fractal->grid_low = -2.0;
}

static int	close_x(t_fractal *fractal)
{
	(void)fractal;
	exit(EXIT_SUCCESS);
}

static int	handle_key(int keycode, t_fractal *fractal)
{
	if (keycode == ESC_KEY_MAC)
		close_x(fractal);
	else if (keycode == ARROW_UP)
		fractal->offset_y += 0.1;
	else if (keycode == ARROW_DOWN)
		fractal->offset_y -= 0.1;
	else if (keycode == ARROW_LEFT)
		fractal->offset_x += 0.1;
	else if (keycode == ARROW_RIGHT)
		fractal->offset_x -= 0.1;
	else if (keycode == KEY_C)
		fractal->color_shift += 5;
	render(fractal);
	return (0);
}

static int	handle_mouse(int keycode, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	mouse_x = normalize(x, fractal->grid_low, fractal->grid_high, WIDTH);
	mouse_y = normalize(y, fractal->grid_low, fractal->grid_high, HEIGHT);
	zoom_factor = 1.2;
	if (keycode == MOUSE_WHEEL_DOWN)
	{
		fractal->grid_high /= zoom_factor;
		fractal->grid_low /= zoom_factor;
	}
	else if (keycode == MOUSE_WHEEL_UP)
	{
		fractal->grid_high *= zoom_factor;
		fractal->grid_low *= zoom_factor;
	}
	fractal->offset_x += (mouse_x * zoom_factor) - mouse_x;
	fractal->offset_y -= (mouse_y * zoom_factor) - mouse_y;
	fractal->zoom = zoom_factor;
	return (render(fractal));
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	check_params(ac, av);
	fractal.set = av[1];
	if (!ft_strcmp(av[1], "Julia"))
	{
		fractal.julia.real = atoi_double(av[2]);
		fractal.julia.i = atoi_double(av[3]);
	}
	initialize(&fractal);
	mlx_hook(fractal.win.window, 2, 1L << 0, handle_key, &fractal);
	mlx_hook(fractal.win.window, 17, 1L << 17, close_x, &fractal);
	mlx_mouse_hook(fractal.win.window, handle_mouse, &fractal);
	mlx_loop_hook(fractal.win.mlx, render, &fractal);
	render(&fractal);
	mlx_loop(fractal.win.mlx);
	exit(EXIT_SUCCESS);
}
