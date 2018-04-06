/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:22:15 by adstan            #+#    #+#             */
/*   Updated: 2018/03/26 16:54:26 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_signals(void)
{
	signal(SIGABRT, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGSTOP, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGQUIT, signal_handler);
}

void	suspend_signal(void)
{
	restore();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDIN_FILENO, TIOCSTI, "\x1A");
}

void	signal_handler(int signo)
{
	if (signo == SIGTSTP)
		suspend_signal();
	else if (signo == SIGSTOP || signo == SIGKILL || signo == SIGQUIT
			|| signo == SIGABRT || signo == SIGINT)
	{
		restore();
		exit(0);
	}
	else if (signo == SIGCONT)
	{
		init_termfuckingcap();
		init_signals();
		main_afis(g_term.start);
	}
}
