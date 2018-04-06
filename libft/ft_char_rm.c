/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_rm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:20:06 by adstan            #+#    #+#             */
/*   Updated: 2018/02/25 18:56:51 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_char_rm(char *str, char c)
{
	int		i;
	int		nr;
	char	*new;

	i = 0;
	nr = 0;
	while (str[i])
	{
		if (str[i] == c)
			nr++;
		i++;
	}
	if (!(new = (char*)ft_memalloc(sizeof(char) * (i + 1 - nr))))
		ft_putendl_fd(M_ERROR, 2);
	i = 0;
	nr = 0;
	while (str[i])
	{
		if (str[i] != c)
			new[nr++] = str[i];
		i++;
	}
	if (str)
		free(str);
	return (new);
}
