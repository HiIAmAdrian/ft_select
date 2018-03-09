/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:27:11 by adstan            #+#    #+#             */
/*   Updated: 2018/03/01 17:34:29 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		longest_string(t_dlist *start)
{
	t_dlist *tmp;
	int		max;

	tmp = start;
	max = ft_strlen(start->name);
	while (tmp->next != start)
	{
		if (ft_strlen(tmp->name) > max)
			max = ft_strlen(tmp->name);
		tmp = tmp->next;
	}
	if (ft_strlen(tmp->name) > max)
		max = ft_strlen(tmp->name);
	return (max);
}

int		double_length(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*string_spaces(int size)
{
	char	*str;
	int		i;

	i = -1;
	str = (char*)ft_memalloc(sizeof(char) * (size + 1));
	while (++i < size)
		str[i] = ' ';
	return (str);
}

void	put_spaces(t_dlist *start)
{
	t_dlist *tmp;
	char	*cpy;
	int		max;
	int		i;
	int		count;

	count = 1;
	max = longest_string(start);
	tmp = start;
	while (count)
	{
		cpy = string_spaces(max - ft_strlen(tmp->name));
		tmp->name = ft_strjoin(tmp->name, cpy);
		free(cpy);
		tmp->name = ft_strjoin("[ ",tmp->name);
		tmp->name = ft_strjoin(tmp->name," ]");
		if (tmp->last == 1)
			count = 0;
		tmp = tmp->next;
	}
}


