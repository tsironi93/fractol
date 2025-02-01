/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:52:03 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/01 19:38:18 by itsiros          ###   ########.fr       */
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

// static int	close(int keycode, t_window_vars *vars)
// {
// 	if (keycode == ESC_KEY_MAC)
// 	{
// 		mlx_destroy_window(vars->mlx, vars->window);
// 		exit (0);

// 	}
// 	return 0;
// }

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
		//mlx_hook(vars.window, 2, 1L << 0, close, &vars);
		//mlx_hook(vars.window, 17, 1L << 17, close, &vars);
	// if (!strcmp(av[1], "Mandelbrot"))
	// 	draw_mandelbrot(fractal.img.img);
	render(&fractal);
	mlx_loop(fractal.win.mlx);
}
