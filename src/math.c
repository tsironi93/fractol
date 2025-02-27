/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:04:10 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/09 23:21:13 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_fpoint	fractal_sum(t_fpoint z1, t_fpoint z2)
{
	t_fpoint	sum;

	sum.real = z1.real + z2.real;
	sum.i = z1.i + z2.i;
	return (sum);
}

t_fpoint	fractal_sqr(t_fpoint z)
{
	t_fpoint	res;

	res.real = (z.real * z.real) - (z.i * z.i);
	res.i = 2 * z.real * z.i;
	return (res);
}

double	normalize(double un_number, double new_min, double new_max,
	double old_max)
{
	return ((((new_max - new_min) * un_number) / old_max) + new_min);
}

int	get_color(int iter, int color_shift)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == MAX_ITER)
		return (COLOR_BLACK);
	t = (double)iter / MAX_ITER;
	r = (int)(9 * (1 - t) * t * t * t * 255) + color_shift;
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255) + color_shift;
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255) + color_shift;
	r %= 256;
	g %= 256;
	b %= 256;
	return (r << 16 | g << 8 | b);
}
