/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:20:02 by adstan            #+#    #+#             */
/*   Updated: 2017/12/09 18:21:39 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		fff(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*c;

	i = 0;
	if (s)
	{
		if ((c = (char *)malloc(fff(s) + 1)))
		{
			i = 0;
			while (s[i])
			{
				c[i] = f(i, s[i]);
				i++;
			}
			c[i] = 0;
			return (c);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
