#include "something.h"
#include "ft_printf.h"
#include "mlx.h"

void	img_info(t_img image)
{
	ft_printf("whats inside our image structure:\n");
	ft_printf("img_ptr	:	[%p]\n", image.img_ptr);
	ft_printf("bpp		:	[%d]\n", image.bpp);
	ft_printf("line_len	:	[%d]\n", image.line_len);
	ft_printf("endian	:	[%d]\n", image.endian);
	ft_printf("addr		:	[%p]\n", image.addr);
}

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), &(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	img_info(image);
	return (image);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *) dst = color;
}

void	draw_square(t_square square, t_img img)
{
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while(i < square.size && i + square.y < img.h)
	{
		j = 0;
		while (j < square.size && j + square.x < img.w)
		{
			put_pixel_img(img, j + square.x, i + square.y, square.color);
			j++;
		}
		i++;
	}
}
