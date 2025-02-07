/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:52:03 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/05 17:31:44 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	initialize(t_fractal *fractal, char *set_name)
{
	fractal->win.mlx = mlx_init();
	if (!fractal->win.mlx)
		exit(EXIT_FAILURE);
	fractal->win.window = mlx_new_window(fractal->win.mlx, WIDTH,
			HEIGHT, set_name);
	if (!fractal->win.window)
	{
		//mlx_kill(fractal->win.mlx);
		free(fractal->win.mlx);
		exit(EXIT_FAILURE);
	}
	fractal->img.img = mlx_new_image(fractal->win.mlx, WIDTH, HEIGHT);
	if (fractal->img.img == NULL)
	{
		mlx_destroy_window(fractal->win.mlx, fractal->win.window);
		//mlx_kill(fractal->win.mlx);
		free(fractal->win.mlx);
		exit(EXIT_FAILURE);
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bits_per_pixel,
			&fractal->img.line_length, &fractal->img.endian);
}

static int	close_x(t_fractal *fractal)
{
	if (fractal->img.img)
		mlx_destroy_image(fractal->win.mlx, fractal->img.img);
	if (fractal->win.window)
		mlx_destroy_window(fractal->win.mlx, fractal->win.window);
	if (fractal->win.mlx)
		free(fractal->win.mlx);
	exit(EXIT_SUCCESS);
}

static int	handle_key(int keycode, t_fractal *fractal)
{
	if (keycode == ESC_KEY_MAC)
		close_x(fractal);
	else if (keycode == ARROW_UP)
		fractal->offset_y += 0.01;
	else if (keycode == ARROW_DOWN)
		fractal->offset_y -= 0.01;
	else if (keycode == ARROW_LEFT)
		fractal->offset_x += 0.01;
	else if (keycode == ARROW_RIGHT)
		fractal->offset_x -= 0.01;
	render(fractal);
	return (0);
}


static int	handle_mouse(int keycode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_WHEEL_DOWN)
		fractal->zoom = 1.05;
	if (keycode == MOUSE_WHEEL_UP)
		fractal->zoom = 0.95;
	render(fractal);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (!(ac == 2 && (!strcmp(av[1], "Mandelbrot")
				|| !strcmp(av[1], "Julia"))))
	{
		printf("Please select Mandelbrot or Julia\n");
		exit (EXIT_SUCCESS);
	}
	initialize(&fractal, av[1]);
	fractal.julia.real = atoi_double(av[2]);
	fractal.julia.i = atoi_double(av[3]);
	fractal.offset_x = 0.0;
	fractal.offset_y = 0.0;
	fractal.zoom = 1.0;
	mlx_hook(fractal.win.window, 2, 1L << 0, handle_key, &fractal);
	mlx_hook(fractal.win.window, 17, 1L << 17, close_x, &fractal);
	mlx_mouse_hook(fractal.win.window, handle_mouse, &fractal);
	render(&fractal);
	mlx_loop(fractal.win.mlx);
}
