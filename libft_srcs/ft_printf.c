/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:23:08 by htomas-d          #+#    #+#             */
/*   Updated: 2022/04/21 10:50:55 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<unistd.h>
#include<stdio.h>

static t_print	ft_initialise_tab(t_print *tab)
{
	tab->lentot = 0;
	return (*tab);
}

static void	ft_format(char format, t_print *tab)
{
	if (format == 'c')
		ft_putchar(tab);
	else if (format == 's')
		ft_putstr(tab);
	else if (format == 'p')
		ft_putptr(tab);
	else if (format == 'd' || format == 'i')
		ft_putsigned(tab);
	else if (format == 'u')
		ft_putunsigned(tab);
	else if (format == 'x')
		ft_putex(tab);
	else if (format == 'X')
		ft_putexup(tab);
	else if (format == '%')
		tab->lentot += write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	t_print	*tab;
	int		index;
	int		ret;

	index = 0;
	ret = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, str);
	while (str[index])
	{
		if (str[index] == '%')
			ft_format(str[++index], tab);
		else
			ret += write(1, &str[index], 1);
		index++;
	}
	va_end(tab->args);
	ret += tab->lentot;
	free(tab);
	return (ret);
}
//int main()
//{
//	ft_printf("\n\e[0;31mWRONG NUMBER OF ARGUMENTS!\n\n");
//	return 0;
//}
