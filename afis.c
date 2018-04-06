/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:58:10 by adstan            #+#    #+#             */
/*   Updated: 2018/03/26 17:36:35 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		main_afis(t_dlist *list)
{
	struct winsize	w;
	struct winsize	z;
	long			c;

	ioctl(0, TIOCGWINSZ, &w);
	calc_rows_cols(list);
	c = 0;
	z = w;
	loop_afis(list, c, w, z);
}

void		loop_afis(t_dlist *list, int c, struct winsize w, struct winsize z)
{
	while (1)
	{
		c = 0;
		ioctl(0, TIOCGWINSZ, &z);
		if ((z.ws_col != w.ws_col) || (z.ws_row != w.ws_row))
		{
			w = z;
			tputs(tgetstr("cl", NULL), 1, &ft_printnbr);
			calc_rows_cols(list);
		}
		read(0, &c, 8);
		if (c == ENTER_KEY || c == UP_KEY || c == DOWN_KEY || c == LEFT_KEY ||
c == RIGHT_KEY || c == ESC_KEY || c == BKP_KEY || c == DEL_KEY || c == SPA_KEY)
		{
			if ((take_actions(c)))
			{
				restore();
				return ;
			}
			if (list->last == 2)
				list = list->next;
			tputs(tgetstr("cl", NULL), 1, &ft_printnbr);
			calc_rows_cols(list);
		}
	}
}

void		ft_print(t_dlist *start)
{
	ft_putchar_fd(start->name[0], 0);
	if (g_term.current == start)
		ft_putstr_fd("\e[4m", 0);
	if (start->selected % 2)
	{
		start->ftype == 'b' ? ft_putstr_fd("\e[43m", 0) : (0);
		start->ftype == 'd' ? ft_putstr_fd("\e[46m", 0) : (0);
		start->ftype == 'r' ? ft_putstr_fd("\e[41m", 0) : (0);
		start->ftype == 'l' ? ft_putstr_fd("\e[45m", 0) : (0);
		start->ftype == 's' ? ft_putstr_fd("\e[42m", 0) : (0);
		start->ftype == 'c' ? ft_putstr_fd("\e[44m", 0) : (0);
		ft_putstr_fd("\e[30m", 0);
	}
	else
		ft_print2(start);
	ft_putstr_fd(ft_strsub(start->name, 1, ft_strlen(start->name) - 2), 0);
	ft_putstr_fd("\e[0m", 0);
	ft_putchar_fd(start->name[ft_strlen(start->name) - 1], 0);
}

void		calc_rows_cols(t_dlist *start)
{
	int		cols;
	int		rows;

	cols = get_max(ft_strlen(start->name), 1);
	if (!cols)
		return ;
	rows = g_term.argc / cols;
	if (g_term.argc % cols)
		rows++;
	if (rows > get_max(1, 3))
		return ;
	printing(start, rows, cols);
}

void		printing(t_dlist *start, int rows, int cols)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 1;
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
