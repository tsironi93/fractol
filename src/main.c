/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:52:03 by itsiros           #+#    #+#             */
/*   Updated: 2024/12/16 14:36:03 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	close(int keycode, t_window_vars *vars)
{
	if (keycode == ESC_KEY_MAC)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		exit (0);
	}
	return (0);
}

static void	my_mlx_pixel_put(t_imgdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	t_window_vars	vars;
	t_imgdata		img;

	if (argc == 2 && (!strcmp(argv[1], "Mandelbrot")
		|| !strcmp(argv[1], "Julia")))
	{
		printf("Its working!");
		vars.mlx = mlx_init();
		vars.window = mlx_new_window(vars.mlx, WIDTH, HEIGHT, argv[1]);
		mlx_hook(vars.window, 2, 1L<<0, close, &vars);
		img.img = mlx_new_image(vars.mlx, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
									&img.line_length, &img.endian);
		my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
		mlx_put_image_to_window(vars.mlx, vars.window, img.img, 0, 0);
		mlx_loop(vars.mlx);
	}
	else
		printf("pls select Mandelbrot or Julia");
	exit (0);
}