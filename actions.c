/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 17:51:33 by adstan            #+#    #+#             */
/*   Updated: 2018/03/26 16:11:46 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	up(void)
{
	int		i;
	int		j;
	t_dlist	*tmp;

	i = get_max(ft_strlen(g_term.current->name), 1) + 1;
	if (g_term.current->i == 0)
	{
		while (g_term.current->i < (g_term.current->rows - 1) &&
				!g_term.current->last)
		{
			j = g_term.current->j;
			tmp = g_term.current;
			g_term.current = g_term.current->next;
			while (g_term.current->j != j && !g_term.current->last)
				g_term.current = g_term.current->next;
			if (g_term.current->j == j)
				tmp = g_term.current;
		}
		g_term.current = tmp;
	}
	else
		while (--i > 0)
			g_term.current = g_term.current->prev;
}

void	help_down(void)
{
	int	j;

	j = g_term.current->j;
	while (g_term.current->i >= 0)
	{
		g_term.current = g_term.current->prev;
		if (g_term.current->j == j && !g_term.current->i)
			break ;
	}
}

void	down(void)
{
	int		i;
	int		j;

	i = get_max(ft_strlen(g_term.current->name), 1) + 1;
	if (g_term.current->i == (g_term.current->rows - 1))
	{
		j = g_term.current->j;
		while (g_term.current->i >= 0)
		{
			g_term.current = g_term.current->prev;
			if (g_term.current->j == j && !g_term.current->i)
				break ;
		}
	}
	else if (return_j_last_nod() < g_term.current->j &&
			g_term.current->i == g_term.current->rows - 2)
		help_down();
	else
		while (--i > 0)
			g_term.current = g_term.current->next;
}

void	delete_it(void)
{
	if ((*g_term.curraddr) == g_term.start)
		g_term.start = g_term.start->next;
	(*g_term.curraddr)->prev->next = (*g_term.curraddr)->next;
	(*g_term.curraddr)->next->prev = (*g_term.curraddr)->prev;
	if (g_term.current->prev->last == 1)
	{
		(*g_term.curraddr)->last = 2;
		(*g_term.curraddr) = (*g_term.curraddr)->next;
	}
	else if (g_term.current->last)
	{
		(*g_term.curraddr)->prev->last = 1;
		(*g_term.curraddr) = (*g_term.curraddr)->prev;
	}
	else
		(*g_term.curraddr) = (*g_term.curraddr)->next;
	g_term.argc--;
	if (g_term.argc == 0)
	{
		restore();
		exit(0);
	}
}

int		take_actions(long c)
{
	g_term.curraddr = &g_term.current;
	if (c == ENTER_KEY || c == ESC_KEY)
		return (1);
	else if (c == SPA_KEY)
	{
		(*g_term.curraddr)->selected++;
		g_term.current = g_term.current->next;
	}
	else if (c == LEFT_KEY)
		g_term.current = g_term.current->prev;
	else if (c == RIGHT_KEY)
		g_term.current = g_term.current->next;
	else if (c == UP_KEY && g_term.current->rows != 1)
		up();
	else if (c == DOWN_KEY && g_term.current->rows != 1)
		down();
	else if (c == DEL_KEY || c == BKP_KEY)
		delete_it();
	return (0);
}
