/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:55:21 by adstan            #+#    #+#             */
/*   Updated: 2017/12/09 11:37:39 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*roman;

	i = 0;
	roman = (char *)s;
	while (roman[i])
		i++;
	while (i >= 0)
	{
		if (roman[i] == c)
			return (&roman[i]);
		i--;
	}
	return (NULL);
}
