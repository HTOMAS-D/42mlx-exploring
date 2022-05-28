#ifndef SO_LONG_H
#define SO_LONG_H
#define	WIND_H 1080
#define WIND_W 1920
#include "ft_printf.h"
#include "mlx.h"

typedef	struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

#endif
