/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:40:37 by adstan            #+#    #+#             */
/*   Updated: 2018/03/29 17:48:24 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	restore(void)
{
	tcsetattr(0, TCSANOW, &g_term.oldterminal);
	tputs(tgetstr("te", NULL), 1, ft_printnbr);
	tputs(tgetstr("ve", NULL), 1, ft_printnbr);
}

int		return_j_last_nod(void)
{
	t_dlist *tmp;

	tmp = g_term.current;
	while (!tmp->last)
		tmp = tmp->next;
	return (tmp->j);
}

int		ft_printnbr(int nbr)
{
	return (write(STDERR_FILENO, &nbr, 1));
}

int		get_max(int len, int what)
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

void	ft_print2(t_dlist *start)
{
	start->ftype == 'b' ? ft_putstr_fd("\e[33m", 0) : (0);
	start->ftype == 'd' ? ft_putstr_fd("\e[36m", 0) : (0);
	start->ftype == 'r' ? ft_putstr_fd("\e[31m", 0) : (0);
	start->ftype == 'l' ? ft_putstr_fd("\e[35m", 0) : (0);
	start->ftype == 's' ? ft_putstr_fd("\e[32m", 0) : (0);
	start->ftype == 'c' ? ft_putstr_fd("\e[34m", 0) : (0);
	ft_putstr_fd("\e[49m", 0);
}
