/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punbr_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:10:52 by adstan            #+#    #+#             */
/*   Updated: 2017/12/12 18:00:51 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int		ft_tchar(char c, int fd)
{
	write(fd, &c, 1);
	return (0);
}

static void		specialcas(int fd)
{
	ft_tchar('-', fd);
	ft_tchar('2', fd);
	ft_tchar('1', fd);
	ft_tchar('4', fd);
	ft_tchar('7', fd);
	ft_tchar('4', fd);
	ft_tchar('8', fd);
	ft_tchar('3', fd);
	ft_tchar('6', fd);
	ft_tchar('4', fd);
	ft_tchar('8', fd);
}

static void		idk(int nb, int fd)
{
	if (!nb)
	{
		ft_tchar('0', fd);
		return ;
	}
	if (nb == -2147483648)
	{
		specialcas(fd);
		return ;
	}
}

void			ft_putnbr_fd(int nb, int fd)
{
	char	v[12];
	int		i;

	i = 0;
	if (!nb || nb == -2147483648)
	{
		idk(nb, fd);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_tchar('-', fd);
	}
	while (nb)
	{
		v[i++] = nb % 10;
		nb /= 10;
	}
	i--;
	while (i >= 0)
		ft_tchar(v[i--] + '0', fd);
}
