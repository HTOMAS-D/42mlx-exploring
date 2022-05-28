#include "mlx.h"
#include "something.h"

int main()
{
	t_win	tutorial;
	t_img	image;

	tutorial = new_program(300, 300, "first image");
	if(!tutorial.win_ptr)
		return (2);
	image = new_img(300, 300, tutorial);
	draw_square((t_square){0, 0, 300, 0x00FF00}, image);
	mlx_put_image_to_window (image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);
	mlx_hook(tutorial.win_ptr, 17, 0, exit_program, &tutorial);
	mlx_loop(tutorial.mlx_ptr);
	return (0);
}