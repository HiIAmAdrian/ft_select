/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:32:40 by adstan            #+#    #+#             */
/*   Updated: 2018/03/02 21:06:09 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <stdlib.h>

int     ft_printnbr(int nbr)
{
	return (write(STDERR_FILENO, &nbr, 1));
}

int main(int argc, char **argv)
{
	struct winsize w,z;
	char			buf;

	tgetent(NULL, getenv("TERM"));
	tputs(tgetstr("ti",NULL), 1, ft_printnbr);
	tputs(tgetstr("vi",NULL), 1, ft_printnbr);
	ioctl(0, TIOCGWINSZ, &w);
	tputs(tgetstr("cl",NULL), 1, ft_printnbr);
//	write(1,"\033[2J\033[1;1H",14);
	while (read(0,&buf,1) && buf != '\n')
	{
		printf("lines: %d\n",w.ws_row);
		printf("cols:%d\n", w.ws_col);
	}
	tputs(tgetstr("ve", NULL), 1, ft_printnbr);
	tputs(tgetstr("te", NULL), 1, ft_printnbr);
	return 0;
}
