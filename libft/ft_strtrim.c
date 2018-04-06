/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:07:53 by adstan            #+#    #+#             */
/*   Updated: 2018/02/22 19:24:17 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	functie(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static int	sf(char const *s)
{
	int i;

	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*c;
	int		inceput;
	int		sfarsit;
	int		size;

	if (s)
	{
		inceput = functie(s);
		sfarsit = sf(s);
		size = sfarsit - inceput;
		if (size < 1)
			size = 1;
		if ((c = (char *)ft_memalloc(size + 2)))
		{
			i = 0;
			while (inceput <= sfarsit)
				c[i++] = s[inceput++];
			return (c);
		}
		if (c)
			free(c);
	}
	return (NULL);
}
