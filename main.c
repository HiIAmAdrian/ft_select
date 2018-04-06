/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 19:59:49 by adstan            #+#    #+#             */
/*   Updated: 2018/03/29 17:46:09 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_dlist	*init_args(char **argv)
{
	int		i;
	t_dlist *start;
	t_dlist *list;

	i = 2;
	if (argv[1])
	{
		start = new_nod(argv[1]);
		list = start;
		if (double_length(argv) == 2)
			list->last = 1;
	}
	while (argv[i])
	{
		list->next = new_nod(argv[i]);
		list->next->prev = list;
		list = list->next;
		if (i == (double_length(argv) - 1))
			list->last = 1;
		i++;
	}
	list->next = start;
	start->prev = list;
	return (start);
}

t_dlist	*lstat_them(t_dlist *start)
{
	int			count;
	struct stat st;
	t_dlist		*list;

	list = start;
	count = 1;
	while (count)
	{
		if ((lstat(start->name, &st)) != -1)
		{
			(S_ISBLK(st.st_mode)) ? start->ftype = 'b' : (0);
			(S_ISFIFO(st.st_mode)) ? start->ftype = 'f' : (0);
			(S_ISCHR(st.st_mode)) ? start->ftype = 'c' : (0);
			(S_ISDIR(st.st_mode)) ? start->ftype = 'd' : (0);
			(S_ISSOCK(st.st_mode)) ? start->ftype = 's' : (0);
			(S_ISLNK(st.st_mode)) ? start->ftype = 'l' : (0);
			(S_ISREG(st.st_mode)) ? start->ftype = 'r' : (0);
		}
		else
			start->ftype = 'r';
		if (start->last)
			count = 0;
		start = start->next;
	}
	return (list);
}

void	verify_term(void)
{
	char	*term;
	int		ret;

	if (!(term = getenv("TERM")))
	{
		ft_putendl_fd("TERM VARIABLE NOT FOUND! Exiting...", 2);
		exit(0);
	}
	if (!(isatty(0)))
	{
		ft_putendl_fd("Not a terminal! Existing...", 2);
		exit(0);
	}
	if ((ret = tgetent(term, NULL)) <= 0)
	{
		if (ret == -1)
			ft_putendl_fd("Terminfo database could not be found! Exiting", 2);
		if (!ret)
			ft_putendl_fd("There is no such TERM in terminfo database!", 2);
		exit(0);
	}
	init_termfuckingcap();
}

void	init_termfuckingcap(void)
{
	tcgetattr(STDIN_FILENO, &g_term.oldterminal);
	tcgetattr(STDIN_FILENO, &g_term.terminal);
	g_term.terminal.c_lflag &= ~ICANON;
	g_term.terminal.c_lflag &= ~ECHO;
	g_term.terminal.c_cc[VMIN] = 0;
	g_term.terminal.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &g_term.terminal);
	tputs(tgetstr("ti", NULL), 1, ft_printnbr);
	tputs(tgetstr("vi", NULL), 1, ft_printnbr);
}

int		main(int argc, char **argv)
{
	t_dlist *args;
	t_dlist *start;

	g_term.argc = argc - 1;
	args = init_args(argv);
	args = lstat_them(args);
	start = args;
	verify_term();
	init_signals();
	put_spaces(args);
	start = args;
	g_term.current = start;
	g_term.curraddr = &start;
	g_term.start = start;
	main_afis(args);
}
