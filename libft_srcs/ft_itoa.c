/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:02:04 by htomas-d          #+#    #+#             */
/*   Updated: 2022/04/06 12:59:36 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	newstrlen(long c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	else if (c < 0)
	{
		c *= -1;
		i++;
	}
	while (c > 0)
	{
		c /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int c)
{
	char	*res;
	int		i;
	long	numb;

	numb = c;
	i = newstrlen(numb);
	res = (char *)malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	if (numb < 0)
	{
		res[0] = '-';
		numb *= -1;
	}
	else if (numb == 0)
		res[0] = '0';
	res[i] = '\0';
	while (numb > 0)
	{
		res[i - 1] = numb % 10 + '0';
		numb /= 10;
		i--;
	}
	return (res);
}
