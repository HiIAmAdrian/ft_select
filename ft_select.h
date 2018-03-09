/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:08:20 by adstan            #+#    #+#             */
/*   Updated: 2018/03/09 18:30:10 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <curses.h>
# include <signal.h>
# include <dirent.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <term.h>
# include "../libft/includes/libft.h"
# define ENTER_KEY 10
# define UP_KEY 4283163
# define DOWN_KEY 4348699
# define LEFT_KEY 4479771
# define RIGHT_KEY 4414235
# define SPACE_KEY 32
# define ESC_KEY 27
# define BKP_KEY 127
# define DEL_KEY 2117294875L

typedef struct		s_dlist 
{
	char			*name;
	int				last;
	int				selected;
	int				rows;
	int				i;
	int				j;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct		s_global
{
	int				argc;
	struct termios	terminal;
	struct termios	oldterminal;
	t_dlist			*current;
	t_dlist			**curraddr;
}					t_global;

t_global	g_term;
/*
**string_manipulation.c
*/

int		longest_string(t_dlist *start);
void	put_spaces(t_dlist *start);
int		double_length(char **str);

/*
** afis.c
*/

void	main_afis(t_dlist *list);
void	printing(t_dlist *start);
int     ft_printnbr(int nbr);
int		get_max(int len, int what);

/*
** restore.c
*/

void	up(void);
void	down(void);
int		take_actions(long c);
void	restore(void);
#endif

