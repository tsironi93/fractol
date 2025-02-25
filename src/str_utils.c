/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:39:43 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/25 16:27:47 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	check_syntax(char *str)
{
	int	dotflag;

	dotflag = 0;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			dotflag++;
			if (dotflag > 1)
				return (0);
		}
		else if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	check_params(int ac, char **av)
{
	if (ac == 2 && (!ft_strcmp(av[1], "Mandelbrot")))
		return ;
	else if (ac == 4 && (!ft_strcmp(av[1], "Julia")))
	{
		if (sqrt(pow(atoi_double(av[2]), 2) + pow(atoi_double(av[3]), 2)) < 1.4
			&& (check_syntax(av[2]) && check_syntax(av[3])))
			return ;
	}
	write(1, "Please select Mandelbrot or Julia\nFor Julia some valid "
		"arguments are:\n0.45 0.1428\n-0.70176 -0.3842\n"
		"-0.835 -0.2321\n-0.8 0.156\n-0.7269 0.1889\n", 149);
	exit (EXIT_SUCCESS);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

double	atoi_double(char *str)
{
	double	result;
	double	fraction;
	int		sign;
	double	divisor;

	result = 0.0;
	fraction = 0.0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	str++;
	while (*str != '.')
		result = result * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	divisor = 10.0;
	while (*str >= '0' && *str <= '9')
	{
		fraction += (*str++ - '0') / divisor;
		divisor *= 10.0;
	}
	return (sign * (result + fraction));
}
