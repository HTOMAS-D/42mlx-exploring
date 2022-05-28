/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:10:19 by htomas-d          #+#    #+#             */
/*   Updated: 2022/04/08 10:21:50 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putunsigned(t_print *tab)
{
	long	temp;
	char	*str;

	temp = va_arg(tab->args, unsigned int);
	str = ft_utoa(temp);
	tab->lentot += write(1, str, ft_strlen(str));
	free(str);
}
