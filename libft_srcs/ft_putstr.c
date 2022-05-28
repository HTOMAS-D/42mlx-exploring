/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:06:59 by htomas-d          #+#    #+#             */
/*   Updated: 2022/04/08 11:05:00 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putstr(t_print *tab)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(tab->args, char *);
	if (str == NULL)
	{
		tab->lentot += write(1, "(null)", 6);
		return ;
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	tab->lentot += i;
}
