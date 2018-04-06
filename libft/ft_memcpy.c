/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:40:57 by adstan            #+#    #+#             */
/*   Updated: 2017/12/09 11:07:11 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*cpy;
	char	*cpy1;

	cpy = (char*)src;
	cpy1 = (char*)dst;
	i = 0;
	while (i < n)
	{
		cpy1[i] = cpy[i];
		i++;
	}
	return (dst);
}
