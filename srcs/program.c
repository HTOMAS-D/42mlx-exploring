#include "mlx.h"
#include "something.h"

t_win	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, h, h, str), w, h});
}

int	exit_program(t_win *window)
{
	if (window)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	}
	exit(EXIT_SUCCESS);
}
