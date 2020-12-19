#include "mlx.h"

int main()
{

	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window( mlx_ptr, 500,500, "ww");
	mlx_loop(mlx_ptr);
}
