/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:08:13 by adstan            #+#    #+#             */
/*   Updated: 2018/02/22 19:24:37 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	char	*kk;

	i = 0;
	kk = (char *)str;
	if (to_find[0] == 0)
		return (kk);
	while (kk[i])
	{
		j = 0;
		while (kk[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
				return (&kk[i]);
		}
		i++;
	}
	return (NULL);
}
