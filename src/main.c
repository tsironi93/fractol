/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:52:03 by itsiros           #+#    #+#             */
/*   Updated: 2024/12/15 19:03:47 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2 && (!strcmp(argv[1], "Mandelbrot")
		|| !strcmp(argv[1], "Julia")))
	{
		printf("Its working!");
	}
	else
	{
		printf("pls select Mandelbrot or Julia");
	}
	return (0);
}

// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1080, 720, "Hello malaka");
// 	mlx_loop(mlx);