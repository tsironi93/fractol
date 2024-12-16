/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:37:09 by itsiros           #+#    #+#             */
/*   Updated: 2024/12/16 14:38:26 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define	FRACTOL_H

#include "./mlx/mlx.h"
#include <string.h>			//TO DO! IMPORT LIBFT
#include <stdio.h>			//TESTING
#include <math.h>
#include <stdlib.h>

#define HEIGHT 800
#define WIDTH 800

#define ESC_KEY_MAC 53

typedef struct s_window_vars{
	void	*mlx;
	void	*window;
}				t_window_vars;

typedef struct s_imgdata {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_imgdata;



#endif