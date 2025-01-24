/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:52:03 by itsiros           #+#    #+#             */
/*   Updated: 2025/01/24 21:22:47 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	close(int keycode, t_window_vars *vars)
{
	if (keycode == ESC_KEY_MAC)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_window_vars	vars;
	t_imgdata		img;

	if (argc == 2 && (!strcmp(argv[1], "Mandelbrot")
			|| !strcmp(argv[1], "Julia")))
	{
		vars.mlx = mlx_init();
		vars.window = mlx_new_window(vars.mlx, WIDTH, HEIGHT, argv[1]);
		mlx_hook(vars.window, 2, 1L << 0, close, &vars);
		mlx_hook(vars.window, 17, 1L << 17, close, &vars);
		img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
				&img.line_length, &img.endian);
		if (!strcmp(argv[1], "Mandelbrot"))
			draw_mandelbrot(&img);
		mlx_put_image_to_window(vars.mlx, vars.window, img.img, 0, 0);
		mlx_loop(vars.mlx);
	}
	else
		printf("Please select Mandelbrot or Julia\n");
	exit (EXIT_SUCCESS);
}
