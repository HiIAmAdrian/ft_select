/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:48:59 by adstan            #+#    #+#             */
/*   Updated: 2018/03/01 17:12:05 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	if (s1 && s2)
	{
		if ((s3 = (char *)ft_memalloc(sizeof(char) *
						(ft_strlen(s1) + ft_strlen(s2) + 1))))
		{
			while (s1[i])
			{
				s3[i] = s1[i];
				i++;
			}
			j = 0;
			while (s2[j])
				s3[i++] = s2[j++];
			return (s3);
		}
		if (s3)
			free(s3);
	}
	return (NULL);
}
