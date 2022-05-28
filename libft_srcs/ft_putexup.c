/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putexup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:52:21 by htomas-d          #+#    #+#             */
/*   Updated: 2022/04/08 10:28:18 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_newstrlen(unsigned int temp)
{
	int	i;

	i = 0;
	while (temp > 15)
	{
		temp /= 16;
		i++;
	}
	return (i);
}

void	ft_putexup(t_print *tab)
{
	unsigned int	n;
	char			*a;
	int				i;
	unsigned int	temp;

	i = 0;
	n = va_arg(tab->args, int);
	temp = n;
	if (n < 0)
	{
		tab->lentot += write(1, "-", 1);
		n *= (-1);
		i++;
	}
	i = ft_newstrlen(temp);
	a = (char *)ft_calloc(i + 1, sizeof(char *));
	while (n >= 0 && i >= 0)
	{
		a[i--] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	tab->lentot += write(1, a, ft_strlen(a));
	free(a);
}
