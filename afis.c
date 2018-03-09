/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:58:10 by adstan            #+#    #+#             */
/*   Updated: 2018/03/09 19:03:01 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		main_afis(t_dlist *list)
{
	long c;
	struct winsize w;
	struct winsize z;

	ioctl(0, TIOCGWINSZ, &w);
	printing(list);
	while(1)
	{
		c = 0;
		ioctl(0, TIOCGWINSZ, &z);
		if ((z.ws_col != w.ws_col) || (z.ws_row != w.ws_row))
		{
			w = z;
			tputs(tgetstr("cl", NULL), 1, &ft_printnbr);
			printing(list);
		}
		read(0, &c, 8);
		if (c == ENTER_KEY || c == UP_KEY || c == DOWN_KEY || c == LEFT_KEY
			|| c == RIGHT_KEY || c == ESC_KEY || c == BKP_KEY || c == DEL_KEY || c == SPACE_KEY)
		{
			if ((take_actions(c)))
			{
				restore();
				return ;
			}
			if (list->last == 2)
				list = list->next;
			tputs(tgetstr("cl", NULL), 1, &ft_printnbr);
//			ft_putnbr_fd(g_term.argc, 0);
			printing(list);
		}
	}
}


int			get_max(int len, int what)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	if (what == 1)
		return (w.ws_col / len);
	else if (what == 2)
		return (w.ws_row / len);
	else if (what == 3)
		return (w.ws_row);
	else
		return (w.ws_col);
}

int		ft_printnbr(int nbr)
{
	return (write(STDERR_FILENO, &nbr, 1));
}

void		ft_print(t_dlist *start)
{
	ft_putchar_fd(start->name[0], 0);
	if (g_term.current == start)
		ft_putstr_fd("\e[4m", 0);
	if (start->selected % 2)
	{
		ft_putstr_fd("\e[41m", 0);
		ft_putstr_fd("\e[30m", 0);
	}
	else
	{
		ft_putstr_fd("\e[49m", 0);
		ft_putstr_fd("\e[31m", 0);
	}
	ft_putstr_fd(ft_strsub(start->name, 1, ft_strlen(start->name) - 2), 0);
	ft_putstr_fd("\e[0m", 0);
	ft_putchar_fd(start->name[ft_strlen(start->name) - 1], 0);
}

void		printing(t_dlist *start)
{
	int		cols;
	int		rows;
	int		count = 1;
	int		i;
	int		j;

	cols = get_max(ft_strlen(start->name), 1);
	if (!cols)
		return ;
	rows = g_term.argc / cols;
	if (g_term.argc % cols)
		rows++;
	i = -1;
	if (rows > get_max(1,3))
		return ;
	while (++i <= rows && count)
	{
		j = -1;
		while (++j < cols && count)
		{
			ft_print(start);
			start->rows = rows;
			start->i = i;
			start->j = j;
			if (start->last)
				count = 0;
			start = start->next;
		}
		ft_putchar_fd('\n', 0);
	}
}
