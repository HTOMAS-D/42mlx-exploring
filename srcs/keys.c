#include "something.h"
#include "mlx.h"

int	follow = 0;
int	size  = 10;

int	get_color()
{
	return (rand() % 2147483647);
}

int	read_keys(int	key_pressed, void *param)
{
	t_img	*img;

	img = (t_img *) param;
	if (key_pressed == ESC || !img)
		exit_program(&img->win);
	else if (key_pressed == ENTER)
		draw_square((t_square){0, 0, img->w, 0xFFFFFF}, *img);
	else if (key_pressed == FOLLOW)
		follow = !follow;
//	else if (key_pressed == COLOR)
//		color = get_color();
//	else if (key_pressed == PENGUIN)
//		penguin(*img);
	else
		return (-1);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
	return (0);

}

int	read_mouse(int button, int mouse_x, int mouse_y, void *param)
{
	int	x;
	int	y;
	t_img	*img;
	t_square	s;

	img = (t_img *) param;
	if(!img)
		return (-1);
	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->w || mouse_y > img->h)
		return (2);
	x = ((mouse_x % img->w) / size) * size;
	y = ((mouse_y % img->h) / size) * size;
	s = (t_square){x, y, size, color};
	draw_square(s, *img);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
	(void)button;
	return (0);
}
