/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:30:52 by adstan            #+#    #+#             */
/*   Updated: 2018/02/22 20:15:23 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	j;

	i = start;
	j = 0;
	if (s)
	{
		if ((str = (char *)ft_memalloc(len + 1)))
		{
			while (j < len)
			{
				str[j] = s[i];
				i++;
				j++;
			}
			return (str);
		}
		if (str)
			free(str);
	}
	return (NULL);
}
