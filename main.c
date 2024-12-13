#include "./mlx/mlx.h"

int main()
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 720, "Hello malaka");
	mlx_loop(mlx);
}
