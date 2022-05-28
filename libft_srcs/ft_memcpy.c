/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:55:19 by htomas-d          #+#    #+#             */
/*   Updated: 2022/03/04 17:01:23 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//copy a block of date from one memory adress to another

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < len)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}

/*int main()
{
    char src[] = "henrique";
    char dest [9];
    ft_memcpy(dest, src, sizeof(char) * 9);
    //memcpy(dest, src, sizeof(char) * 9);
    printf("%s", dest);

}*/
