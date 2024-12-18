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

	screen.x = (int)((point.x - (-0.2)) / (-0.4) * WIDTH);
	screen.y = HEIGHT - (int)((point.y - (-0.2)) / (-0.4) * HEIGHT);
	return (screen);
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
