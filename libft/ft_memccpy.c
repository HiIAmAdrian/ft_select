/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:50:26 by adstan            #+#    #+#             */
/*   Updated: 2017/12/09 14:26:34 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpy;
	unsigned char	*cpy1;

	cpy = (unsigned char*)src;
	cpy1 = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		cpy1[i] = cpy[i];
		if (cpy[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
