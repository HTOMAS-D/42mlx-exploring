#ifndef SOMETHING_H
#define SOMETHING_H
#include "ft_printf.h"

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	height;
	int	width;
}	t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int	h;
	int	w;
	int	bpp;
	int	endian;
	int	line_len;
}	t_img;

typedef struct s_square
{
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int	size;
	int	color;
}	t_square;

//IMAGE FUNCTIONS

t_img	new_img(int w, int h, t_win window);

void	img_info(t_img image);

void	put_pixel_img(t_img img, int x, int y, int color);

void	draw_square(t_square square, t_img img);

//PROGRAM FUNCTIONS

t_win	new_program(int w, int h, char *str);

int	exit_program(t_win *window);

#endif
