/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:04:10 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/07 19:33:51 by itsiros          ###   ########.fr       */
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
