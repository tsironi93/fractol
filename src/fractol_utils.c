//				TO DO
//	1). REFACTOR MY SCREEN										√
//  2).	SET UP THE ALGORITHM FUNCTION	x^2 - y^2 + 2*x*y*i
//	3).	LEARN AND IMPLIMENT COLORS
//	4).	LEARN ABOUT LOOPS AND SYNC


//Function needs to take in any position height and width
//and normalize the value to the screen

#include "../fractol.h"

t_screenpnt	normalize(t_fpoint point)
{
	t_screenpnt	screen;

	screen.x = (int)((point.real - (-0.2)) / (-0.4) * WIDTH);
	screen.y = HEIGHT - (int)((point.i - (-0.2)) / (-0.4) * HEIGHT);
	return (screen);
}

int	mandelbrot(t_fpoint c)
{
	int			iter;
	t_fpoint	tmp;
	t_fpoint	z;

	z.real = 0;
	z.i = 0;
	iter = 0;
	while (iter < MAX_ITER && (z.real * z.real + z.i * z.i) <= 4)
	{
		tmp.real = z.real * z.real - z.i * z.i + c.real;
		tmp.i = 2 * z.real * z.i + c.i;
		z = tmp;
		iter++;
	}
	return (iter);
}

void	my_mlx_pixel_put(t_imgdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_mandelbrot(t_imgdata *img)
{
    int			x, y;
    t_fpoint	c;
    int			iter;
    t_screenpnt	screen;

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            c.real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            c.i = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            iter = mandelbrot(c);
            screen.x = x;
            screen.y = y;
            if (iter == MAX_ITER)
                my_mlx_pixel_put(img, screen.x, screen.y, 0x000000); // Black for points in the set
            else
                my_mlx_pixel_put(img, screen.x, screen.y, get_color(iter)); // Color based on iteration count
        }
    }
}

int	get_color(int iter)
{
    // Simple coloring function based on iteration count
    return (0x00FF00 + (iter * 255 / MAX_ITER) * 0x00010101);
}

// int	main(void)
// {
// 	t_fpoint	point;

// 	point.x = -0.2;
// 	point.y = -0.2;

// 	t_screenpnt screen = normalize(point);
// 	printf("%d\n%d\n", screen.x, screen.y);
// 	return (0);
// }
