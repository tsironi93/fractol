//				TO DO
//	1). REFACTOR MY SCREEN
//  2).	SET UP THE ALGORITHM FUNCTION	x^2 - y^2 + 2*x*y*i
//	3).	LEARN AND IMPLIMENT COLORS
//	4).	LEARN ABOUT LOOPS AND SYNC


//Function needs to take in any position height and width
//and normalize the value to the screen

typedef struct s_point{
	float	x;
	float	y;
}				t_point;

#include "../fractol.h"

int	normalize(t_point pnt)
{
	int	m_height;
	int	m_width;

	m_height = HEIGHT;
	m_width = WIDTH;

	//So if point is (0,0) in the screen should be (400,400) since Mandelbrot starts for -0.2 to 0.2

	pnt.x = pnt.x * m_width + 400;
	pnt.y = pnt.y * m_height + 400;

	printf ("x:%f--->y:%f", pnt.x, pnt.y);
	return (0);
}

int main()
{
	t_point	point;

	point.x = -0.2;
	point.y = -0.2;

	normalize(point);
	return (0);
}