/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:04:12 by adstan            #+#    #+#             */
/*   Updated: 2018/01/07 15:09:42 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *p;
	t_list *f;

	f = *alst;
	while (f)
	{
		p = f;
		f = f->next;
		del(p->content, p->content_size);
		free(p);
	}
	*alst = NULL;
}
