/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:26:03 by adstan            #+#    #+#             */
/*   Updated: 2017/12/13 16:49:07 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss;
	unsigned char	*sss;

	i = 0;
	ss = (unsigned char *)s1;
	sss = (unsigned char *)s2;
	while (i < n && ss[i] == sss[i])
		i++;
	if (i == n)
		return (0);
	else
		return (ss[i] - sss[i]);
}
