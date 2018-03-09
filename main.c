/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 19:59:49 by adstan            #+#    #+#             */
/*   Updated: 2018/03/08 16:19:42 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_dlist *new_nod(char *str)
{
	t_dlist *new;

	new = (t_dlist*)ft_memalloc(sizeof(t_dlist));
	if (!(new->name = ft_strdup(str)))
		ft_putendl_fd(M_ERROR, 2);
	new->prev = NULL;
	new->next = NULL;
	new->selected = 0;
	new->last = 0;
	return (new);
}

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

void	init_termfuckingcap(void)
{
	char	*term;
	int		ret;

	if (!(term = getenv("TERM")))
	{
		ft_putendl_fd("TERM VARIABLE NOT FOUND! Exiting...", 2);
		exit (0);
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
			ft_putendl_fd("There is no such entry as TERM in terminfo database! Exiting...", 2);
			exit(0);
	}
	tcgetattr(STDIN_FILENO, &g_term.oldterminal);
	tcgetattr(STDIN_FILENO, &g_term.terminal);
	g_term.terminal.c_lflag &= ~ICANON;
	g_term.terminal.c_lflag &= ~ECHO;
	g_term.terminal.c_cc[VMIN] = 0;
	g_term.terminal.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &g_term.terminal);
	tputs(tgetstr("ti",NULL), 1, ft_printnbr);
	tputs(tgetstr("vi",NULL), 1, ft_printnbr);
}	

int		main(int argc, char **argv, char **envp)
{
	t_dlist *args;
	t_dlist *start;
	int		count;

	count = 1;
	g_term.argc = argc - 1;
	start = args = init_args(argv);
	init_termfuckingcap();
	/*	while (count)
		{
		printf("%s %zu l:%d\n",start->name,ft_strlen(start->name),start->last);
		if (start->last == 1)
		count = 0;
		start = start->next;
		}
		printf("%d\n",longest_string(args));*/
	put_spaces(args);
	start = args;
	g_term.current = start;
	g_term.curraddr = &start;
	main_afis(args);
	/*	while (start->next != args)
		{
		printf("%s",start->name);
		start = start->next;
		}
		printf("%s",start->name);*/

}
