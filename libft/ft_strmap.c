/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:01:16 by adstan            #+#    #+#             */
/*   Updated: 2017/12/09 18:14:46 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ff(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*c;

	i = 0;
	if (s)
	{
		if ((c = (char *)malloc(ff(s) + 1)))
		{
			i = 0;
			while (s[i])
			{
				c[i] = f(s[i]);
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
