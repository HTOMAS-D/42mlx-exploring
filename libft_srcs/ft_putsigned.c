/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:10:31 by htomas-d          #+#    #+#             */
/*   Updated: 2022/04/08 10:27:12 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putsigned(t_print *tab)
{
	char	*str;
	int		temp;

	temp = va_arg(tab->args, int);
	str = ft_itoa(temp);
	tab->lentot += write (1, str, ft_strlen(str));
	free (str);
}
