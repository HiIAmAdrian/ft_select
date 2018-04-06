/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:39:32 by adstan            #+#    #+#             */
/*   Updated: 2017/12/09 11:56:04 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	int		j;
	char	*kk;

	i = 0;
	kk = (char *)str;
	if (to_find[0] == 0)
		return (kk);
	while (kk[i] && i < len)
	{
		j = 0;
		while (kk[i + j] == to_find[j] && i + j < len)
		{
			j++;
			if (to_find[j] == '\0')
				return (&kk[i]);
		}
		i++;
	}
	return (NULL);
}
