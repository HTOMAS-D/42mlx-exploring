#include "something.h"

int	get_color()
{
	return (rand() % 2147483647);
}

int	read_keys(int	keypressed, void *param)
{
	t_img	*img;

	img = (t_img *) param;
	if (key_pressed == ESC || !img)
		exit_program(&img->win);
	else if (key_pressed == ENTER)
		draw_square((t_square){0, 0, img->2, 0xFFFFFF}, *img);
	else if (key pressed == FOLLOW)
		follow = !follow;
}
