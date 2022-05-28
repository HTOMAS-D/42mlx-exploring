/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:10:40 by htomas-d          #+#    #+#             */
/*   Updated: 2022/04/08 10:30:26 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include <unistd.h>

void	ft_putchar(t_print *tab)
{
	unsigned char	c;

	c = (unsigned char)(va_arg(tab->args, int));
	tab->lentot += write(1, &c, 1);
}
