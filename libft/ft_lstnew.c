/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:19:46 by adstan            #+#    #+#             */
/*   Updated: 2018/01/09 16:22:05 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstnew(char *content, size_t content_size)
{
	t_list *newelem;

	if ((newelem = (t_list*)malloc(sizeof(t_list))))
	{
		if (content)
		{
			if (!(newelem->content =
						(char*)malloc(sizeof(content) * content_size)))
			{
				free(newelem);
				return (NULL);
			}
			else
				ft_memcpy(newelem->content, content, content_size);
			newelem->content_size = content_size;
		}
		else
		{
			newelem->content = NULL;
			newelem->content_size = 0;
		}
		newelem->next = NULL;
		return (newelem);
	}
	return (NULL);
}
